#include "bookManager.h"
#include "utilities.h"
#include "user.h"
#include "book.h"
#include "session.h"
#include "sessionManager.h"

#include <string>
#include <vector>
#include <iostream>

BookManager::BookManager() {
    Book book1;
    book1.setISBN(1234), book1.setAuthorName("yousef"), book1.setTitle("C++ how to program"), book1.setNumOfPages(5), book1.setContent({"A C++", "B C++", "C C++", "D C++", "E C++"});

    Book book2;
    book2.setISBN(5678), book2.setTitle("Intro to algo"), book2.setAuthorName("yousef"), book2.setNumOfPages(5), book2.setContent({"A Algo", "B Algo", "C Algo", "D Algo", "E Algo"});

    isbnToBook[book1.getISBN()] = book1;
    isbnToBook[book2.getISBN()] = book2;
}

void BookManager::addBook() {
    
    for (int count {1}; count <= 3; count++) {
        std::cout << "Enter ISBN : ";
        int isbn;
        std::cin >> isbn;

        if (!isbnToBook.count(isbn)){
            Book book;
            book.readBook(isbn); 
            isbnToBook[isbn] = book;
            break;
        }

        std::cout << "A book with this ISBN already exist!!!!\n";
        std::cout << (3 - count ) << " Tries left\n";
    }
}

void BookManager::listBooks() {
    for (std::pair<int, Book> p : isbnToBook)
        p.second.print(), std::cout << "\n";
}
