#include "userManager.hpp"
#include "utilities.hpp"
#include "user.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <utility>

UserManager::UserManager(){
    users.emplace_back( User {"root", "root", "root@admin.com", "1234", 1});
    users.emplace_back( User {"yousef", "yousefElsayed", "yousef@customer.com", "1234", 0});
}

void UserManager::resetLoggedUser() {
    loggedUserIdx = -1;
}

int UserManager::findUser(const std::string& userName) const {
    for (int i {0}; i < users.size(); i++)
        if(users[i].getUserName() == userName)
            return i;
    return -1;
}

const User& UserManager::getLoggedUser() const {
    return users[loggedUserIdx];
}

void UserManager::listUsers()
{
    for (auto& user : users) 
        user.print();
}

void UserManager::login()
{
    for (int count {1}; count <= 3; count++) {
        std::cout << "Enter username (no spaces) : ";
        std::string userName;
        std::cin >> userName;

        int id = findUser(userName);
        if (id > -1) {
            User& loggedUser = users[id];
            std::cout << "Enter password : ";
            std::string password;
            std::cin >> password;
            if (loggedUser.getPassword() == password){
                loggedUserIdx = id;
                return;
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

        if (findUser(userName) == -1)
            break;

        std::cout << "Already Exist. Try again\n";
    }

    User newUser;
    newUser.readUser(userName);
    users.push_back(std::move(newUser));
}

void UserManager::accessSystem()
{
    int choice = showReadMenu({"Log In", "Sign Up", "List Users", "Exit"});

    switch (choice)
    {
    case 1:
        return login();
        break;
    case 2:
        signUp();
        break;
    case 3:
        listUsers();
        break;
    case 4:
        resetLoggedUser();
        return;
    }
    return accessSystem();
}

bool UserManager::isUserLogged() const {
    return (loggedUserIdx > -1);
}