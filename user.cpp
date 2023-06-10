#include "user.h"
#include <string>
#include <iostream>

User::User() = default;

User::User(int id, std::string userName, std::string name, std::string email, std::string password, bool isAdmin) : id{id}, userName{userName}, name{name}, email{email}, password{password}, isAdmin{isAdmin}
{
}

// Getters
int User::getId() const
{
    return id;
}

std::string User::getUserName()
{
    return userName;
}

std::string User::getName()
{
    return name;
}

std::string User::getEmail()
{
    return email;
}

std::string User::getPassword()
{
    return password;
}

bool User::getIsAdmin()
{
    return isAdmin;
}

// Setters
void User::setId(int id)
{
    this->id = id;
}

void User::setUserName(std::string userName)
{
    this->userName = userName;
}

void User::setName(std::string name)
{
    this->name = name;
}

void User::setEmail(std::string email)
{
    this->email = email;
}

void User::setPassword(std::string password)
{
    this->password = password;
}

void User::setIsAdmin(bool isAdmin)
{
    this->isAdmin = isAdmin;
}

void User::readUser(std::string userName, int id)
{
    setId(id);
    setUserName(userName);
    setIsAdmin(0);

    std::string str;
    std::cout << "Enter your name (no spaces) : ";
    std::cin >> str;
    setName(str);

    std::cout << "Enter your email (no spaces) : ";
    std::cin >> str;
    setEmail(str);

    std::cout << "Enter your password (no spaces) : ";
    std::cin >> str;
    setPassword(str);
}

void User::print()
{
    std::cout << "\nName : " << getName();
    std::cout << "\nusername : " << getUserName();
    std::cout << "\nEmail : " << getEmail();
    std::cout << "\nPassword : " << getPassword();
    std::cout << "\nisAdmin : " << (getIsAdmin() ? "yes" : "no") << "\n";
}