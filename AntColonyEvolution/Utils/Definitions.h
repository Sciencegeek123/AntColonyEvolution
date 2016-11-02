#pragma once
/*###############
This file contains hard coded definitions.

Format:
	//Description
	#define DEF_[Scope]_[Name] [Value]
################*/

//The number of iterations the simulation should run
#define DEF_SIM_ITERATIONS 100000

//The size of the environment
#define DEF_SIM_MAP_SIDE 4096
#define DEF_SIM_MAP_SIZE (DEF_SIM_MAP_SIDE * DEF_SIM_MAP_SIDE)

//The default random seed. Uncomment to use the time.
#define DEF_GLOBAL_RANDOM_SEED 0x414e5453;

