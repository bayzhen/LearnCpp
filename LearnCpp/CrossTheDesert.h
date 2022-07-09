#pragma once
#include<vector>
#include<iostream>

struct Node;

class CrossTheDesert
{
public:
    int GetNodeCost(const Node& node);
    int DynamicProgramming();
    void Solve();
private:
    int D = 10, W = 4;
    std::vector<int> position=std::vector<int>({0, 1, 4, 7, 10});
    std::vector<int> supply = std::vector<int>({4, 6, 3, 5, 0});
};
