#ifndef _library_H_
#define _library_H_

#include "session.h"
#include "sessionManager.h"
#include "user.h"
#include "book.h"
#include <map>

class Library {

private:
    User loggedUser;
    std::map<int, Book> isbnToBook;
    SessionManager sessionManager;
    void addBook();

    void listBooks();

    void listSelectSession();

    void listSelectBook();

    void adminView();

    void userView();

public:
    Library(User loggedUser);

    void accessSystem();
};

#endif