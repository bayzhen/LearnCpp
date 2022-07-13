#include "STN.h"

#include <complex>
#include <iostream>
#include <vector>
void print_line(const std::vector<int> &line)
{
    for(auto i:line)
    {
        std::cout<<i;
    }
    std::cout << std::endl;
}

int get_up_limitation(const std::vector<int>& line, int p, int n)
{
    int temp = n;
    for (int i = p + 1; i < line.size(); i++)
    {
        temp -= line[i] * std::pow(2, i);
    }
    const int result = static_cast<int>(temp/std::pow(2,p));
    return result;
}

int get_sum(std::vector<int> line)
{
    int sum = 0;
    for (int i = 0; i < line.size(); i++)
    {
        sum += line[i] * std::pow(2, i);
    }
    return sum;
}

void STN::build_table(std::vector<int> line, int p)
{
    if (p < 0)
    {
        if (get_sum(line) == n)
        {
            dp.push_back(line);
        }
    }
    else
    {
        for (int i = 0; i <= get_up_limitation(line,p,n); i++)
        {
            line[p] = i;
            build_table(line, p - 1);
        }
    }
}

void STN::solve()
{
    length = 0;
    while (true)
    {
        if (std::pow(2, length) > n)
            break;
        length++;
    }
    std::vector<int> line;
    line.resize(length);
    build_table(line, length - 1);
    std::cout << dp.size() << std::endl;
}

void STN::set_n(int num)
{
    n = num;
}
