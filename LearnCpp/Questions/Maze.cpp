#include "Maze.h"

#include <iostream>
using namespace std;

void Print2DVector(vector<vector<bool>> v)
{
    for(auto a:v)
    {
        for(auto b: a)
        {
            cout<<b<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Maze::Solve()
{
    BFS();
}

vector<int> Maze::GetPortalPosition(int portal_num, vector<int> position)
{
    vector<vector<int>> collector;
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[0].size(); j++)
        {
            if (maze[i][j] == portal_num)
            {
                collector.push_back(vector<int>{i, j});
            }
        }
    }
    for (auto p : collector)
    {
        if (p[0] != position[0] || p[1] != position[1])
        {
            vector<int> temp(p);
            return temp;
        }
    }
    cout << "Portal not find";
    return {-1, -1};
}


void Maze::BFS()
{
    vector<int> current_position = {1, 0};
    vector<vector<bool>> record;
    for (int i = 0; i < 3; i++)
    {
        vector<bool> temp;
        for (int j = 0; j < 4; j++)
        {
            temp.push_back(false);
        }
        record.push_back(temp);
    }
    list<vector<int>> edge;
    int count = 0;
    list<vector<int>> temp = {current_position};
    while (!(edge.empty() && temp.empty()))
    {
        for (auto i : temp)
        {
            edge.push_back(i);
        }
        temp.clear();
        count++;
        while (!edge.empty())
        {
            current_position = edge.front();
            if (maze[current_position[0]][current_position[1]] == -3)
            {
                cout<<count<<endl;
                return;
            }
            edge.pop_front();
            record[current_position[0]][current_position[1]] = true;
            Print2DVector(record);
            if (maze[current_position[0]][current_position[1]] == 1 || maze[current_position[0]][current_position[1]] ==
                2)
            {
                auto portal_position = GetPortalPosition(maze[current_position[0]][current_position[1]],
                                                         current_position);
                if (!record[portal_position[0]][portal_position[1]])
                    temp.push_back(portal_position);
            }
            vector<int> up = {current_position[0] - 1, current_position[1]};
            vector<int> down = {current_position[0] + 1, current_position[1]};
            vector<int> left = {current_position[0], current_position[1] - 1};
            vector<int> right = {current_position[0], current_position[1] + 1};
            if (up[0] >= 0 && up[0] < 3 && up[1] >= 0 && up[1] < 4)
                temp.push_back(up);
            if (down[0] >= 0 && down[0] < 3 && down[1] >= 0 && down[1] < 4)
                temp.push_back(down);
            if (left[0] >= 0 && left[0] < 3 && left[1] >= 0 && left[1] < 4)
                temp.push_back(left);
            if (right[0] >= 0 && right[0] < 3 && right[1] >= 0 && right[1] < 4)
                temp.push_back(right);
        }
    }
}
