#include "system.hpp"

// Input from keyboard to register form.
Profile inputRegister(System&);

// Input from keyboard to login form.
void inputLogin(string&, string&);

// Create system instance
System System::s_Instance;

int main() {
    System& Cake = System::getInstance();

    // Driver
    int choice;
    while(true) {
        int choice;

        cout << "WELCOME TO THE SYSTEM!" << endl;
        cout << "Input 0/1/2 to exit/login/register the system: ";

        cin >> choice;
        cout << "\n";

        // Exit system
        if(choice == 0) {
            break;
        }

        // Login
        if(choice == 1) {
            string account, password;
            inputLogin(account, password); // Input account and password.

            // Login to system
            Cake.Login(account, password);
        }

        // Register
        if(choice == 2) {
            Profile newRegister = inputRegister(Cake); // Input information such as name, email,...

            // Send register's information to system to check.
            Cake.Register(newRegister);
        }

        cout << "---------------------------------------------------------------------------------\n";
    }

    cout << "Thank you for using the system!";

    return 0;
}
