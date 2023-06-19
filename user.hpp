#ifndef USER_6122023_H
#define USER_6122023_H

#include <string>
#include <iostream>
#include <utility>

class User
{
private:
    int id {0};
    std::string userName {""};
    std::string name {""};
    std::string email {""};
    std::string password {""};
    bool isAdmin {0};

public:
    User() = default;

    User(int id, std::string userName, std::string name, std::string email, std::string password, bool isAdmin) : id{id}, userName{userName}, name{name}, email{email}, password{password}, isAdmin{isAdmin}
    {
    }

    // Getters
    int getId() const
    {
      return id;
    }

    const std::string& getUserName() const
    {
      return userName;
    }

    const std::string& getName() const
    {
      return name;
    }

    const std::string& getEmail() const
    {
      return email;
    }

    const std::string& getPassword() const
    { 
      return password;
    }

    bool getIsAdmin() const
    {
      return isAdmin;
    }

    // Setters
    void setId(int id_)
    {
      id = id_;
    }

    void setUserName(std::string userName_)
    {
      userName = std::move(userName_);
    }

    void setName(std::string name_)
    {
      name = std::move(name_);
    }

    void setEmail(std::string email_)
    {
      email = std::move(email_);
    }

    void setPassword(std::string password_)
    {
      password = std::move(password_);
    }

    void setIsAdmin(bool isAdmin_)
    {
      isAdmin = isAdmin_;
    }

    void readUser(std::string userName, int id)
    {
      setId(id);
      setUserName(std::move(userName));
      setIsAdmin(0);

      std::string str;
      std::cout << "Enter your name (no spaces) : ";
      std::cin >> str;
      setName(std::move(str));

      std::cout << "Enter your email (no spaces) : ";
      std::cin >> str;
      setEmail(std::move(str));

      std::cout << "Enter your password (no spaces) : ";
      std::cin >> str;
      setPassword(std::move(str));
    }

    void print() const
    {
      std::cout << "\nName : " << getName();
      std::cout << "\nusername : " << getUserName();
      std::cout << "\nEmail : " << getEmail();
      std::cout << "\nPassword : " << getPassword();
      std::cout << "\nisAdmin : " << (getIsAdmin() ? "yes" : "no") << "\n";
    }
};

#endif
