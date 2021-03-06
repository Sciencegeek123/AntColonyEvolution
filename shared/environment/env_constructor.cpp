// Project Includes
#include "environment/environment.h"
#include "utils/utils.h"

// Dep includes
#include "deps/FastNoise/FastNoise.h"

// STL Includes
#include <iostream>
#include <random>
#include <climits>

#define ENV_DEBUG false

#if ENV_DEBUG
#define ENV_DEBUG_IF(x) x
#else
#define ENV_DEBUG_IF(x)
#endif

using namespace std;
Environment::Environment(unsigned int seed) : map()
{
  this->PopulateTiles(seed);
}

Environment::Environment() : map()
{
  this->PopulateTiles(utils::getRandomInt());
}

void Environment::PopulateTiles(int seed)
{
  mt19937 randomEngine(seed);
  uniform_int_distribution<int> randInt(INT_MIN, INT_MAX);
  uniform_int_distribution<int> rand4K(0, 4096);

  // For heights
  FastNoise fn_height(randInt(randomEngine));
  fn_height.SetNoiseType(FastNoise::NoiseType::GradientFractal);
  fn_height.SetFrequency(0.04f);
  fn_height.SetInterp(FastNoise::Interp::Quintic);
  fn_height.SetFractalType(FastNoise::FractalType::Billow);
  fn_height.SetFractalOctaves(8);
  fn_height.SetFractalLacunarity(2);
  fn_height.SetFractalGain(0.8);

  // For types
  FastNoise fn_type(randInt(randomEngine));
  fn_type.SetNoiseType(FastNoise::NoiseType::GradientFractal);
  fn_type.SetFrequency(0.12f);
  fn_type.SetInterp(FastNoise::Interp::Quintic);
  fn_type.SetFractalType(FastNoise::FractalType::FBM);
  fn_type.SetFractalOctaves(4);
  fn_type.SetFractalLacunarity(1);
  fn_type.SetFractalGain(1);
  ENV_DEBUG_IF(cdebug << endl;)

#if ENV_DEBUG
  float maxRandCont = 0;
  float maxNoiseCont = 0;
  float maxHeightCont = 0;
  float maxRawHeightCont = 0;
  float maxDistCont = 0;
  float minNoiseCont = 10000;
  float maxTotalCont = 0;

  int gCount = 0;
  int pCount = 0;
  int sCount = 0;
  int tCount = 0;
  int fCount = 0;
#endif

  for (int x = 0; x < ENV_SIDE; x++)
  {
    for (int y = 0; y < ENV_SIDE; y++)
    {

      colonyActiveScent[x + y * ENV_SIDE] = 0;
      colonyPassiveScent[x + y * ENV_SIDE] = 0;

      float distance = sqrt(pow((float)(x - 128) / 128.0f, 2) +
                            pow((float)(y - 128) / 128.0f, 2)) /
                       sqrt(2);

      float rawHeight = (fn_height.GetNoise(x, y) + 1.0f) * 1.2f;

      rawHeight =
          (tanh((distance * 1.5 + rawHeight * 0.25 - 0.6f) * 3.14159f) / 2.0f +
           0.5f) *
              rawHeight * 0.75 +
          distance * 0.25;

      unsigned char height;

      if (rawHeight * 255 > 255)
      {
        height = 255;
      }
      else if (rawHeight < 0)
      {
        height = 0;
      }
      else
      {
        height = rawHeight * 255;
      }

      ENV_DEBUG_IF(if (maxRawHeightCont < height) maxRawHeightCont = height;)

      if (x == ENV_SIDE / 2 && y == ENV_SIDE / 2)
      {
        this->colony = new ColonyTile(height, x + y * ENV_SIDE);
        map.at(x + y * ENV_SIDE) = this->colony;
        ENV_DEBUG_IF(cdebug << "C";)
      }
      else if (x == 0 || y == 0 || x == ENV_SIDE - 1 || y == ENV_SIDE - 1)
      {
        map.at(x + y * ENV_SIDE) = new WallTile(255, x + y * ENV_SIDE);
        ENV_DEBUG_IF(cdebug << "W");
      }
      else
      {
        float randCont = 0.4f * ((float)rand4K(randomEngine)) / 4096.0f;
        float heightCont = 0.3f * rawHeight;
        float noiseCont = 0.3f * (1.0 + fn_type.GetNoise(x, y));

#if ENV_DEBUG
        if (maxRandCont < randCont)
          maxRandCont = randCont;
        if (maxHeightCont < heightCont)
          maxHeightCont = heightCont;
        if (maxNoiseCont < noiseCont)
          noiseCont = noiseCont;
        if (maxDistCont < distance)
          maxDistCont = distance;
        if (minNoiseCont > noiseCont)
          minNoiseCont = noiseCont;
#endif

        float type = randCont + noiseCont + heightCont;

        type = (tanh((distance * 3.0f + type * 1.5f - 1.5f) * 3.14159f) / 2.0f +
                0.5f) *
               type;
        type *= 1000.0f;

        ENV_DEBUG_IF(if (maxTotalCont < type) maxTotalCont = type;)

        if ((type - TileTypeProbs[0]) <= 0)
        {
          this->map.at(x + y * ENV_SIDE) = new GrassTile(height, x + y * ENV_SIDE);
          ENV_DEBUG_IF({
            cdebug << "G";
            gCount++;
          })
        }
        else if ((type - TileTypeProbs[1]) <= 0)
        {
          this->map.at(x + y * ENV_SIDE) = new PlantTile(height, x + y * ENV_SIDE);
          ENV_DEBUG_IF({
            cdebug << "P";
            pCount++;
          })
        }
        else if ((type - TileTypeProbs[2]) <= 0)
        {
          this->map.at(x + y * ENV_SIDE) = new GrassTile(height, x + y * ENV_SIDE);
          ENV_DEBUG_IF({
            cdebug << "G";
            gCount++;
          })
        }
        else if ((type - TileTypeProbs[3]) <= 0)
        {
          this->map.at(x + y * ENV_SIDE) = new SandTile(height, x + y * ENV_SIDE);
          ENV_DEBUG_IF({
            cdebug << "S";
            sCount++;
          })
        }
        else if ((type - TileTypeProbs[4]) <= 0)
        {
          this->map.at(x + y * ENV_SIDE) = new TrapTile(height, x + y * ENV_SIDE);
          ENV_DEBUG_IF({
            cdebug << "T";
            tCount++;
          })
        }
        else if ((type - TileTypeProbs[5]) <= 0)
        {
          this->map.at(x + y * ENV_SIDE) = new FoodTile(height, x + y * ENV_SIDE);
          ENV_DEBUG_IF({
            cdebug << "F";
            fCount++;
          })
        }
        else
        {
          this->map.at(x + y * ENV_SIDE) = new GrassTile(height, x + y * ENV_SIDE);
          ENV_DEBUG_IF({
            cdebug << "G";
            gCount++;
          })
        }
      }
    }
    ENV_DEBUG_IF(cdebug << endl;)
  }
  ENV_DEBUG_IF(cdebug << endl;)

#if ENV_DEBUG
  cdebug << "MaxR: " << maxRandCont << endl;
  cdebug << "MaxN: " << maxNoiseCont << endl;
  cdebug << "MinN: " << minNoiseCont << endl;
  cdebug << "MaxD: " << maxDistCont << endl;
  cdebug << "MaxC: " << maxTotalCont << endl;
  cdebug << "MaxH: " << maxHeightCont << endl;
  cdebug << "MaxRH: " << maxRawHeightCont << endl;

  cdebug << endl;

  cdebug << "gCount: " << gCount << " @ " << (float)gCount * 100 / (float)ENV_SIZE
       << endl;
  cdebug << "pCount: " << pCount << " @ " << (float)pCount * 100 / (float)ENV_SIZE
       << endl;
  cdebug << "sCount: " << sCount << " @ " << (float)sCount * 100 / (float)ENV_SIZE
       << endl;
  cdebug << "tCount: " << tCount << " @ " << (float)tCount * 100 / (float)ENV_SIZE
       << endl;
  cdebug << "fCount: " << fCount << " @ " << (float)fCount * 100 / (float)ENV_SIZE
       << endl;
  cdebug << endl;
#endif
}
