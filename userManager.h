#ifndef _userManager_H_
#define _userManager_H_

#include "user.h"
#include <string>
#include <map>

class UserManager
{
private:
    std::map<std::string, User> userNameToObjMap;
    int lastId{0};

public:
    UserManager();

    void listUsers();

    void login();

    void signUp();

    void accessSystem();
};

#endif