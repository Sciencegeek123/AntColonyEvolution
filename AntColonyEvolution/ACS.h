#pragma once
/*

	This file contains all of the hard coded flags for the programs.
	THESE ARE NOT SETTINGS. THESE ARE FLAGS. SETTINGS NEED TO BE IN THE SETTINGS STRUCTURE.
	
*/

/*########################################################
MAIN PROGRAM MODES
#########################################################*/
#define ACS_DEBUG
#define ACS_DEVELOPMENT
//#define ACS_HOST
//#define ACS_WORKER
//#define ACS_DEMO

/*########################################################
MAIN PROGRAM MODES
#########################################################*/
/* These are the primary code sets that can be used.
ACS_SIMULATION //Code that actually simulates input
ACS_GENETICS //Code that generates new generations
ACS_GRAPHICS //Code that renders a simulation
ACS_NETWORK //Code that connects to a host for simulation data
ACS_WEB //Code that displays information as a web page
ACS_DATABASE //Code that connects to a database for persistant storage
*/

#ifdef ACS_DEVELOPMENT
#define ACS_SIMULATION
#define ACS_GENETICS
#define ACS_GRAPHICS
#endif

#ifdef ACS_HOST
//TBD
#endif

#ifdef ACS_HOST
//TBD
#endif

#ifdef ACS_DEMO
//TBD
#endif

/*########################################################
OS FLAGS
#########################################################*/
#define WINDOWS
//#define LINUX
//#define MAC

/*########################################################
Basic Includes
#########################################################*/
#include <cstdint>
#include "Utils/Settings.h"
#include "Utils/Typedefs.h"
#include "Utils/Definitions.h"
