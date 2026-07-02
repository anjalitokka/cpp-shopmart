#include "cart.h"
#include "invoice.h"
#include "ordermanager.h"
#include "coupon.h"

// Add Product
void Cart::addToCart(Product p)
{
    // Check if product already exists
    for (int i = 0; i < cartItems.size(); i++)
    {
        if (cartItems[i].getId() == p.getId())
        {
            quantity[i]++;
            cout << "\nQuantity Updated Successfully!\n";
            return;
        }
    }

    cartItems.push_back(p);
    quantity.push_back(1);

    cout << "\nProduct Added To Cart Successfully!\n";
}

// Remove Product
void Cart::removeFromCart(int productId)
{
    for (int i = 0; i < cartItems.size(); i++)
    {
        if (cartItems[i].getId() == productId)
        {
            cartItems.erase(cartItems.begin() + i);
            quantity.erase(quantity.begin() + i);

            cout << "\nProduct Removed Successfully!\n";
            return;
        }
    }

    cout << "\nProduct Not Found!\n";
}

// View Cart
void Cart::viewCart() const
{
    if (cartItems.empty())
    {
        cout << "\nYour Cart is Empty.\n";
        return;
    }

    cout << "\n=========================================\n";
    cout << "              SHOPPING CART\n";
    cout << "=========================================\n";

    float total = 0;

    for (int i = 0; i < cartItems.size(); i++)
    {
        cout << "\nProduct " << i + 1 << endl;

        cartItems[i].displayProduct();

        cout << "Quantity : " << quantity[i] << endl;

        float subtotal = cartItems[i].getPrice() * quantity[i];

        cout << "Subtotal : Rs. " << subtotal << endl;

        total += subtotal;

        cout << "-----------------------------------------\n";
    }

    cout << "Grand Total : Rs. " << total << endl;
    cout << "=========================================\n";
}

// Total Price
float Cart::getTotalPrice() const
{
    float total = 0;

    for (int i = 0; i < cartItems.size(); i++)
        total += cartItems[i].getPrice() * quantity[i];

    return total;
}

// Checkout
float Cart::checkout(string username)
{
    if (cartItems.empty())
    {
        cout << "Cart is Empty!" << endl;
        return 0;
    }

    int orderId = OrderManager::getNextOrderID();
    float subtotal = 0;

    vector<string> productNames;
    vector<float> prices;

    for (int i = 0; i < cartItems.size(); i++)
    {
        subtotal += cartItems[i].getPrice() * quantity[i];

        productNames.push_back(cartItems[i].getName());

        prices.push_back(cartItems[i].getPrice());
    }

    float gst = subtotal * 0.18;

    float grandTotal = subtotal + gst;
    string coupon;

    cout << "\nEnter Coupon Code (Press 0 to Skip): ";

    cin >> coupon;

    if (coupon != "0")
    {
        grandTotal = Coupon::applyCoupon(coupon, grandTotal);
    }

    // Save Order
    ofstream file("orders.txt", ios::app);

    file << "====================================" << endl;
    file << "Order ID : " << orderId << endl;
    file << "Customer : " << username << endl;

    for (int i = 0; i < cartItems.size(); i++)
    {
        file << cartItems[i].getName()
             << " x "
             << quantity[i]
             << endl;
    }

    file << "Subtotal : " << subtotal << endl;
    file << "GST : " << gst << endl;
    file << "Grand Total : " << grandTotal << endl;
    file << "====================================" << endl;

    file.close();

    // Generate Invoice
    Invoice::generateInvoice(
        orderId,
        username,
        productNames,
        quantity,
        prices,
        subtotal,
        gst,
        grandTotal);

    cout << "\nCheckout Successful!\n";
    cout << "Grand Total : Rs." << grandTotal << endl;

    orderId++;

    clearCart();

    return grandTotal;
}
// Clear Cart
void Cart::clearCart()
{
    cartItems.clear();
    quantity.clear();
}

// Empty Check
bool Cart::isEmpty() const
{
    return cartItems.empty();
}

// Item Count
int Cart::getItemCount() const
{
    return cartItems.size();
}