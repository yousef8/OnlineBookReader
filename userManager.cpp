#include "userManager.h"
#include "utilities.h"
#include "user.h"
#include "library.h"

#include <iostream>
#include <string>
#include <map>

UserManager::UserManager()
{
    User admin{++lastId, "root", "root", "root@admin.com", "1234", 1};
    User customer{++lastId, "yousef", "yousefElsayed", "yousef@customer.com", "1234", 0};

    userNameToObjMap[admin.getUserName()] = admin;
    userNameToObjMap[customer.getUserName()] = customer;
}

void UserManager::listUsers()
{
    for (std::pair<std::string, User> p : userNameToObjMap)
        p.second.print();
}

void UserManager::login()
{
    for (int count {1}; count <= 3; count++) {
        std::cout << "Enter username (no spaces) : ";
        std::string userName;
        std::cin >> userName;

        if (userNameToObjMap.count(userName)){
            User loggedUser = userNameToObjMap[userName];
            std::cout << "Enter password : ";
            std::string password;
            std::cin >> password;
            if (loggedUser.getPassword() == password){
                Library library(loggedUser);
                return library.accessSystem();
            }
        }

        std::cout << "Wrong Username or Password!!!!\n";
        std::cout << (3 - count ) << " Tries left\n";
    }

    return;
}

void UserManager::signUp()
{
    std::string userName;
    while (true)
    {
        std::cout << "Enter username (no spaces) : ";
        std::cin >> userName;

        if (!userNameToObjMap.count(userName))
            break;

        std::cout << "Already Exist. Try again\n";
    }

    User newUser;
    newUser.readUser(userName, lastId);
    userNameToObjMap[newUser.getUserName()] = newUser;
}

void UserManager::accessSystem()
{
    int choice = showReadMenu({"Log In", "Sign Up", "Exit", "List Users"});

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        signUp();
        break;
    case 3:
        return;
    case 4:
        listUsers();
        break;
    }
    return accessSystem();
}
