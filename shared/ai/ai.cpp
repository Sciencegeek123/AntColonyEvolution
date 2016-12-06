#include "ai/ai.h"

AI::AI(std::string input) { this->GeneticString = input; }

std::string AI::getTypeName() { return std::move("BASE"); }

std::shared_ptr<AI> AI::createRandom()
{
  return std::shared_ptr<AI>(new AI(utils::randomString(25)));
}

std::shared_ptr<AI> AI::createFrom(std::string &input)
{
  return std::shared_ptr<AI>(new AI(input));
}

std::string AI::GetGeneticString() { return this->GeneticString; }

OutputActions AI::get(ACSData input) { return OutputActions::NoOP; }

std::shared_ptr<AI> AI::reproduce(std::shared_ptr<std::set<std::shared_ptr<Ant>, AntComparator>> parents) { return createRandom(); }