#include "filemanager.h"

void FileManager::saveProducts(const vector<Product>& products)
{
    ofstream file("products.txt");

    for(const auto &p : products)
    {
        file << p.getId() << "|"
             << p.getName() << "|"
             << p.getCategory() << "|"
             << p.getPrice() << "|"
             << p.getStock() << "|"
             << p.getRating() << "|"
             << p.getReviews() << endl;
    }

    file.close();
}

void FileManager::loadProducts(vector<Product>& products)
{
    products.clear();

    ifstream file("products.txt");

    string line;

    while(getline(file,line))
    {
        stringstream ss(line);

        string id,name,category,price,stock,rating,reviews;

        getline(ss,id,'|');
        getline(ss,name,'|');
        getline(ss,category,'|');
        getline(ss,price,'|');
        getline(ss,stock,'|');
        getline(ss,rating,'|');
        getline(ss,reviews,'|');

        products.push_back(
            Product(
                stoi(id),
                name,
                category,
                stof(price),
                stoi(stock),
                stof(rating),
                stoi(reviews)
            )
        );
    }

    file.close();
}