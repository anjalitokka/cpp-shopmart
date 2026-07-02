#include "product.h"

// Default Constructor
Product::Product()
{
    id = 0;
    name = "";
    category = "";
    price = 0;
    stock = 0;
    rating = 0.0;
    reviews = 0;
}

// Parameterized Constructor
Product::Product(int id, string name, string category, float price,
                 int stock, float rating, int reviews)
{
    this->id = id;
    this->name = name;
    this->category = category;
    this->price = price;
    this->stock = stock;
    this->rating = rating;
    this->reviews = reviews;
}

// Getters
int Product::getId() const
{
    return id;
}

string Product::getName() const
{
    return name;
}

string Product::getCategory() const
{
    return category;
}

float Product::getPrice() const
{
    return price;
}

int Product::getStock() const
{
    return stock;
}

float Product::getRating() const
{
    return rating;
}

int Product::getReviews() const
{
    return reviews;
}

// Setters
void Product::setStock(int stock)
{
    this->stock = stock;
}

void Product::setPrice(float price)
{
    this->price = price;
}

void Product::setRating(float rating)
{
    this->rating = rating;
}

void Product::setReviews(int reviews)
{
    this->reviews = reviews;
}

// Utility
bool Product::isAvailable() const
{
    return stock > 0;
}

// Display Product Details
void Product::displayProduct() const
{
    cout << "==========================================" << endl;
    cout << "Product ID : " << id << endl;
    cout << "Name       : " << name << endl;
    cout << "Category   : " << category << endl;
    cout << "Price      : Rs. " << fixed << setprecision(2) << price << endl;
    cout << "Stock      : " << stock << endl;
    cout << "Rating     : " << rating << " (" << reviews << " Reviews)" << endl;

    if (stock > 0)
        cout << "Status     : In Stock" << endl;
    else
        cout << "Status     : Out of Stock" << endl;

    cout << "==========================================" << endl;
}