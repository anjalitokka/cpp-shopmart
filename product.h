#ifndef PRODUCT_H
#define PRODUCT_H

#include <bits/stdc++.h>
using namespace std;

class Product
{
private:
    int id;
    string name;
    string category;
    float price;
    int stock;
    float rating;
    int reviews;

public:
    // Constructors
    Product();
    Product(int id, string name, string category, float price, int stock,
            float rating = 0.0, int reviews = 0);

    // Getters
    int getId() const;
    string getName() const;
    string getCategory() const;
    float getPrice() const;
    int getStock() const;
    float getRating() const;
    int getReviews() const;

    // Setters
    void setStock(int stock);
    void setPrice(float price);
    void setRating(float rating);
    void setReviews(int reviews);

    // Utility
    bool isAvailable() const;
    void displayProduct() const;
};

#endif