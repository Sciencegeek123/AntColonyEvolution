//Project Includes
#include "../logging/logging.h"
#include "../config.h"

//Dep Includes
#include <array>
#include <vector>
#include <memory>

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

struct Tile {
    public:
        //Construction and data
        Tile(TileType t, unsigned char h) : type(t), height(h) { };
        const TileType type;
        const unsigned char height;

        const std::vector<Ant*> getAnts();

        //Preparing Input
        virtual bool LayerInput(Ant&, Simulation&) { };

        //Generic Actions
        bool MoveTo(Ant&, Simulation&);
        bool MoveFrom(Ant&, Simulation&);
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
        std::array<std::unique_ptr<Tile>, ENV_SIZE> map;
    public:
        Environment(); //Generate random Environment
        Environment(unsigned int seed); //Generate Environment from seed.

        inline Tile* get(const unsigned char &x, const unsigned char &y) {
            return map.at(x+y*ENV_SIDE).get();
        }

        void Print() { };
};

struct Colony : Tile {

};

struct Food : Tile {

};

struct Plant : Tile {

};

struct Road : Tile {

};

struct Grass : Tile {

};

struct Sand : Tile {

};

struct Trap : Tile {

};

struct Wall : Tile {
    
};
