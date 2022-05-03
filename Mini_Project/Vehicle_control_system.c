/*
 ============================================================================
 Name        : Vehicle.c
 Author      : Abdelrahman Diaa_eldein sayd
 Version     :
 Copyright   : Your copyright notice
 Description : vehicle control system C_project
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define ON 1
#define OFF 0
#define bool 1 /* the bonus requirement if bool=1-->it will compile the lines of
                  engine temperature and if bool=0--> it will not be compiled
 */
struct vehicle_control   //structure that contains all the options of the car
{
	int Vehicle_Speed ,Room_Temperature,Engine_Temperature;
	int AC_State ,Engine_Controller_state;
}car={100,25,90,OFF,OFF}; //create an object and give its members an initial values

void main_menu (void);  // the first and main menu that the user will interface with
void Sensors_set_menu(void); // second menu that will appear if the user turn ON the engine
void Required_traffic_color(void); // function to set the color and takes actions according to the color
void Required_engine_temp(void); //function to set the engine temp and takes actions according to the temp
void Required_room_temp(void); //function to set the room temp and takes actions according to the temp
void display_vehicle_state(void); // function to display the states of the car

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	main_menu();
	return 0;
}
void main_menu (void)
{
	printf("Welcome :),please choose a letter (only small letters): \n");
	printf("a. Turn on the vehicle engine.\n");
	printf("b. Turn off the vehicle engine.\n");
	printf("c. Quit the system.\n\n");

	char input;
	scanf(" %c",&input);
	switch(input)
	{
	case 'c':
		printf(" Quit the system.\n\n");
		return;
		break;
	case 'b':
		printf(" Turn off the vehicle engine \n\n");
		main_menu();
		break;
	case 'a':
		printf(" Turn on the vehicle engine \n\n");
		Sensors_set_menu();
		break;
	default:
		printf("wrong input! \n\n");
		main_menu();
		break;
	}
}
void Sensors_set_menu(void)
{
	printf("please choose a character(only small character): \n");
	printf("a. Turn off the engine. \n");
	printf("b. Set the traffic light color. \n");
	printf("c. Set the room temperature (Temperature Sensor). \n");
#if(bool)
	printf("d. Set the engine temperature (Engine Temperature Sensor). \n\n");
#endif
	char input;
	scanf(" %c",&input);
	switch(input)
	{
	case 'a':
		main_menu();
		break;
	case 'b':
		Required_traffic_color();
		display_vehicle_state();
		Sensors_set_menu();
		break;
	case 'c':
		Required_room_temp();
		display_vehicle_state();
		Sensors_set_menu();
		break;
#if (bool)
	case 'd':
		Required_engine_temp();
		display_vehicle_state();
		Sensors_set_menu();
		break;
#endif
	default:
		printf("wrong input! \n");
		Sensors_set_menu();
		break;
	}
}
void Required_traffic_color(void)
{
	char traffic_color;
	printf("enter the traffic color:(only small characters) \n");
	scanf(" %c",&traffic_color);
	switch(traffic_color)
	{
	case 'g':
		car.Vehicle_Speed=100;
		break;
	case 'r':
		car.Vehicle_Speed=0;
		break;
	case 'o':
		car.Vehicle_Speed=30;
		break;
	default:
		printf("wrong input! \n");
		Required_traffic_color();
		break;
	}


}
void Required_engine_temp(void)
{
	printf("enter the required engine temperature: \n");
	scanf(" %d",&car.Engine_Temperature);
	if(car.Engine_Temperature<100)
	{
		car.Engine_Controller_state=ON;
		car.Engine_Temperature=125;
	}
	else if(car.Engine_Temperature>150)
	{
		car.Engine_Controller_state=ON;
		car.Engine_Temperature=125;
	}
	else
		car.Engine_Controller_state=OFF;
}
void Required_room_temp(void)
{
	printf("enter the required room temperature: \n");
	scanf(" %d",&car.Room_Temperature);
	if(car.Room_Temperature<10)
	{
		car.AC_State=ON;
		car.Room_Temperature=20;
	}
	else if(car.Room_Temperature>30)
	{
		car.AC_State=ON;
		car.Room_Temperature=20;
	}
	else
		car.AC_State=OFF;
}
void display_vehicle_state(void)
{
	if(car.Vehicle_Speed==30)
	{
		car.AC_State=ON;
		car.Room_Temperature=car.Room_Temperature *(5/4)+1;
#if(bool)
		car.Engine_Controller_state=ON;
		car.Engine_Temperature=car.Engine_Temperature *(5/4)+1;
#endif
	}
	printf("Engine is ON\n");
	if(car.AC_State)
		printf("AC is ON\n");
	else
		printf("AC is OFF\n");
	printf("Vehicle speed: %d Km/Hr \n",car.Vehicle_Speed);
	printf("Room Temp: %d C \n",car.Room_Temperature);
#if(bool)
	if(car.Engine_Controller_state)
		printf("Engine controller is ON\n");
	else
		printf("Engine controller is OFF\n");
	printf("Engine Temp: %d C \n\n",car.Engine_Temperature);
#endif
}




