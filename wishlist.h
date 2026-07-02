#ifndef WISHLIST_H
#define WISHLIST_H

#include <bits/stdc++.h>
#include "product.h"

using namespace std;

class Wishlist
{
private:
    vector<Product> wishlistItems;

public:
    void addToWishlist(Product p);
    void removeFromWishlist(int productId);
    void viewWishlist() const;
    void moveToCart(int productId, class Cart &cart);
    bool isEmpty() const;
};

#endif