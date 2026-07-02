#include "ordermanager.h"

int OrderManager::getNextOrderID()
{
    ifstream in("orderid.txt");

    int id=1000;

    if(in.is_open())
        in>>id;

    in.close();

    id++;

    ofstream out("orderid.txt");

    out<<id;

    out.close();

    return id;
}