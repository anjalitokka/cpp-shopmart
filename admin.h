#ifndef ADMIN_H
#define ADMIN_H

#include <bits/stdc++.h>
#include "user.h"
#include "product.h"

using namespace std;

class Admin : public User
{
public:

    // Product Management
    void dashboard(const vector<Product>& products);
    void addProduct(vector<Product>& products);
    void viewProducts(const vector<Product>& products);
    void updateProduct(vector<Product>& products);
    void deleteProduct(vector<Product>& products);
    void searchProduct(const vector<Product>& products);

    // Inventory
    void viewLowStockProducts(const vector<Product>& products);

    // Reports
    void viewSalesReport();
};

#endif