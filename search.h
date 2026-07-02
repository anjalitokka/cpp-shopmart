#ifndef SEARCH_H
#define SEARCH_H

#include <bits/stdc++.h>
#include "product.h"

using namespace std;

class Search
{
public:
    static void searchByName(const vector<Product>& products);

    static void searchByCategory(const vector<Product>& products);

    static void searchByPrice(const vector<Product>& products);

    static void sortByPriceLowToHigh(vector<Product>& products);

    static void sortByPriceHighToLow(vector<Product>& products);

    static void sortByRating(vector<Product>& products);

    static void sortByStock(vector<Product>& products);
};

#endif