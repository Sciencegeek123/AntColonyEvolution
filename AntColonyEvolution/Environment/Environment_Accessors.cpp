#include "Environment.h"
#include <random>
#include <vector>

//Later Perlin Noise should be implemented.
//Simple randomness will be used for now;
Environment::Environment(fuint seed) {
	std::mt19937 generator(seed);

	std::normal_distribution<float_t> difficultyDistribution(16, 6);
	std::uniform_int_distribution<int> typeDistribution(0, 255);

	for (fuint p = 0; p < DEF_SIM_MAP_SIZE; p++) {

		dMap[p] = (fbyte)(difficultyDistribution(generator))  % 32;

		fbyte count = 0;
		tMap[p] = EMPTY;
		do {
			tMap[p] = (TileType)(typeDistribution(generator) % TileType::SIZE);
			if (TileProbabilities[tMap[p]] < typeDistribution(generator)) {
				tMap[p] = TileType::EMPTY;
				if (++count == 8) {
					tMap[p] = TileType::Grass;
				}
			}
		} while (tMap[p] == EMPTY);
	}

	//Hard coded colony locations, with grass surrounding.
	for (fuint x = 254; x < 258; x++) {
		for (fuint y = 254; y < 258; x++) {
			tMap[x + DEF_SIM_MAP_SIDE * y] = TileType::Grass;
			dMap[x + DEF_SIM_MAP_SIDE * y] = 8;

			tMap[(DEF_SIM_MAP_SIDE - x) + DEF_SIM_MAP_SIDE * (DEF_SIM_MAP_SIDE - y)] = TileType::Grass;
			dMap[(DEF_SIM_MAP_SIDE - x) + DEF_SIM_MAP_SIDE * (DEF_SIM_MAP_SIDE - y)] = 8;
		}
	}

	tMap[256 + DEF_SIM_MAP_SIDE * 256] = TileType::Colony;
	tMap[(DEF_SIM_MAP_SIDE - 256) + DEF_SIM_MAP_SIDE * (DEF_SIM_MAP_SIDE - 256)] = TileType::Colony;

	for (fuint p = 0; p < DEF_SIM_MAP_SIZE; p++) {
		switch (tMap[p])
		{
		case TileType::Grass:
			tiles[p] = std::move(std::shared_ptr<Tile>(new GrassTile(dMap[p], tMap[p])));
			break;
		case TileType::Food:
			tiles[p] = std::move(std::shared_ptr<Tile>(new FoodTile(dMap[p], tMap[p])));
			break;
		case TileType::Plant:
			tiles[p] = std::move(std::shared_ptr<Tile>(new PlantTile(dMap[p], tMap[p])));
			break;
		case TileType::Hazard:
			tiles[p] = std::move(std::shared_ptr<Tile>(new HazardTile(dMap[p], tMap[p])));
			break;
		case TileType::Danger:
			tiles[p] = std::move(std::shared_ptr<Tile>(new DangerTile(dMap[p], tMap[p])));
			break;
		case TileType::Debris:
			tiles[p] = std::move(std::shared_ptr<Tile>(new DebrisTile(dMap[p], tMap[p])));
			break;
		case TileType::Wall:
			tiles[p] = std::move(std::shared_ptr<Tile>(new WallTile(dMap[p], tMap[p])));
			break;
		case TileType::Colony:
			tiles[p] = std::move(std::shared_ptr<Tile>(new ColonyTile(dMap[p], tMap[p])));
			if (!ColonyA) {
				ColonyA = std::move(std::shared_ptr<ColonyTile>(*(std::shared_ptr<ColonyTile>*)(&tiles[p])));
			} else if(!ColonyB) {
				ColonyB = std::move(std::shared_ptr<ColonyTile>(*(std::shared_ptr<ColonyTile>*)(&tiles[p])));
			}
			else {
				//Error.
			}
			break;
		default:
			tiles[p] = std::move(std::shared_ptr<Tile>(new Tile(dMap[p], tMap[p])));
			break;
		}
	}
}

TileType Environment::getType(fushort x, fushort y) {

}

uint8_t Environment::getDifficulty(fushort x, fushort y) {
	
}

template <class T> T Environment::getTile() {

}


void Environment::ResetEnvironment() {

}