#pragma once
#include <iostream>
#include <ostream>
#include <random>
#include <vector>
#include <cmath>

#include "LearnCpp.h"
#include "LearnCpp.h"
#include "MinimumCostToMultiplyToB.h"

using namespace std;

inline void JumpOnPillars()
{
    vector<int> h = {1,8,2,3,4};
    int k=3;
    int cp = 0;
    int i= h.size()-1;
    bool super_power = true;
    while(i!=0)
    {
        vector<int> temp;
        for(int position = i-1;position>i-k&&position>=0;position--)
        {
            temp.insert(temp.begin(),h[position]);
        }
        bool exist_maximum = false;
        int maximum = 9999;
        int maximum_position = -1;
        for(int j=0;j<temp.size();j++)
        {
            if(temp[j]>h[i]&&temp[j]<maximum)
            {
                exist_maximum = true;
                maximum = temp[j];
                maximum_position = j;
            }
        }
        if(exist_maximum)
        {
            i = maximum_position+i-k+1;
        }
        else if(super_power==false)
        {
            cout<<"NO"<<endl;
            return;
        }else
        {
            super_power = false;
            int smallest_position = 0;
            for(size_t j=1;j<temp.size();j++)
            {
                if(temp[j]<temp[smallest_position])
                {
                    smallest_position = j;
                }
            }
            i = smallest_position+i-k+1;
        }
    }
    cout<<"YES"<<endl;
}
inline bool CircleCutting()
{
    vector<int> circle = {4,4,5,3};
    int sum = 0;
    for (auto i : circle)
    {
        sum += i;
    }
    if (sum % 2)
        return false;
    else
    {
        int left = 0, right = 0;
        int temp = 0;
        for (int i = left; i < right; i++)
        {
            temp += circle[i];
        }
        while (temp != sum / 2)
        {
            if (temp > sum / 2 && left < right)
            {
                left++;
            }
            else if (temp < sum / 2 && right < circle.size())
            {
                right++;
            }
            else
            {
                return false;
            }
            temp = 0;
            for (int i = left; i < right; i++)
            {
                temp += circle[i];
            }
        }
        return true;
    }
}

inline int EatGrape()
{
    vector<int> grapes = {1, 2, 3};
    sort(grapes.begin(), grapes.end());
    if (grapes[0] + grapes[1] > ceil(float(grapes[2]) / 2))
    {
        cout << (grapes[0] + grapes[1] + grapes[2]) / 3 + (grapes[0] + grapes[1] + grapes[2]) % 3 << endl;
    }
    else
    {
        cout << ceil(grapes[2] / 2);
    }
    return 0;
}

inline int S(int n)
{
    int result = n % 9;
    int temp = n / 9;
    while (temp > 0)
    {
        temp--;
        result = result * 10;
        result += 9;
    }
    return result;
}


inline int MinimumCostToMakeAProductB()
{
    int f[1005][105];
    int n, b;
    int a[1005];
    vector<int> v[100005];
    int num[100005];

    cin >> n >> b;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= b; i++)
    {
        for (int j = i; j <= b; j += i)
            v[j].push_back(i);
    }
    for (int i = 0; i < v[b].size(); i++)
        num[v[b][i]] = i;
    f[0][0] = 0;
    for (int i = 1; i < v[b].size(); i++)
        f[0][i] = 1e9;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < v[b].size(); j++)
        {
            f[i][j] = 1e9;
            for (int k = 0; k < v[v[b][j]].size(); k++)
            {
                f[i][j] = min(f[i][j], f[i - 1][num[v[v[b][j]][k]]] +
                              abs(a[i] - v[b][j] / v[v[b][j]][k]));
            }
        }
    }
    cout << f[n][v[b].size() - 1] << endl;
    return 0;
}


class TestClass
{
public:
    TestClass(int n)
    {
        number = n;
    }

    // TestClass(const TestClass& rhs)
    // {
    //     number = rhs.number;
    //     std::cout<<"1"<<std::endl;
    // }
    TestClass operator=(const TestClass& rhs)
    {
        number = rhs.number;
        return *this;
    }

    int number;
};

class Netease
{
public:
    void TestClassFunc()
    {
        TestClass a(1), b(2), c(3);
        a = b = c;
        std::cout << a.number << b.number << c.number << std::endl;
    }
};
