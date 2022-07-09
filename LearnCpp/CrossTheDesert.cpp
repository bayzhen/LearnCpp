#include "CrossTheDesert.h"
using namespace std;

struct Node
{
    int position;
    int supply;
    int cost;

    Node(int p, int s, int c): position(p), supply(s), cost(c)
    {
    }
};


int CrossTheDesert::GetNodeCost(const Node& n)
{
    vector<Node> nodes;
    int reach = position[n.position] + n.supply;
    if (reach >= D)
    {
        return n.cost;
    }
    for (int i = n.position + 1; i < position.size(); i++)
    {
        if (reach >= position[i])
        {
            auto node = Node(i, n.supply + supply[i] + position[n.position] - position[i], n.cost + 1);
            nodes.push_back(node);
        }
    }
    if (nodes.empty())
        return static_cast<int>(1e9);
    int minimum_cost = static_cast<int>(1e9);
    for (auto node : nodes)
    {
        int cost = GetNodeCost(node);
        if (cost < minimum_cost)
            minimum_cost = cost;
    }
    return minimum_cost;
}

int CrossTheDesert::DynamicProgramming()
{
    int dp[5][20];
    for (auto i : dp)
    {
        fill_n(i, 20, 10);
    }
    dp[0][4] = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (dp[i][j] < 10)
            {
                int reach = position[i] + j;
                for (size_t k = i+1; k < position.size(); k++)
                {
                    if(reach>=position[k]&&dp[i][j]+1<dp[k][j+supply[k]+position[k]-position[i]])
                    {
                        dp[k][j+supply[k]-position[k]+position[i]] = dp[i][j]+1;
                    }
                }
            }
        }
    }
    cout<<"横坐标是剩余补给，纵坐标是位置点。";
    for (int j = 0; j < 20; j++)
    {
        for (auto& i : dp)
        {
            cout << i[j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}


void CrossTheDesert::Solve()
{
    Node root(0, 4, 0);
    std::cout << "（递归）最少使用的站点数量： " << GetNodeCost(root) << std::endl;
    std::cout << "（动编）最少使用的站点数量： " << DynamicProgramming() << std::endl;
}
