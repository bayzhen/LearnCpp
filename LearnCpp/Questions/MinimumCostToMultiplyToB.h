#pragma once
#include<vector>

class MinimumCostToMultiplyToB
{
//     【题目描述】
// 小易给定你一个长度为n的正整数序列Ai，你每次可以使用1的代价将某个数加一或者减一，你希望用最少的代价使得所有数的乘积等于B，求最小代价（操作结束后每个数也必须是正整数）。
public:
    void Solve();
void BuildTheTable(std::vector<int> v, int p);
    void DynamicProgramming();
    void Official();
private:
    static constexpr int n = 5;
    static constexpr int B = 1000;
    const std::vector<int> A = {3,8,7,6,7,2,7,8};
    std::vector<std::vector<int>> dp;
};
