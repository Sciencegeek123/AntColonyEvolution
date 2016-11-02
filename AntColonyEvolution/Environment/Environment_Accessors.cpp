#include "Environment.h"
#include <random>
#include <vector>
#include <sstream>

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
				ColonyA = std::move(std::dynamic_pointer_cast<ColonyTile>(tiles[p]));
			} else if(!ColonyB) {
				ColonyB = std::move(std::dynamic_pointer_cast<ColonyTile>(tiles[p]));
			}
			else {
				//Error.
			}
			break;
		default:
			//Error.
			tiles[p] = std::move(std::shared_ptr<Tile>(new Tile(dMap[p], tMap[p])));
			break;
		}
	}
}

TileType Environment::getType(fuint x, fuint y) {
	return tiles[x + y * DEF_SIM_MAP_SIDE]->type;
}

uint8_t Environment::getDifficulty(fuint x, fuint y) {
	return tiles[x + y * DEF_SIM_MAP_SIDE]->difficulty;
}

template <class T> std::shared_ptr<T> Environment::getTile(fuint x, fuint y) {
	if (x >= DEF_SIM_MAP_SIDE || y >= DEF_SIM_MAP_SIDE) {
		return std::move(std::shared_ptr<Tile>(nullptr));
	}
	else {
		return std::move(std::dynamic_pointer_cast<T>(tiles[x + y * DEF_SIM_MAP_SIDE]));
	}
}


void Environment::ResetEnvironment() {
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
				ColonyA = std::move(std::dynamic_pointer_cast<ColonyTile>(tiles[p]));
			}
			else if (!ColonyB) {
				ColonyB = std::move(std::dynamic_pointer_cast<ColonyTile>(tiles[p]));
			}
			else {
				//Error.
			}
			break;
		default:
			//Error.
			tiles[p] = std::move(std::shared_ptr<Tile>(new Tile(dMap[p], tMap[p])));
			break;
		}
	}
}

std::string Environment::PrettyPrint() {
	std::stringstream sstr;
	for (fint x = 0; x < DEF_SIM_MAP_SIDE; x++) {
		for (fint y = 0; y < DEF_SIM_MAP_SIDE; y++) {
			sstr << getDifficulty(x, y);
		}
		sstr << "\t#\t";
		for (fint y = 0; y < DEF_SIM_MAP_SIDE; y++) {
			sstr << getType(x, y);
		}
		sstr << "\n";
	}
	return std::move(sstr.str());
}