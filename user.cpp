#include "user.h"

// Register User
void User::registerUser()
{
    ofstream file("users.txt", ios::app);

    cout << "\n========== USER REGISTRATION ==========\n";

    cin.ignore();

    cout << "Full Name      : ";
    getline(cin, fullName);

    cout << "Username       : ";
    getline(cin, username);

    cout << "Password       : ";
    getline(cin, password);

    cout << "Email          : ";
    getline(cin, email);

    cout << "Phone Number   : ";
    getline(cin, phone);

    cout << "Address        : ";
    getline(cin, address);

    file << fullName << "|"
         << username << "|"
         << password << "|"
         << email << "|"
         << phone << "|"
         << address << endl;

    file.close();

    cout << "\nRegistration Successful!\n";
}

// Login
bool User::login()
{
    string u, p;
    string line;

    cout << "\n========== LOGIN ==========\n";

    cout << "Username : ";
    cin >> u;

    cout << "Password : ";
    cin >> p;

    ifstream file("users.txt");

    while (getline(file, line))
    {
        stringstream ss(line);

        getline(ss, fullName, '|');
        getline(ss, username, '|');
        getline(ss, password, '|');
        getline(ss, email, '|');
        getline(ss, phone, '|');
        getline(ss, address, '|');

        if (u == username && p == password)
        {
            cout << "\nLogin Successful!\n";
            file.close();
            return true;
        }
    }

    file.close();

    cout << "\nInvalid Username or Password!\n";
    return false;
}

// Getters
string User::getUsername() const
{
    return username;
}

string User::getFullName() const
{
    return fullName;
}

string User::getEmail() const
{
    return email;
}

string User::getPhone() const
{
    return phone;
}

string User::getAddress() const
{
    return address;
}

// Setters
void User::setFullName(string name)
{
    fullName = name;
}

void User::setEmail(string mail)
{
    email = mail;
}

void User::setPhone(string ph)
{
    phone = ph;
}

void User::setAddress(string addr)
{
    address = addr;
}

// Display Profile
void User::displayProfile() const
{
    cout << "\n========== MY PROFILE ==========\n";

    cout << "Name      : " << fullName << endl;
    cout << "Username  : " << username << endl;
    cout << "Email     : " << email << endl;
    cout << "Phone     : " << phone << endl;
    cout << "Address   : " << address << endl;

    cout << "=================================\n";
}

// Edit Profile
void User::editProfile()
{
    cin.ignore();

    cout << "\n========== EDIT PROFILE ==========\n";

    cout << "New Name      : ";
    getline(cin, fullName);

    cout << "New Email     : ";
    getline(cin, email);

    cout << "New Phone     : ";
    getline(cin, phone);

    cout << "New Address   : ";
    getline(cin, address);

    cout << "\nProfile Updated Successfully!\n";
}