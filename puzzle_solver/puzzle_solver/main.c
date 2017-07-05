#define F_CPU 14745600
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd.h"
#include "puzzle_solver_statechart_model\src-gen\Puzzle_solver.c"
#include "firebird.c"
#define m 3
#define n 4
#define d1_size 12
#define d2_size 24
#define max_numbers_in_d2 4

struct pick_n_drop		//structure for storing steps in the form of node numbers from where to pick and where to drop
{
	int pick_cell,drop_cell;
};
typedef struct pick_n_drop pick_n_drop;				//typedef the above structure
pick_n_drop temp_steps[d1_size];					//declare array of structure created above to store a number of steps
const int initial_pick_length[12]={4,4,4,4,4,4,6,6,6,8,8,8};			//lookup table for initial pick length of number
const int pick_length[12]={4,3,2,3,2,1,3,2,1,4,3,2};					//lookup table for all pick lengths except initial of number
const int drop_length[24]={3,4,5,6,2,3,4,5,1,2,3,4,1,2,3,4,2,3,4,5,3,4,5,6};	//lookup table for drop length of number
int	node_index=0;		//node index to store which node number of the node sequence is visited
int node_sequence[25][3];	//array to store node sequence, each row stores node x coordinate, node y coordinate and number to pick (if it is pick node)
pick_n_drop steps[d1_size];				//store steps for picking and dropping
const int initial_pick_node_x[d1_size]={1,1,2,1,1,2,1,1,2,1,1,2};		//lookup table for converting cell number to node x coordinate for initial pick
const int initial_pick_node_y[d1_size]={0,0,0,1,1,1,2,2,2,3,3,3};		//lookup table for converting cell number to node y coordinate for initial pick
const int pick_node_x[d1_size]={1,2,3,1,2,3,1,2,3,1,2,3};				//lookup table for converting cell number to node x coordinates for all pick except initial
const int pick_node_y[d1_size]={1,1,1,2,2,2,2,2,2,3,3,3};				//lookup table for converting cell number to node y coordinates for all pick except initial
const int drop_node_x[d2_size]={4,5,6,7,4,5,6,7,4,5,6,7,4,5,6,7,4,5,6,7,4,5,6,7};	//lookup table for converting cell number to node x coordinates for all drop
const int drop_node_y[d2_size]={0,0,0,0,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,4,4,4,4};	//lookup table for converting cell number to node y coordinates for all drop
int l=150;
int get_length(pick_n_drop *steps,int step)				//function to get path length of a particular solution
{

	int i=0;
	int length=0;												//declare and initialize length
	length=initial_pick_length[steps[0].pick_cell];				//add initial pick length
	length+= 2*drop_length[steps[0].drop_cell];					//add initial drop length (both sides)

	for(i=1;i<(step-1);i++)				//to add lengths for all steps except the first and last step
	{
		length+= 2*pick_length[steps[i].pick_cell];			//add pick length of ith step
		length+= 2*drop_length[steps[i].drop_cell];			//add drop length of ith step
	}
	length+= 2*pick_length[steps[step-1].pick_cell];		//add pick length of last step
	length+=drop_length[steps[step-1].drop_cell];			//add drop length of last step
	length+= 2*step-1;										//add length for segment connecting d1 and d2
	return length;											//return length
}

void init_sol(pick_n_drop *steps)		
{
	int i=0;
	for(i=0;i<d1_size;i++)		//initialize the solution steps by assigning -1
	{
		steps[i].pick_cell=-1;			//assign -1 to pick of ith step
		steps[i].drop_cell=-1;			//assign -1 to drop of ith step
	}
}

bool is_solved(int d2[4][2],int numbers_to_solve)			//checks whether it is solved or not
{
	int i=0;
	for(i=0;i<numbers_to_solve;i++)						
	if(d2[i][1] != 0)					//if any of the number is not solved in d2 return false
	return false;
	return true;						// if all the numbers are solved, return true
}
void copy_sol(pick_n_drop *steps,int step)
{
	int i=0;
	init_sol(steps);			//initialize the solution
	for(i=0;i<step;i++)				//copy all the steps from temporary solution to permanent step
	{
		steps[i].pick_cell=temp_steps[i].pick_cell;
		steps[i].drop_cell=temp_steps[i].drop_cell;
	}
}
bool solve(int d1[d1_size],int d2[4][2],pick_n_drop *steps,int x1,int numbers_to_solve,int step)		
{
	int i,k,temp;
	if(is_solved(d2,numbers_to_solve))			//checks if puzzle is solved. If it is solved then
	{
		temp=get_length(temp_steps,step);			//get length of the solution
		if(temp <l)									// and compare with the minimum length got in previous solutions. if this length is less than minimum then
		{
			l=temp;									//store this length as minimum length
			copy_sol(steps,step);					//copy this solution to the permanent steps

		}
		return true;								//return true
	}
	
	//if it is not solved then 
	for(i=x1;i<d1_size;i++)							//iterate through all numbers in d1
	{
		for(k=0;k<numbers_to_solve;k++)				//iterate through all numbers in d2				
		{
			if(d2[k][1] >= d1[i])					//if number in d2 is greater than or equal to the number in d1 then
			{
				temp_steps[step].pick_cell=i;		//drop the number in d2
				temp_steps[step].drop_cell=d2[k][0];
				d2[k][1]-=d1[i];
				++step;								
				solve(d1,d2,steps,i+1,numbers_to_solve,step);		//solve the remaining problem
				--step;												//backtrack (put the number back from d2 to d1)
				temp_steps[step].pick_cell=-1;
				temp_steps[step].drop_cell=-1;
				d2[k][1]+=d1[i];
			}
		}
	}
	return false;								//return false
}

