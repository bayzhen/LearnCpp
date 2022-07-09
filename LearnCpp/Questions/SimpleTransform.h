#pragma once
#include <vector>

class SimpleTransform
{
public:
    bool Solve();
    std::vector<int> a{1, 1, 1, 1, 1};
    std::vector<int> b{1, 2, 1, 3, 1};
};
