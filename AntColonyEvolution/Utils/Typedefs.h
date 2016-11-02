#pragma once
/*################
This file is for global typedefs.

DO NOT USE INT, USE THE STDINT TYPES
##################*/

#include <cstdint>

typedef int_fast32_t fint;
typedef uint_fast32_t fuint;

typedef int_fast16_t fshort;
typedef uint_fast16_t fushort;

typedef int_fast8_t fchar;
typedef uint_fast8_t fbyte;

enum TileType : uint8_t {
	Grass = 0,
	Food,
	Plant,
	Hazard,
	Danger,
	Debris,

	//Add new types above. Don't forget to add a tile class.
	//Special Types
	SIZE,
	Wall,
	Colony,
	EMPTY = 255
};

const fbyte TileProbabilities[TileType::SIZE] = {
	255, //Grass
	2, //Food
	16, //Plant
	16, //Hazard
	4, //Danger
	8 //Debris
};