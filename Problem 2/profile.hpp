#ifndef PROFILE_HPP_
#define PROFILE_HPP_

#include "voucher.hpp"

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
    bool firstTime; // This variable tell the system current register can have a voucher or not.
    voucher curVoucher; //Default voucher have nothing.


public:
    Profile(int id_, string name_, string phone_, string email_, string username_, string password_, string birthday_) {
        id = id_;
        name = name_;
        phone = phone_;
        email = email_;
        username = username_;
        password = password_;
        birthday = birthday_;
        lastLogin = "today";
        firstTime = true;
    }

    string getUsername() const;
    string getPassword() const;
    string getEmail() const;
    string getPhone() const;

    // When register, check user input is valid or not.
    bool isValid() const;

    // Join the campaign and get the voucher.
    void setVoucher(const voucher& newVoucher);

    // Check for new register to have a voucher or not.
    bool firstLogin();

    // Function to calculate total money that user need to transfer including voucher (if any).
    double transferMoney(double value);

};

#endif
