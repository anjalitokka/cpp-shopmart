#include "search.h"

// Search by Product Name
void Search::searchByName(const vector<Product>& products)
{
    string name;

    cin.ignore();

    cout << "\nEnter Product Name : ";
    getline(cin, name);

    string searchKey = name;

    transform(searchKey.begin(), searchKey.end(),
              searchKey.begin(), ::tolower);

    bool found = false;

    for (const auto &p : products)
    {
        string productName = p.getName();

        transform(productName.begin(), productName.end(),
                  productName.begin(), ::tolower);

        if (productName.find(searchKey) != string::npos)
        {
            p.displayProduct();
            found = true;
        }
    }

    if (!found)
        cout << "\nNo Matching Products Found!\n";
}

// Search by Category
void Search::searchByCategory(const vector<Product>& products)
{
    string category;

    cin.ignore();

    cout << "\nEnter Category : ";
    getline(cin, category);

    string key = category;

    transform(key.begin(), key.end(),
              key.begin(), ::tolower);

    bool found = false;

    for (const auto &p : products)
    {
        string productCategory = p.getCategory();

        transform(productCategory.begin(), productCategory.end(),
                  productCategory.begin(), ::tolower);

        if (productCategory == key)
        {
            p.displayProduct();
            found = true;
        }
    }

    if (!found)
        cout << "\nNo Products Found In This Category!\n";
}

// Search by Price Range
void Search::searchByPrice(const vector<Product>& products)
{
    float minPrice, maxPrice;

    cout << "\nMinimum Price : ";
    cin >> minPrice;

    cout << "Maximum Price : ";
    cin >> maxPrice;

    bool found = false;

    for (const auto &p : products)
    {
        if (p.getPrice() >= minPrice &&
            p.getPrice() <= maxPrice)
        {
            p.displayProduct();
            found = true;
        }
    }

    if (!found)
        cout << "\nNo Products Found In This Price Range!\n";
}

// Sort Price Low -> High
void Search::sortByPriceLowToHigh(vector<Product>& products)
{
    sort(products.begin(), products.end(),
        [](const Product &a, const Product &b)
        {
            return a.getPrice() < b.getPrice();
        });

    cout << "\nProducts Sorted (Low -> High)\n";
}

// Sort Price High -> Low
void Search::sortByPriceHighToLow(vector<Product>& products)
{
    sort(products.begin(), products.end(),
        [](const Product &a, const Product &b)
        {
            return a.getPrice() > b.getPrice();
        });

    cout << "\nProducts Sorted (High -> Low)\n";
}

// Sort By Rating
void Search::sortByRating(vector<Product>& products)
{
    sort(products.begin(), products.end(),
        [](const Product &a, const Product &b)
        {
            return a.getRating() > b.getRating();
        });

    cout << "\nProducts Sorted By Rating\n";
}

// Sort By Stock
void Search::sortByStock(vector<Product>& products)
{
    sort(products.begin(), products.end(),
        [](const Product &a, const Product &b)
        {
            return a.getStock() > b.getStock();
        });

    cout << "\nProducts Sorted By Stock\n";
}