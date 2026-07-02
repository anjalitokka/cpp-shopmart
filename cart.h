#ifndef CART_H
#define CART_H

#include <bits/stdc++.h>
#include "product.h"
using namespace std;

class Cart
{
private:
    vector<Product> cartItems;
    vector<int> quantity;

public:
    // Cart Operations
    void addToCart(Product p);
    void removeFromCart(int productId);
    void clearCart();

    // Display
    void viewCart() const;

    // Checkout
    float checkout(string username);

    // Utility
    bool isEmpty() const;
    int getItemCount() const;
    float getTotalPrice() const;
};

#endif