#ifndef _userManager_H_
#define _userManager_H_

#include "user.hpp"
#include <string>
#include <map>

class UserManager
{
private:
    std::map<std::string, User> userNameToObjMap;
    int lastId{0};
    std::string loggedUserName {""};

    void resetLoggedUser();
public:
    UserManager();

    const User& getLoggedUser() const;

    void listUsers();

    void login();

    void signUp();

    void accessSystem();
};

#endif