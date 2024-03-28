#ifndef PROFILE_HPP_
#define PROFILE_HPP_

#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Profile {
private:
    int id; // Assign by number of user in the system.
    string name;
    string phone;
    string email;
    string username;
    string password;
    string birthday;
    string lastLogin;


public:
    Profile() {}

    Profile(int id_, string name_, string phone_, string email_, string username_, string password_, string birthday_) {
        id = id_;
        name = name_;
        phone = phone_;
        email = email_;
        username = username_;
        password = password_;
        birthday = birthday_;
        lastLogin = "today";
    }

    // When register, check user input is valid or not.
    bool isValid() const;

    string getUsername() const;
    string getPassword() const;
    string getEmail() const;
    string getPhone() const;
};

#endif
