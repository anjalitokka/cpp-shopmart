#include "admin.h"

// Add Product
void Admin::dashboard(const vector<Product>& products)
{
    int totalProducts = products.size();

    int lowStock = 0;

    for(const auto &p : products)
    {
        if(p.getStock() <= 5)
            lowStock++;
    }

    ifstream userFile("users.txt");

    int totalUsers = 0;
    string line;

    while(getline(userFile,line))
        totalUsers++;

    userFile.close();

    ifstream orderFile("orders.txt");

    int totalOrders = 0;

    while(getline(orderFile,line))
    {
        if(line.find("Order ID") != string::npos)
            totalOrders++;
    }

    orderFile.close();

    cout << "\n";
    cout << "=================================================\n";
    cout << "               ADMIN DASHBOARD\n";
    cout << "=================================================\n";

    cout << " Total Products     : " << totalProducts << endl;
    cout << " Registered Users   : " << totalUsers << endl;
    cout << " Orders Placed      : " << totalOrders << endl;
    cout << " Low Stock Products : " << lowStock << endl;

    cout << "=================================================\n";
}
void Admin::addProduct(vector<Product> &products)
{
    int id, stock;
    string name, category;
    float price, rating;
    int reviews;

    cout << "\n========== ADD PRODUCT ==========\n";

    cout << "Product ID      : ";
    cin >> id;

    cin.ignore();

    cout << "Product Name    : ";
    getline(cin, name);

    cout << "Category        : ";
    getline(cin, category);

    cout << "Price           : ";
    cin >> price;

    cout << "Stock           : ";
    cin >> stock;

    cout << "Rating (0-5)    : ";
    cin >> rating;

    cout << "Reviews         : ";
    cin >> reviews;

    Product p(id, name, category, price, stock, rating, reviews);

    products.push_back(p);

    cout << "\nProduct Added Successfully!\n";
}

// View Products
void Admin::viewProducts(const vector<Product> &products)
{
    if (products.empty())
    {
        cout << "\nNo Products Available.\n";
        return;
    }

    cout << "\n========== PRODUCT LIST ==========\n\n";

    for (const auto &p : products)
        p.displayProduct();
}

// Search Product
void Admin::searchProduct(const vector<Product> &products)
{
    string search;

    cin.ignore();

    cout << "\nEnter Product Name : ";
    getline(cin, search);

    bool found = false;

    for (const auto &p : products)
    {
        if (p.getName() == search)
        {
            p.displayProduct();
            found = true;
        }
    }

    if (!found)
        cout << "\nProduct Not Found.\n";
}

// Update Product
void Admin::updateProduct(vector<Product> &products)
{
    int id;

    cout << "\nEnter Product ID : ";
    cin >> id;

    for (auto &p : products)
    {
        if (p.getId() == id)
        {
            float price;
            int stock;

            cout << "New Price : ";
            cin >> price;

            cout << "New Stock : ";
            cin >> stock;

            p.setPrice(price);
            p.setStock(stock);

            cout << "\nProduct Updated Successfully!\n";
            return;
        }
    }

    cout << "\nProduct Not Found!\n";
}

// Delete Product
void Admin::deleteProduct(vector<Product> &products)
{
    int id;

    cout << "\nEnter Product ID : ";
    cin >> id;

    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].getId() == id)
        {
            products.erase(products.begin() + i);

            cout << "\nProduct Deleted Successfully!\n";
            return;
        }
    }

    cout << "\nProduct Not Found!\n";
}

// Low Stock Report
void Admin::viewLowStockProducts(const vector<Product> &products)
{
    cout << "\n========== LOW STOCK REPORT ==========\n";

    bool found = false;

    for (const auto &p : products)
    {
        if (p.getStock() <= 5)
        {
            p.displayProduct();
            found = true;
        }
    }

    if (!found)
        cout << "All Products Have Sufficient Stock.\n";
}

// Sales Report
void Admin::viewSalesReport()
{
    ifstream file("orders.txt");

    string line;
    int orders = 0;

    while (getline(file, line))
    {
        if (!line.empty())
            orders++;
    }

    file.close();

    cout << "\n========== SALES REPORT ==========\n";
    cout << "Total Order Records : " << orders << endl;
}