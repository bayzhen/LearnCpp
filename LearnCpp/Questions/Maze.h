#pragma once
#include <list>
#include <vector>
class Maze
{
public:
    void Solve();
    std::vector<int> GetPortalPosition(int portal_num, std::vector<int> position);
    void BFS();
public:
    std::vector<std::vector<int>> maze = {{1, 0, -1, 1}, {-2, 0, -1, -3}, {2, 2, 0, 0}};
};
