#ifndef _library_H_
#define _library_H_

#include "session.h"
#include "sessionManager.h"
#include "user.h"
#include "book.h"
#include <map>

class BookManager{

private:
    std::map<int, Book> isbnToBook;
public:
    BookManager();

    void addBook();

    void listBooks(bool adminView = false);

    const Book& getBook(int idx);

    int getNumOfBooks() const;

};

#endif