#include <bits/stdc++.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include "wishlist.h"
#include "product.h"
#include "user.h"
#include "cart.h"
#include "admin.h"
#include "filemanager.h"
#include "search.h"

using namespace std;

const string ADMIN_PASSWORD = "admin123";

void pauseScreen()
{
    cout << "\n\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void loadingScreen()
{
#ifdef _WIN32
    system("cls");
#endif

    cout << "\n";
    cout << "==============================================\n";
    cout << "              SHOPMART\n";
    cout << "      Loading Application";

    for (int i = 0; i < 5; i++)
    {
        cout << ".";
#ifdef _WIN32
        Sleep(300);
#endif
    }

    cout << "\nApplication Loaded Successfully!\n";
    cout << "==============================================\n";

    pauseScreen();
}

void displayProducts(const vector<Product> &products)
{
    cout << "\n";
    cout << "==============================================\n";
    cout << "             AVAILABLE PRODUCTS\n";
    cout << "==============================================\n";

    cout << "Total Products : "
         << products.size()
         << endl;

    cout << "----------------------------------------------\n";

    if (products.empty())
    {
        cout << "No Products Available.\n";
        return;
    }

    for (const auto &p : products)
        p.displayProduct();
}

void about()
{
    cout << "\n";
    cout << "=====================================================\n";
    cout << "                    SHOPMART\n";
    cout << "=====================================================\n";

    cout << "Version        : 1.0.0\n";
    cout << "Language       : C++\n";
    cout << "Developer      : TOKKA ANJALI\n";

    cout << "\nTechnologies\n";
    cout << "-----------------------------------\n";
    cout << "Object-Oriented Programming\n";
    cout << "STL\n";
    cout << "File Handling\n";

    cout << "\nFeatures\n";
    cout << "-----------------------------------\n";

    cout << "User Registration & Login\n";
    cout << "Admin Dashboard\n";
    cout << "Shopping Cart\n";
    cout << "Wishlist\n";
    cout << "Search & Sorting\n";
    cout << "Invoice Generation\n";
    cout << "Coupon System\n";
    cout << "Order History\n";
    cout << "Reports\n";

    cout << "=====================================================\n";
}

int main()
{
    loadingScreen();

    vector<Product> products;

    FileManager::loadProducts(products);

    if (products.empty())
    {
        products.push_back(Product(1, "Laptop", "Electronics", 50000, 10, 4.8, 250));
        products.push_back(Product(2, "Mouse", "Accessories", 500, 20, 4.5, 180));
        products.push_back(Product(3, "Keyboard", "Accessories", 1500, 15, 4.7, 210));

        FileManager::saveProducts(products);
    }

    User user;
    Cart cart;
    Wishlist wishlist;
    Admin admin;

    bool loggedIn = false;

    int choice;

    while (true)
    {

#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        cout << "=====================================================\n";
        cout << "                    SHOPMART\n";
        cout << "         Console E-Commerce Management System\n";
        cout << "=====================================================\n";

        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Browse Products\n";
        cout << "4. Search Products\n";
        cout << "5. Add To Cart\n";
        cout << "6. Wishlist\n";
        cout << "7. View Cart\n";
        cout << "8. Checkout\n";
        cout << "9. Admin Panel\n";
        cout << "10. About\n";
        cout << "11. Exit\n";

        cout << "=====================================================\n";

        cout << "\nEnter Choice : ";

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            user.registerUser();

            pauseScreen();

            break;
        }

        case 2:
        {
            loggedIn = user.login();

            if (loggedIn)
            {
                cout << "\n=====================================\n";
                cout << " Welcome " << user.getFullName() << "!\n";
                cout << " Happy Shopping!\n";
                cout << "=====================================\n";
            }

            pauseScreen();

            break;
        }

        case 3:
        {
            displayProducts(products);

            pauseScreen();

            break;
        }

        case 4:
        {
            int searchChoice;

            do
            {
#ifdef _WIN32
                system("cls");
#endif

                cout << "\n=====================================\n";
                cout << "         SEARCH PRODUCTS\n";
                cout << "=====================================\n";

                cout << "1. Search By Name\n";
                cout << "2. Search By Category\n";
                cout << "3. Search By Price\n";
                cout << "4. Sort Price Low -> High\n";
                cout << "5. Sort Price High -> Low\n";
                cout << "6. Sort By Rating\n";
                cout << "7. Sort By Stock\n";
                cout << "8. Back\n";

                cout << "\nEnter Choice : ";
                cin >> searchChoice;

                switch (searchChoice)
                {
                case 1:
                    Search::searchByName(products);
                    pauseScreen();
                    break;

                case 2:
                    Search::searchByCategory(products);
                    pauseScreen();
                    break;

                case 3:
                    Search::searchByPrice(products);
                    pauseScreen();
                    break;

                case 4:
                    Search::sortByPriceLowToHigh(products);
                    displayProducts(products);
                    pauseScreen();
                    break;

                case 5:
                    Search::sortByPriceHighToLow(products);
                    displayProducts(products);
                    pauseScreen();
                    break;

                case 6:
                    Search::sortByRating(products);
                    displayProducts(products);
                    pauseScreen();
                    break;

                case 7:
                    Search::sortByStock(products);
                    displayProducts(products);
                    pauseScreen();
                    break;
                }

            } while (searchChoice != 8);

            break;
        }

        case 5:
        {
            if (!loggedIn)
            {
                cout << "\nPlease Login First!\n";
                pauseScreen();
                break;
            }

            displayProducts(products);

            int id;

            cout << "\nEnter Product ID : ";
            cin >> id;

            bool found = false;

            for (auto &p : products)
            {
                if (p.getId() == id)
                {
                    cart.addToCart(p);

                    found = true;

                    break;
                }
            }

            if (found)
                cout << "\nProduct Added Successfully!\n";
            else
                cout << "\nProduct Not Found!\n";

            pauseScreen();

            break;
        }

        case 6:
        {
            if (!loggedIn)
            {
                cout << "\nPlease Login First!\n";

                pauseScreen();

                break;
            }

            int wChoice;

            do
            {
#ifdef _WIN32
                system("cls");
#endif

                cout << "\n=====================================\n";
                cout << "            MY WISHLIST\n";
                cout << "=====================================\n";

                cout << "1. View Wishlist\n";
                cout << "2. Add Product\n";
                cout << "3. Remove Product\n";
                cout << "4. Move To Cart\n";
                cout << "5. Back\n";

                cout << "\nEnter Choice : ";

                cin >> wChoice;

                switch (wChoice)
                {
                case 1:
                    wishlist.viewWishlist();
                    pauseScreen();
                    break;

                case 2:
                {
                    displayProducts(products);

                    int id;

                    cout << "\nEnter Product ID : ";
                    cin >> id;

                    bool found = false;

                    for (auto &p : products)
                    {
                        if (p.getId() == id)
                        {
                            wishlist.addToWishlist(p);
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                        cout << "\nProduct Not Found!\n";

                    pauseScreen();

                    break;
                }

                case 3:
                {
                    int id;

                    cout << "\nEnter Product ID : ";
                    cin >> id;

                    wishlist.removeFromWishlist(id);

                    pauseScreen();

                    break;
                }

                case 4:
                {
                    int id;

                    cout << "\nEnter Product ID : ";
                    cin >> id;

                    wishlist.moveToCart(id, cart);

                    pauseScreen();

                    break;
                }
                }

            } while (wChoice != 5);

            break;
        }

        case 7:
        {
            if (!loggedIn)
            {
                cout << "\nPlease Login First!\n";
                pauseScreen();
                break;
            }

            cout << "\n=====================================\n";
            cout << "           SHOPPING CART\n";
            cout << "=====================================\n";

            cart.viewCart();

            pauseScreen();

            break;
        }

        case 8:
        {
            if (!loggedIn)
            {
                cout << "\nPlease Login First!\n";
                pauseScreen();
                break;
            }

            cout << "\n=====================================\n";
            cout << "             CHECKOUT\n";
            cout << "=====================================\n";

            cart.checkout(user.getUsername());

            pauseScreen();

            break;
        }

        case 9:
        {
            string password;

            cout << "\nEnter Admin Password : ";
            cin >> password;

            if (password != ADMIN_PASSWORD)
            {
                cout << "\nAccess Denied!\n";
                pauseScreen();
                break;
            }

            int adminChoice;

            do
            {
#ifdef _WIN32
                system("cls");
#endif

                admin.dashboard(products);

                cout << "\n=====================================\n";
                cout << "            ADMIN PANEL\n";
                cout << "=====================================\n";

                cout << "1. Add Product\n";
                cout << "2. View Products\n";
                cout << "3. Search Product\n";
                cout << "4. Update Product\n";
                cout << "5. Delete Product\n";
                cout << "6. Low Stock Report\n";
                cout << "7. Sales Report\n";
                cout << "8. Back\n";

                cout << "\nEnter Choice : ";
                cin >> adminChoice;

                switch (adminChoice)
                {
                case 1:
                    admin.addProduct(products);
                    FileManager::saveProducts(products);
                    pauseScreen();
                    break;

                case 2:
                    admin.viewProducts(products);
                    pauseScreen();
                    break;

                case 3:
                    admin.searchProduct(products);
                    pauseScreen();
                    break;

                case 4:
                    admin.updateProduct(products);
                    FileManager::saveProducts(products);
                    pauseScreen();
                    break;

                case 5:
                    admin.deleteProduct(products);
                    FileManager::saveProducts(products);
                    pauseScreen();
                    break;

                case 6:
                    admin.viewLowStockProducts(products);
                    pauseScreen();
                    break;

                case 7:
                    admin.viewSalesReport();
                    pauseScreen();
                    break;
                }

            } while (adminChoice != 8);

            break;
        }

        case 10:
        {
#ifdef _WIN32
            system("cls");
#endif

            about();

            pauseScreen();

            break;
        }

        case 11:
        {
#ifdef _WIN32
            system("cls");
#endif

            cout << "\n";
            cout << "=====================================================\n";
            cout << "          THANK YOU FOR VISITING SHOPMART\n";
            cout << "=====================================================\n";
            cout << "We hope you enjoyed shopping with us.\n";
            cout << "Have a wonderful day!\n";
            cout << "=====================================================\n";

            return 0;
        }

        default:
        {
            cout << "\nInvalid Choice! Please Try Again.\n";
            pauseScreen();
            break;
        }
        }
    }
    return 0;
}