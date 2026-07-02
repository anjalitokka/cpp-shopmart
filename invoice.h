#ifndef INVOICE_H
#define INVOICE_H

#include<bits/stdc++.h>
using namespace std;

class Invoice
{
public:

    static void generateInvoice(
        int orderId,
        string customerName,
        vector<string> productNames,
        vector<int> quantity,
        vector<float> prices,
        float subtotal,
        float gst,
        float total
    );
};

#endif