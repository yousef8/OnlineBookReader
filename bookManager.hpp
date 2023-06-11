#ifndef _library_H_
#define _library_H_

#include "session.hpp"
#include "sessionManager.hpp"
#include "user.hpp"
#include "book.hpp"
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