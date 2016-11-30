//Project Includes
#include "../logging/logging.h"
#include "../config.h"

//Dep Includes
#include <array>
#include <vector>
#include <memory>
#include <iostream>
#include <iomanip>

//Declarations
class Ant;
class Simulation;

enum TileType {
    Colony = 255,
    Food = 127,
    Plant = 63,
    Road = 31,
    Grass = 15,
    Sand = 7,
    Trap = 3,
    Wall = 1,
    Null = 0
};

const int TileTypeProbs[5] = {
    1, //Food
    3, //Plant
    5, //Sand
    1, //Trap
    90 //Grass
};

struct Tile {
    private:
        unsigned char height;
    
    public:
        //Construction and data
        Tile(TileType t, unsigned char h) : type(t), height(h) { };
        const TileType type;
        unsigned char getHeight() { return height; }

        const std::vector<Ant*> getAnts();

        //Preparing Input
        virtual bool LayerInput(Ant&, Simulation&) { };

        //Generic Actions
        bool MoveTo(Ant&, Simulation&);
        bool MoveFrom(Ant&, Simulation&);
        bool Idle(Ant&, Simulation&);
        bool ReleaseSmallScentA(Ant&, Simulation&);
        bool ReleaseLargeScentA(Ant&, Simulation&);
        bool ReleaseSmallScentB(Ant&, Simulation&);
        bool ReleaseLargeScentB(Ant&, Simulation&);
        bool ReleaseSmallScentC(Ant&, Simulation&);
        bool ReleaseLargeScentC(Ant&, Simulation&);
        bool LowerHeight(Ant&, Simulation&);
        bool RaiseHeight(Ant&, Simulation&);

        //Actions that depend on Tile Type
        bool Harvest(Ant&, Simulation&) { };
        bool Give(Ant&, Simulation&) { };
        bool Take(Ant&, Simulation&) { };
        bool Work(Ant&, Simulation&) { };
        bool Build(Ant&, Simulation&) { };
};

struct Environment {
    private:
        std::array<std::shared_ptr<Tile>, ENV_SIZE> map;
    public:
        Environment(); //Generate random Environment
        Environment(unsigned int seed); //Generate Environment from seed.

        inline std::shared_ptr<Tile> get(const unsigned char &x, const unsigned char &y) {
            return map.at(x+y*ENV_SIDE);
        }

        void Print() { 
            for(int x = 0; x < ENV_SIDE; x++) {
                for(int y = 0; y < ENV_SIDE; y++) {
                    std::cout << std::setw(3) << (int)this->get(x,y)->type << ',';
                }
                std::cout << '\n';
            }

            std::cout << std::endl << std::endl << std::endl;

            for(int x = 0; x < ENV_SIDE; x++) {
                for(int y = 0; y < ENV_SIDE; y++) {
                    std::cout << std::setw(3) << (int)this->get(x,y)->getHeight() << ',';
                }
                std::cout << '\n';
            }

            std::cout << std::endl << std::endl << std::endl;
        };
};

struct ColonyTile : public Tile {
    public:
        ColonyTile(unsigned char h) : Tile(TileType::Colony, h) { };
};

struct FoodTile : public Tile {
    public:
        FoodTile(unsigned char h) : Tile(TileType::Food, h) { };
};

struct PlantTile : public Tile {
    public:
        PlantTile(unsigned char h) : Tile(TileType::Plant, h) { };
};

struct RoadTile : public Tile {
    public:
        RoadTile(unsigned char h) : Tile(TileType::Road, h) { };
};

struct GrassTile : public Tile {
    public:
        GrassTile(unsigned char h) : Tile(TileType::Grass, h) { };
};

struct SandTile : public Tile {
    public:
        SandTile(unsigned char h) : Tile(TileType::Sand, h) { };
};

struct TrapTile : public Tile {
    public:
        TrapTile(unsigned char h) : Tile(TileType::Trap, h) { };
};

struct WallTile : public Tile {
    public:
        WallTile(unsigned char h) : Tile(TileType::Wall, h) { };
};
