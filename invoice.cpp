#include "invoice.h"

void Invoice::generateInvoice(
    int orderId,
    string customerName,
    vector<string> productNames,
    vector<int> quantity,
    vector<float> prices,
    float subtotal,
    float gst,
    float total)
{
    string filename = "invoice_" + to_string(orderId) + ".txt";

    ofstream file(filename);

    file<<"======================================"<<endl;
    file<<"            SHOPMART"<<endl;
    file<<"======================================"<<endl;

    file<<"Invoice No : "<<orderId<<endl;
    file<<"Customer   : "<<customerName<<endl;

    time_t now=time(0);

    file<<"Date       : "<<ctime(&now)<<endl;

    file<<"--------------------------------------"<<endl;

    file<<"Items"<<endl<<endl;

    for(int i=0;i<productNames.size();i++)
    {
        file<<left<<setw(20)
            <<productNames[i];

        file<<" Qty : "
            <<quantity[i];

        file<<" Price : Rs."
            <<prices[i];

        file<<endl;
    }

    file<<"--------------------------------------"<<endl;

    file<<"Subtotal : Rs."
        <<subtotal
        <<endl;

    file<<"GST(18%) : Rs."
        <<gst
        <<endl;

    file<<"Grand Total : Rs."
        <<total
        <<endl;

    file<<"======================================"<<endl;
    file<<"      THANK YOU FOR SHOPPING"<<endl;
    file<<"======================================"<<endl;

    file.close();

    cout<<"\nInvoice Generated Successfully!\n";
}