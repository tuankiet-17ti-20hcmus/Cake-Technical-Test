#include "system.hpp"

/*
    This function use for login to the system when account/password has already input from keyboard.
        -> Check for the system has been overloaded or not by using maximum concurrent user.
        -> Check for username is exist in the database, then check valid password using Map data structure.
*/
void System::Login(string account, string password) {
    if(Map.find(account) != Map.end()) {
        // If there is username/email/phone in the list database, check for password.
        int id = Map[account]; // Index of this account in the list.
        if(profileList[id].getPassword() == password) {
            // Login success but exceed the number of concurrent user -> Failed.
            if(concurrentUser + 1 > MAX_USER) return void(cout << "System currently overload! Please try again later.\n");

            concurrentUser++; // Increase number of concurrent user in system.
            cout << "Login successfully!\n";
            return;

        }
    }

    cout << "Login Failed!\n";
    cout << "Username not exist or wrong password.\n";
}

/*
    This function use for register to the system when information such as name, mail,... has already input from keyboard.
        -> Check for username, email, phone number are all empty or not.
        -> Check for password is empty or not.
        -> Check for exist username, email, phone number before or not.
*/
void System::Register(const Profile& newRegister) {
    // username, email, phone are null -> can not register
    if(!newRegister.isValid()) {
        cout << "Register failed!\n";
        cout << "Please input at least one of username, email or phone number and make sure password is not empty.\n";
        return;
    }

    string username = newRegister.getUsername();
    string password = newRegister.getPassword();
    string email = newRegister.getEmail();
    string phone = newRegister.getPhone();

    // Need to check exist information
    if(username.size() != 0 && Map.find(username) != Map.end()) {
        cout << "Register failed! Username has been existed before!\n";
        return;
    }

    if(email.size() != 0 && Map.find(email) != Map.end()) {
        cout << "Register failed! Email has been existed before!\n";
        return;
    }

    if(phone.size() != 0 && Map.find(phone) != Map.end()) {
        cout << "Register failed! Phone number has been existed before!\n";
        return;
    }

    // Push (username, id), (email, id), (phone, id) to Map.
    if(username.size() != 0) Map[username] = numberUser;
    if(email.size() != 0) Map[email] = numberUser;
    if(phone.size() != 0) Map[phone] = numberUser;

    // Now, we can add new user to the list increase the number of user too.
    numberUser++;
    profileList.push_back(newRegister);

    cout << "Register successfully!\n";
    cout << "Your information has been saved to the system.\n";
}

/*
    Register form for input information such as name, email,...
*/
Profile inputRegister(System& Cake) {
    cin.ignore();

    string fullname;
    cout << "Input your full name (or skip by enter): ";
    getline(cin, fullname);

    string phone;
    cout << "Input your phone (or skip by enter): ";
    getline(cin, phone);

    string email;
    cout << "Input your email (or skip by enter): ";
    getline(cin, email);

    string username;
    cout << "Input your username (or skip by enter): ";
    getline(cin, username);

    string password;
    cout << "Input your password (or skip by enter): ";
    getline(cin, password);

    string birthday;
    cout << "Input your birthday (or skip by enter): ";
    getline(cin, birthday);

    cout << "\n";

    int id = Cake.getUser();
    Profile newRegister(id, fullname, phone, email, username, password, birthday);

    return newRegister;
}

/*
    Login form for input account and password.
*/
void inputLogin(string& account, string& password) {
    cin.ignore();

    cout << "Input your account: ";
    getline(cin, account);

    cout << "Input your password: ";
    getline(cin, password);

    cout << "\n";
}
