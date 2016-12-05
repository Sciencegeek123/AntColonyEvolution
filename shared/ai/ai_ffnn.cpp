// Project Includes
#include "ai/ai_ffnn.h"

// STL Includes
#include <random>
#include <iostream>
#include <iomanip>
#include <cmath>

// Using
using namespace std;

/*
Each layer has 65 nodes. 64 of those nodes are regular, with the other being a constant.
Each layer has 65*64 modifiers.
Total size:
    * Input Layer
        * 64 Input nodes
            * With 64 weights each
        * 1 Constant node
            * With 64 weights
        * No thresholds, so this is just:
            * 65 * 64 = 4160
    * Output Layer
        * 64 Output nodes
        * 64 Triggers
    * Hidden Layer
        * 64 regular nodes
            * Trigger
            * 64 Weights
        * 1 Constant node
            * 64 weights
        * 64*65+64 = 4224
    * Total:
        * Input: 4160
        * Output: 64
        * 8x Hidden: 4224 * 8 = 33792
        Total: 38016 (Will use 38128 for safety, as I will pull extra values.

    * Note:
        * The triggers for the input node are used for the output node.
*/

shared_ptr<AI> FFNN_AI::createRandom()
{
    return shared_ptr<AI>(new FFNN_AI(utils::randomString(38128)));
}

inline float BtoF(byte &b)
{
    return ((float)b - 127.0f) / 128.0f;
}

struct ConstantNode
{
    std::array<float, 64> weights;
};

struct RegularNode
{
    float trigger;
    std::array<float, 64>
        weights;
};

class Layer
{
  private:
    std::array<RegularNode, 64> nodes;
    ConstantNode constant;

  public:
    void processWeights(std::unique_ptr<std::array<float, 64>> &in)
    {
        auto out = new std::array<float, 64>();
        auto &arr = *out;

        for (int j = 0; j < 64; j++)
        {
            arr[j] = 0;
        }

        for (int i = 0; i < 64; i++)
        {
            for (int j = 0; j < 64; j++)
            {
                arr[j] += nodes[i].weights[j] * (*in)[i];
            }
        }

        for (int j = 0; j < 64; j++)
        {
            arr[j] += constant.weights[j];
        }

        in.reset(out);
    };
    void processThresholds(std::unique_ptr<std::array<float, 64>> &in)
    {
        for (int i = 0; i < 64; i++)
        {
            if ((*in)[i] < nodes[i].trigger)
            {
                (*in)[i] = 0;
            }
        }
    };
    int populate(int start, byte *str)
    {
        for (int i = 0; i < 64; i++)
        {
            for (int j = 0; j < 64; j++)
            {
                nodes[i].weights[j] = BtoF(str[start++]);
            }
            nodes[i].trigger = BtoF(str[start++]);
        }
        for (int j = 0; j < 64; j++)
        {
            constant.weights[j] = BtoF(str[start++]);
        }
        return start;
    }
};

shared_ptr<AI>
FFNN_AI::createFrom(std::string &input)
{
    return shared_ptr<AI>(new FFNN_AI(input));
}

FFNN_AI::FFNN_AI(std::string input) : AI(input)
{
    int start = 26;
    layers = new Layer[9];
    for (int i = 0; i < 9; i++)
    {
        start = layers[i].populate(start, (byte *)input.data());
    }
}

OutputActions FFNN_AI::get(ACSData in)
{
    std::unique_ptr<std::array<float, 64>> data(new std::array<float, 64>);
    for (int i = 0; i < 64; i++)
    {
        (*data)[i] = BtoF((*in)[i]);
    }

    layers[0].processWeights(data);
    for (int i = 1; i < 9; i++)
    {
        layers[i].processThresholds(data);
        layers[i].processWeights(data);
    }
    layers[0].processWeights(data);

    float max_weight = 0;
    int max_index = 0;

    for (int i = 0; i < 64; i++)
    {
        if ((*data)[i] > max_weight)
        {
            max_weight = (*data)[i];
            max_index = i;
        }
    }

    cout << "* W: " << max_weight << endl;

    return (OutputActions)max_index;
}