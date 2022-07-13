#include "MaxOrMinHeap.h"

#include <iostream>


void MaxOrMinHeap::solve()
{
    int num_set = 0;
    std::cin >> num_set;
    for (int i = 0; i < num_set; i++)
    {
        std::cin >> length;
        for (int j = 0; j < length; j++)
        {
            std::cin >> heap[j];
        }
        bool max_heap = true, min_heap = true;
        for (int k = 0; k < length / 2; k++)
        {
            if (heap[2 * k + 1] > heap[k] && 2 * k + 1 < length)
                max_heap = false;
            if (heap[2 * k + 2] > heap[k] && 2 * k + 2 < length)
                max_heap = false;
            if (heap[2 * k + 1] < heap[k] && 2 * k + 1 < length)
                min_heap = false;
            if (heap[2 * k + 2] < heap[k] && 2 * k + 2 < length)
                min_heap = false;
        }
        if (max_heap)
        {
            std::cout << "Max heap";
            continue;
        }
        if (min_heap)
        {
            std::cout << "Min heap";
            continue;
        }
        std::cout << "Not a heap";
    }
}
