#include "coupon.h"

float Coupon::applyCoupon(string code, float total)
{
    if(code == "WELCOME100")
    {
        cout << "\nCoupon Applied Successfully!\n";
        return max(0.0f, total - 100);
    }

    else if(code == "SAVE10")
    {
        cout << "\n10% Discount Applied!\n";
        return total * 0.90;
    }

    else if(code == "SHOP500")
    {
        if(total >= 5000)
        {
            cout << "\nRs.500 Discount Applied!\n";
            return total - 500;
        }
        else
        {
            cout << "\nSHOP500 requires minimum purchase of Rs.5000.\n";
        }
    }

    cout << "\nInvalid Coupon!\n";

    return total;
}