#pragma once
#include "ACS.h"
#include <memory>
#include <array>

//Environments are not FSMs.
class Environment {
public:
	Environment(fuint seed);
	void ResetEnvironment();

	TileType getType(fuint x, fuint y);
	uint8_t getDifficulty(fuint x, fuint y);
	template <class T> T getTile(fuint y, fuint x);
	std::string PrettyPrint();

	//Later these classes will have more information & actions associated with them.
	class Tile { 
		friend Environment;
	public:
		fbyte difficulty;
		const TileType type = TileType::EMPTY;
		Tile(fbyte d, TileType t) : difficulty(d), type(t) { }
	};

	class ColonyTile : public Tile {
	public:
		const TileType type = TileType::Colony;
		ColonyTile(fbyte d, TileType t) : Tile(d, t) { }
	};

	class GrassTile : public Tile {
	public:
		const TileType type = TileType::Grass;
		GrassTile(fbyte d, TileType t) : Tile(d, t) { }
	};

	class FoodTile : public Tile {
	public:
		const TileType type = TileType::Food;
		FoodTile(fbyte d, TileType t) : Tile(d, t) { }
	};

	class PlantTile : public Tile {
	public:
		const TileType type = TileType::Plant;
		PlantTile(fbyte d, TileType t) : Tile(d, t) { }
	};

	class HazardTile : public Tile {
	public:
		const TileType type = TileType::Hazard;
		HazardTile(fbyte d, TileType t) : Tile(d, t) { }
	};

	class DangerTile : public Tile {
	public:
		const TileType type = TileType::Danger;
		DangerTile(fbyte d, TileType t) : Tile(d, t) { }
	};

	class DebrisTile : public Tile {
	public:
		const TileType type = TileType::Debris;
		DebrisTile(fbyte d, TileType t) : Tile(d, t) { }
	};

	class WallTile : public Tile {
	public:
		const TileType type = TileType::Wall;
		WallTile(fbyte d, TileType t) : Tile(d, t) { }
	};

private:
	std::array<fbyte,DEF_SIM_MAP_SIZE> dMap;
	std::array<TileType, DEF_SIM_MAP_SIZE> tMap;
	std::array<std::shared_ptr<Tile>, DEF_SIM_MAP_SIZE> tiles;
	std::shared_ptr<ColonyTile> ColonyA, ColonyB;
};