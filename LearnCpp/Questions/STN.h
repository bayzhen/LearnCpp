#pragma once
#include <vector>


/* Sum of two to the NTH power */
class STN
{
public:
    void build_table(std::vector<int> i, int p);
    void solve();
    void set_n(int num);
private:
    int n;
    int length;
    std::vector<std::vector<int>> dp;
};
