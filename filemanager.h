#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <bits/stdc++.h>
#include "product.h"
using namespace std;

class FileManager
{
public:
    static void saveProducts(const vector<Product>& products);
    static void loadProducts(vector<Product>& products);
};

#endif