#ifndef USER_H
#define USER_H

#include <bits/stdc++.h>
using namespace std;

class User
{
protected:
    string username;
    string password;

    string fullName;
    string email;
    string phone;
    string address;

public:
    // Authentication
    void registerUser();
    bool login();

    // Getters
    string getUsername() const;
    string getFullName() const;
    string getEmail() const;
    string getPhone() const;
    string getAddress() const;

    // Setters
    void setFullName(string name);
    void setEmail(string email);
    void setPhone(string phone);
    void setAddress(string address);

    // Profile
    void displayProfile() const;
    void editProfile();
};

#endif