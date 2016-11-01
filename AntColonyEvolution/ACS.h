#pragma once

/*

	This file contains all of the hard coded flags for the programs.
	THESE ARE NOT SETTINGS. THESE ARE FLAGS. SETTINGS NEED TO BE IN THE SETTINGS STRUCTURE.
	
*/

/*########################################################
MAIN PROGRAM FLAGS
#########################################################*/
#define ACS_SIMULATION //Code that actually simulates input
#define ACS_GENETICS //Code that generates new generations
#define ACS_GRAPHICS //Code that renders a simulation
#define ACS_NETWORK //Code that connects to a host for simulation data
#define ACS_DATABASE //Code that connects to a database for persistant storage
#define ACS_PRESENTATION //Code that connects to a host to display the results of the genetics

#define WINDOWS
//#define LINUX
//#define MAC

#include "Utils\Settings.h"
#include "Utils\Time.h"