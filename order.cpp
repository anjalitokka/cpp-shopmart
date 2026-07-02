#include "order.h"

Order::Order()
{
    orderId = 0;
    totalAmount = 0;
}

Order::Order(int id,
             string customer,
             vector<string> products,
             vector<int> quantity,
             float total,
             string date)
{
    orderId = id;
    customerName = customer;
    this->products = products;
    this->quantity = quantity;
    totalAmount = total;
    orderDate = date;
}

void Order::displayOrder() const
{
    cout << "\n==============================\n";

    cout << "Order ID : " << orderId << endl;

    cout << "Customer : " << customerName << endl;

    cout << "Date : " << orderDate << endl;

    cout << "\nItems\n";

    for(int i=0;i<products.size();i++)
    {
        cout << products[i]
             << " x "
             << quantity[i]
             << endl;
    }

    cout << "\nTotal : Rs. "
         << totalAmount
         << endl;

    cout << "==============================\n";
}

void Order::saveOrder()
{
    ofstream file("orders.txt",ios::app);

    file<<"============================"<<endl;
    file<<"Order ID : "<<orderId<<endl;
    file<<"Customer : "<<customerName<<endl;
    file<<"Date : "<<orderDate<<endl;

    for(int i=0;i<products.size();i++)
    {
        file<<products[i]
            <<" x "
            <<quantity[i]
            <<endl;
    }

    file<<"Total : "<<totalAmount<<endl;
    file<<"============================"<<endl;

    file.close();
}

void Order::viewOrders()
{
    ifstream file("orders.txt");

    string line;

    while(getline(file,line))
    {
        cout<<line<<endl;
    }

    file.close();
}

int Order::getOrderId() const
{
    return orderId;
}