#ifndef _library_H_
#define _library_H_

#include "user.h"
#include "book.h"
#include <map>

class Library {

private:
    User loggedUser;
    std::map<int, Book> isbnToBook;

    void addBook();

    void listBooks();

    void adminView();

    void userView();

public:
    Library(User loggedUser);

    void accessSystem();
};

#endif