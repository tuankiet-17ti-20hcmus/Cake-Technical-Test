#include "profile.hpp"

string Profile::getUsername() const { return username; }

string Profile::getPassword() const { return password; }

string Profile::getEmail() const { return email; }

string Profile::getPhone() const { return phone; }

// Now the user have the voucher.
void Profile::setVoucher(const voucher& newVoucher) {
    curVoucher = newVoucher;
    cout << "Your voucher's CODE: " << curVoucher.getCode() << endl;
}

// When register, check user input is valid or not.
bool Profile::isValid() const {
    //username, email, phone can not all null.
    if(username.size() == 0 && email.size() == 0 && phone.size() == 0)
        return false;

    // password can not empty.
    if(password.size() == 0)
        return false;

    return true;
}

// Check for new register to have a voucher or not.
bool Profile::firstLogin() {
    // New accout, then get a voucher.
    if(firstTime == true) {
        firstTime = false; // After getting the voucher, this account not new anymore.
        return true;
    }
    return false;
}

// Calculate total transfer money including using voucher (if any).
double Profile::transferMoney(double value) {
    double discount = curVoucher.getDiscount();
    if(discount) value *= (100 - discount) / 100;
    return value;
}
