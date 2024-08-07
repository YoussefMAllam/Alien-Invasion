#pragma once
#include "gameconfig.h"
#include"AlienArmy.h"
#include"EarthArmy.h"
#include "UnitMaintenanceList.h"
class randgen {
private:
	int N;
	int ES;
	int ET;
	int EG;
	int EH;
	int AS;
	int AM;
	int AD;
	int prob;

	int min_earth_power;
	int max_earth_power;

	int min_earth_health;
	int max_earth_health;

	int min_earth_capacity;
	int max_earth_capacity;

	int min_alien_power;
	int max_alien_power;

	int min_alien_health;
	int max_alien_health;

	int min_alien_capacity;
	int max_alien_capacity;

public:
	randgen(gameconfig& config); //constructor

	ArmyUnit* Earthgenerator(int ID, int jt); //function to generate random earth units

	ArmyUnit* Aliengenerator(int ID, int jt); //function to generate random alien units
};