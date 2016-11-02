#pragma once
#include "ACS.h"
#include <memory>
#include <array>

//Environments are not FSMs.
class Environment {
public:
	Environment(fuint seed);
	void ResetEnvironment();

	TileType getType(fushort x, fushort y);
	uint8_t getDifficulty(fushort x, fushort y);
	template <class T> T getTile();

	//Later these classes will have more information & actions associated with them.
	class Tile { 
		friend Environment;
	private:
		fbyte difficulty;
		TileType type;
	public:
		Tile(fbyte d, TileType t) : difficulty(d), type(t) { }
	};

	class ColonyTile : public Tile {
	public:
		ColonyTile(fbyte d, TileType t) : Tile(d, t) { }
	};

	class GrassTile : public Tile {
	public:
		GrassTile(fbyte d, TileType t) : Tile(d, t) { }
	};

	class FoodTile : public Tile {
	public:
		FoodTile(fbyte d, TileType t) : Tile(d, t) { }
	};

	class PlantTile : public Tile {
	public:
		PlantTile(fbyte d, TileType t) : Tile(d, t) { }
	};

	class HazardTile : public Tile {
	public:
		HazardTile(fbyte d, TileType t) : Tile(d, t) { }
	};

	class DangerTile : public Tile {
	public:
		DangerTile(fbyte d, TileType t) : Tile(d, t) { }
	};

	class DebrisTile : public Tile {
	public:
		DebrisTile(fbyte d, TileType t) : Tile(d, t) { }
	};

	class WallTile : public Tile {
	public:
		WallTile(fbyte d, TileType t) : Tile(d, t) { }
	};

private:
	std::array<fbyte,DEF_SIM_MAP_SIZE> dMap;
	std::array<TileType, DEF_SIM_MAP_SIZE> tMap;
	std::array<std::shared_ptr<Tile>, DEF_SIM_MAP_SIZE> tiles;
	std::shared_ptr<ColonyTile> ColonyA, ColonyB;
};