void swap(pick_n_drop *steps,int i,int j)					//swap two steps
{
	int temp;
	temp=steps[i].pick_cell;								//swap pick cell values at ith and jth step
	steps[i].pick_cell=steps[j].pick_cell;
	steps[j].pick_cell=temp;
	temp=steps[i].drop_cell;								//swap drop cell values at ith and jth step		
	steps[i].drop_cell=steps[j].drop_cell;
	steps[j].drop_cell=temp;
}
void optimize_sequence(pick_n_drop *steps)
{
	int i=0;
	while(steps[i+1].pick_cell != -1)					//until all steps are checked
	{
		if(drop_length[steps[i].drop_cell] > drop_length[steps[i+1].drop_cell])		//if ith step drop length is greater than (i+1)th step drop length
		{
			swap(steps,i,i+1);										//swap the steps
		}
		i++;														//select next step
	}
}
int get_number_of_problems(int d2[4][2])
{
	int i=0;
	while(d2[i][0]!=-1 && i!= 4)					//until all numbers to solve are not counted or counter is not 4
	i++;											//increment the counter
	return i;										//return number of problems
}

void update_sensor_values()
{
	bool x,y,z,u,v,w;
	p.ifaceInput.left_sensor=ADC_Conversion(3);				//read left white line sensor value
	p.ifaceInput.center_sensor=ADC_Conversion(2);			//read center white line sensor value
	p.ifaceInput.right_sensor=ADC_Conversion(1);			//read right white line sensor value
	x=p.ifaceInput.left_sensor>16;							//flag for left sensor value is greater than 16 (left on line)
	y=p.ifaceInput.center_sensor>16;						//flag for center sensor value is greater than 16 (left on line)
	z=p.ifaceInput.right_sensor>16;							//flag for right sensor value is greater than 16 (left on line)
	u=p.ifaceInput.left_sensor>116;							//flag for left sensor value is greater than 116 (left on node)
	v=p.ifaceInput.center_sensor>105;						//flag for center sensor value is greater than 105 (left on line)
	w=p.ifaceInput.right_sensor>106;						//flag for right sensor value is greater than 106 (left on line)
	p.ifaceInput.isnode = ((x&y)||(y&z)||(z&x)||u||v||w);	//if any sensor detects node or two sensors detect black then set this flag
		if(p.ifaceInput.left_sensed_line==false)			//if left sensed line flag is false
	{
		p.ifaceInput.left_sensed_line=x;					//assign x value to this flag
	}
	if(p.ifaceInput.right_sensed_line==false)				//if left sensed line flag is false			
	{
		p.ifaceInput.right_sensed_line=z;					//assign y value to this flag
	}	
	if(p.ifaceInput.center_sensed_line==false)				//if left sensed line flag is false
	{
		p.ifaceInput.center_sensed_line=y;					//assign y value to this flag
	}
		
	
	
}
ISR(TIMER1_COMPA_vect)
{
	update_sensor_values();					//updates sensor value every 10 ms in isr
}

void generate_node_sequence(int node_sequence[25][3],pick_n_drop *steps,int d1[d1_size])		//generate node sequence from steps
{
	int i=2,j=1;
	node_sequence[0][0]=initial_pick_node_x[steps[0].pick_cell];			//get first node's x coordinate
	node_sequence[0][1]=initial_pick_node_y[steps[0].pick_cell];			//get first node's y coordinate
	node_sequence[0][2]=d1[steps[0].pick_cell];								//get first node's number to pick
	node_sequence[1][0]=drop_node_x[steps[0].drop_cell];					//get second node's x coordinate
	node_sequence[1][1]=drop_node_y[steps[0].drop_cell];					//get second node's y coordinate
	node_sequence[1][2]=0;													//put 0 in number to pick as it is drop node
	while(steps[j].pick_cell != -1 && j!=d1_size)							//until all steps are done
	{
		node_sequence[i][0]=pick_node_x[steps[j].pick_cell];				//get ith node's x coordinate
		node_sequence[i][1]=pick_node_y[steps[j].pick_cell];				//get ith node's y coordinate 
		node_sequence[i][2]=d1[steps[j].pick_cell];							//get ith node's number to pick 
		node_sequence[i+1][0]=drop_node_x[steps[j].drop_cell];				//get (i+1)th node's x coordinate
		node_sequence[i+1][1]=drop_node_y[steps[j].drop_cell];				//get (i+1)th node's y coordinate
		node_sequence[i+1][2]=0;											//put 0 in number to pick as it is drop node
		j++;																//increment step by 1
		i+=2;																//increment node index by 2
	}
	node_sequence[i][0]=-1;													//set flags (-1) at last
	node_sequence[i][1]=-1;
	node_sequence[i][2]=-1;

}

