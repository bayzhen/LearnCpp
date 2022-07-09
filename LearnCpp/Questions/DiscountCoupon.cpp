#include "DiscountCoupon.h"

#include <iostream>
#include <ostream>

void DiscountCoupon::solve() const
{
    int sum = 0;
    for(const auto price: prices)
    {
        int best_coupon = 0;
        for(const auto coupon: coupons)
        {
            if(coupon<=price)
                best_coupon = coupon;
        }
        sum+=price-best_coupon;
    }
    std::cout<<sum<<std::endl;
}
