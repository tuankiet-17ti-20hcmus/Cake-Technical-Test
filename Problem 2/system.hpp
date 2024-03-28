#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include "campaign.hpp"

// Maximum concurrent user in the system.
const int MAX_USER = 1e6 + 7;

// Base on Singleton design pattern.
class System {
public:
    System(const System&) = delete;

    static System& getInstance() {
        return s_Instance;
    }

    int getUser() const { return numberUser; }

    void Register(const Profile& newRegister);

    void Login(string account, string password, campaign& Campaign);

private:
    System() {}

    // Concurrent users are using the system.
    int concurrentUser = 0;

    // Total user in the system.
    // When a new user register, id's profile = numberUser.
    int numberUser = 0;

    // Store profile which was registered before.
    vector<Profile>profileList;

    // Red-Black Tree data structure (base on Binary Search Tree).
    // Each time system have new valid register, we push (username, profileID), (email, profileID), (phone, profileID) to our Map.
    // Time complexity: O(log2(size)).
    map<string, int>Map;

    static System s_Instance;
};

#endif
