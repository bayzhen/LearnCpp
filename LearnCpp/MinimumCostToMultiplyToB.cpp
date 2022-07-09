#include "MinimumCostToMultiplyToB.h"

#include <iostream>
#include<memory>

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

void PrintVector(vector<int>& v)
{
    for (auto e : v)
    {
        cout << e << "\t";
    }
    cout << endl;
}

void MinimumCostToMultiplyToB::Solve()
{
    cout << "DynamicProgramming: ";
    DynamicProgramming();
}

int Multiply(const vector<int>& v)
{
    int result = 1;
    for (auto i : v)
    {
        result *= i;
    }
    return result;
}

int GetCost(vector<int> a, vector<int> b)
{
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += abs(a[i] - b[i]);
    }
    return sum;
}

void MinimumCostToMultiplyToB::BuildTheTable(vector<int> v, int p)
{
    int r = 1;
    for (int i = 0; i < p; i++)
    {
        r *= v[i];
    }
    int upper_limitation = B / r;
    for (int i = 1; i <= upper_limitation; i++)
    {
        vector<int> temp(v);
        temp[p] = i;
        dp.push_back(temp);
        if (p == v.size() - 1)
            continue;
        BuildTheTable(temp, p + 1);
    }
}

void MinimumCostToMultiplyToB::DynamicProgramming()
{
    BuildTheTable(A, 0);
    int minimum_cost = 1000;
    for (auto i : dp)
    {
        if (Multiply(i) == B)
        {
            int cost = GetCost(i, A);
            if (cost < minimum_cost)
                minimum_cost = cost;
        }
    }
    cout << minimum_cost << endl;
}


void MinimumCostToMultiplyToB::Official()
{
    vector<vector<int>> v(B + 1, vector<int>());
    for (int i = 1; i <= B; i++)
    {
        for (int j = i; j <= B; j += i)
        {
            v[j].push_back(i);
        }
    }
    size_t m = v[B].size();
    auto num = vector<int>(B + 1, 0);
    for (int i = 0; i < m; i++)
    {
        num[v[B][i]] = i;
    }
    auto dp = vector<vector<int>>(n + 1, vector<int>(m, 0));
    for (int i = 1; i < m; i++)
    {
        dp[0][i] = static_cast<int>(1e9);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = static_cast<int>(1e9);
            for (int k = 0; k < v[v[B][j]].size(); k++)
            {
                cout << i << j << k << endl;
                dp[i][j] = min(dp[i][j], dp[i - 1][num[v[v[B][j]][k]]] + abs(A[i] - v[B][j] / v[v[B][j]][k]));
            }
        }
    }
    cout << dp[n][m - 1];
}
