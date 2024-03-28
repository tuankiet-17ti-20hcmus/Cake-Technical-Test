#include "profile.hpp"

string Profile::getUsername() const { return username; }

string Profile::getPassword() const { return password; }

string Profile::getEmail() const { return email; }

string Profile::getPhone() const { return phone; }

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
