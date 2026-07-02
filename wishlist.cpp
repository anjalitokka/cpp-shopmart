#include "wishlist.h"
#include "cart.h"

void Wishlist::addToWishlist(Product p)
{
    for(const auto &item : wishlistItems)
    {
        if(item.getId() == p.getId())
        {
            cout << "\nProduct already exists in Wishlist.\n";
            return;
        }
    }

    wishlistItems.push_back(p);

    cout << "\nProduct Added to Wishlist Successfully!\n";
}

void Wishlist::removeFromWishlist(int productId)
{
    for(int i=0;i<wishlistItems.size();i++)
    {
        if(wishlistItems[i].getId()==productId)
        {
            wishlistItems.erase(wishlistItems.begin()+i);

            cout<<"\nProduct Removed Successfully!\n";
            return;
        }
    }

    cout<<"\nProduct Not Found!\n";
}

void Wishlist::viewWishlist() const
{
    if(wishlistItems.empty())
    {
        cout<<"\nWishlist is Empty.\n";
        return;
    }

    cout<<"\n========== MY WISHLIST ==========\n";

    for(const auto &p:wishlistItems)
        p.displayProduct();
}

void Wishlist::moveToCart(int productId, Cart &cart)
{
    for(int i=0;i<wishlistItems.size();i++)
    {
        if(wishlistItems[i].getId()==productId)
        {
            cart.addToCart(wishlistItems[i]);

            wishlistItems.erase(wishlistItems.begin()+i);

            cout<<"\nMoved To Cart Successfully!\n";

            return;
        }
    }

    cout<<"\nProduct Not Found!\n";
}

bool Wishlist::isEmpty() const
{
    return wishlistItems.empty();
}