//Project Includes
#include "./environment.h"

//Dep includes
#include "../deps/FastNoise/FastNoise.h"

//STL Includes
#include <Random>
#include <iostream>

using namespace std;

Environment::Environment() : map() {
    //For seeds (This should really be static but whatever.)
    std::random_device rd;

    //For heights
    FastNoise fn(rd());
    fn.SetNoiseType(FastNoise::NoiseType::Cellular);
    fn.SetFrequency(0.02f);
    fn.SetInterp(FastNoise::Interp::Quintic);
    fn.SetFractalType(FastNoise::FractalType::FBM);
    fn.SetFractalOctaves(5);
    fn.SetFractalLacunarity(2);
    fn.SetFractalGain(0.5);
    fn.SetCellularDistanceFunction(FastNoise::CellularDistanceFunction::Euclidean);
    fn.SetCellularReturnType(FastNoise::CellularReturnType::Distance2Add);

    //For types
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,99);

    for(int x = 0; x < ENV_SIDE; x++) {
        for(int y = 0; y < ENV_SIDE; y++) {
            int roll = distribution(generator);
            int height = fn.GetNoise(x,y) * 128 + 128;

            if(x == 128 && y == 128) {
                map.at(x+y*ENV_SIDE) = std::shared_ptr<Tile>(new ColonyTile(height));
            } else if((roll -= TileTypeProbs[0]) <= 0) {
                map.at(x+y*ENV_SIDE) = std::shared_ptr<Tile>(new FoodTile(height));
            } else if((roll -= TileTypeProbs[1]) <= 0) {
                map.at(x+y*ENV_SIDE) = std::shared_ptr<Tile>(new PlantTile(height));
            } else if((roll -= TileTypeProbs[2]) <= 0) {
                map.at(x+y*ENV_SIDE) = std::shared_ptr<Tile>(new SandTile(height));
            } else if((roll -= TileTypeProbs[3]) <= 0) {
                map.at(x+y*ENV_SIDE) = std::shared_ptr<Tile>(new TrapTile(height));
            } else if((roll -= TileTypeProbs[4]) <= 0) {
                map.at(x+y*ENV_SIDE) = std::shared_ptr<Tile>(new GrassTile(height));
            } else {
                map.at(x+y*ENV_SIDE) = std::shared_ptr<Tile>(new GrassTile(height));
            }
        }
    }
}