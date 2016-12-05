#pragma once

// STL Includes
#include <array>
#include <list>
#include <memory>
#include <string>
#include <utility>

class Ant;

struct AntComparator
    : public std::binary_function<std::shared_ptr<Ant>, std::shared_ptr<Ant>,
                                  bool>
{
    bool operator()(const std::shared_ptr<Ant> &lhs,
                    const std::shared_ptr<Ant> &rhs) const;
};