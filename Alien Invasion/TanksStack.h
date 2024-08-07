#pragma once
#include "ArrayStack.h"
#include"EarthTank.h"
//EarthTankStack class is a stack of EarthTank objects that inherits from ArrayStack class
class EarthTankStack
{
private:
	int count; //count of the number of tank units in the stack
	ArrayStack <EarthTank*> tankStack; //stack of EarthTank objects
public:
	EarthTankStack(); //constructor
	bool AddTank(EarthTank* tank); //AddTank function to add a tank to the stack 
	void removeTank(EarthTank*& tank); //removeTank function to remove a tank from the stack
	void print(); //print function to print the ID of the tank units in the stack
	int get_count(); //get_count function to return the count of the number of tank units
	void selecttank(EarthTank* &tank); //selecttank function to select the tank unit at the top of the stack
	bool isEmpty(); //isEmpty function to check if the stack is empty
	LinkedQueue<ArmyUnit*>* get_tanks(int n);
	LinkedQueue<EarthTank*>* get_hurt_tanks(); //Gets the tanks with less than 20% health
};
