#include "SimpleTransform.h"

#include <iostream>
#include <ostream>

bool SimpleTransform::Solve()
{
    bool begin = false;
    bool end = false;
    int num = -1;
    for (size_t i = 0; i < a.size(); i++)
    {
        int distance = a[i] - b[i];
        if(distance!=0&&!begin)
            begin = true;
        if(distance==0&&begin)
            end = true;
        if(end&&distance!=0)
        {
            std::cout<<"NO"<<std::endl;
            return false;
        }
    }
    std::cout<<"YES"<<std::endl;
    return true;
}
