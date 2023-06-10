#ifndef _user_H_
#define _user_H_

#include <string>

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
    User();

    User(int id, std::string userName, std::string name, std::string email, std::string password, bool isAdmin);

    // Getters
    int getId() const;
    std::string getUserName();
    std::string getName();
    std::string getEmail();
    std::string getPassword();
    bool getIsAdmin();

    // Setters
    void setId(int id);
    void setUserName(std::string userName);
    void setName(std::string name);
    void setEmail(std::string email);
    void setPassword(std::string password);
    void setIsAdmin(bool isAdmin);

    void readUser(std::string userName, int id);

    void print();
};

#endif