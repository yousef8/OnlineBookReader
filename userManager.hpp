#ifndef USERMANAGER_6122023_H
#define USERMANAGER_6122023_H

#include "user.hpp"
#include <string>
#include <vector>

class UserManager
{
private:
    std::vector<User> users;
    int loggedUserIdx = -1;

    void resetLoggedUser();
    int findUser(const std::string& userName) const;
public:
    UserManager();

    const User& getLoggedUser() const;

    void listUsers();

    void login();

    void signUp();

    void accessSystem();
    bool isUserLogged() const;
};

#endif