#ifndef ORDER_H
#define ORDER_H

#include<bits/stdc++.h>
using namespace std;

class Order
{
private:
    int orderId;
    string customerName;
    vector<string> products;
    vector<int> quantity;
    float totalAmount;
    string orderDate;

public:

    Order();

    Order(int id,
          string customer,
          vector<string> products,
          vector<int> quantity,
          float total,
          string date);

    void displayOrder() const;

    void saveOrder();

    static void viewOrders();

    int getOrderId() const;
};

#endif