/* function to move forward */
void puzzle_solverIfaceInput_forward(const Puzzle_solver* handle)
{	
	forward();			//move bot forward
}


/* function to move right */
void puzzle_solverIfaceInput_right(const Puzzle_solver* handle)
{	
	right();		//rotate bot right by rotating wheels in opposite direction
}


/* function to move left */
void puzzle_solverIfaceInput_left(const Puzzle_solver* handle)
{
	left();			//rotate bot left by rotating wheels in opposite direction
}
void puzzle_solverIfaceInput_soft_right(const Puzzle_solver* handle)
{
	soft_right();				//soft right turn the bot by stopping one wheel
}


/* function to move left */
void puzzle_solverIfaceInput_soft_left(const Puzzle_solver* handle)
{
	soft_left();				//soft left turn the bot by stopping one wheel
}

void puzzle_solverIfaceInput_velocity(const Puzzle_solver* handle, const sc_integer left_motor, const sc_integer right_motor)
{
	velocity(left_motor,right_motor);			//give velocity to left and right motor
}
void puzzle_solverIfaceInput_forward_mm(const Puzzle_solver* handle, const sc_integer distance)
{
	forward_mm(distance);			//go forward "distance" mm
}

void puzzle_solverIfaceInput_delayms(const Puzzle_solver* handle, const sc_integer time)
{
	int t=time;				//initialize a variable for storing time
	while(t--)				//loop until the time is elapsed
	_delay_ms(1);
}

void puzzle_solverIfaceInput_right_degrees(const Puzzle_solver* handle, const sc_integer angle)
{
	right_degrees(angle);		//rotate left "right" degrees
}
void puzzle_solverIfaceInput_left_degrees(const Puzzle_solver* handle, const sc_integer angle)
{
	left_degrees(angle);	//rotate left "angle" degrees
}

void puzzle_solverIfaceInput_get_target(const Puzzle_solver* handle)
{
	p.ifaceInput.x=node_sequence[node_index][0];		//give x coordinate
	p.ifaceInput.y=node_sequence[node_index][1];		//give y coordinate
	p.ifaceInput.num=node_sequence[node_index][2];	//give corresponding number (0 if it is a drop node)
	node_index++;									//increment the counter
}
void puzzle_solverIfaceInput_break(const Puzzle_solver* handle, const sc_integer intensity)
{
	stop();				//stop
	velocity(intensity,intensity);		//give intensity of break
	_delay_ms(100);					//100ms delay
}
void puzzle_solverIfaceInput_lcd_print(const Puzzle_solver* handle, const sc_integer row,const sc_integer column,const sc_integer value,const sc_integer digits)
{
	lcd_print(row,column,value,digits);		//lcd print
}
void puzzle_solverIfaceInput_reset_count(const Puzzle_solver* handle)
{
	ShaftCountLeft=0;		//reset left encoder count
}

void puzzle_solverIfaceInput_buzzer_on(const Puzzle_solver* handle)
{
	buzzer_on();	//on buzzer
}

void puzzle_solverIfaceInput_buzzer_off(const Puzzle_solver* handle)
{
	buzzer_off();		//off buzzer
}

int main()
{
	init_devices();				//initialize the devices
	int d1[d1_size]={0,5,4,2,9,8,3,7,6,1,2,1};		//d1 grid numbers
	int d2[4][2]={{10,15},{12,11},{23,10},{-1,-1}};	//d2 grid numbers and their position
	pick_n_drop steps[d1_size];				//steps array declaration
	int numbers_to_solve=get_number_of_problems(d2);	//get how many numbers to solve for
	init_sol(steps);									//clear the steps by putting -1 in every value
	lcd_string("solving");							//print solving
	solve(d1,d2,steps,0,numbers_to_solve,0);				//solving the puzzle
	lcd_wr_command(1);								//clear lcd
	lcd_string("solved");							//print solved
	optimize_sequence(steps);						//optimize the sequence by putting step with farthest number in d2 at last
	generate_node_sequence(node_sequence,steps,d1);	//generate sequence of nodes from steps
	_delay_ms(2000);							//2 second delay
	lcd_wr_command(1);							//clear lcd
	puzzle_solver_init(&p);	//initialize the state machine
	puzzle_solver_enter(&p); //enter the state machine

	while(1)
	{		
		p.ifaceInput.distance=ShaftCountLeft;	//read shaft count of left wheel
		puzzle_solver_runCycle(&p);				//execute a run cycle of state machine
	}
	
}
