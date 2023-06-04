#include "library.h"
#include "utilities.h"
#include "user.h"
#include "book.h"
#include "session.h"
#include "sessionManager.h"

#include <string>
#include <vector>
#include <iostream>

Library::Library(User loggedUser): loggedUser{loggedUser} {
    Book book1;
    book1.setISBN(1234), book1.setAuthorName("yousef"), book1.setTitle("C++ how to program"), book1.setNumOfPages(5), book1.setContent({"A C++", "B C++", "C C++", "D C++", "E C++"});

    Book book2;
    book2.setISBN(5678), book2.setTitle("Intro to algo"), book2.setAuthorName("yousef"), book2.setNumOfPages(5), book2.setContent({"A Algo", "B Algo", "C Algo", "D Algo", "E Algo"});

    isbnToBook[book1.getISBN()] = book1;
    isbnToBook[book2.getISBN()] = book2;
}

void Library::addBook() {
    
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

void Library::listBooks() {
    for (std::pair<int, Book> p : isbnToBook)
        p.second.print(), std::cout << "\n";
}

void Library::listSelectBook() {

    // Show available books
    std::vector<std::string> books;
    for (auto p : isbnToBook)
        books.push_back(p.second.getTitle());
    
    int choice = showReadMenu(books, "Our current book collection");

    // Get the chosen book
    auto record = isbnToBook.begin();

    while (--choice)
        ++record;
    
    // Start Session
    Book currBook = record->second;
    sessionManager.startSession(currBook);
}

void Library::listSelectSession() {
    std::cout << "\n";
    sessionManager.listSelectSession();
    std::cout << "\n";
}

void Library::adminView() {
    std::cout << "\n\nHello " << loggedUser.getName() << " | " << "Admin View\n";
    int choice = showReadMenu({"View Profile", "Add Book", "List Books", "Log Out"});

    switch (choice) {
        case 1:
            loggedUser.print();
            break;
        case 2:
            addBook();
            break;
        case 3:
            listBooks();
            break;
        case 4:
            return; 
    }

    return adminView();
}

void Library::userView() {
    std::cout << "\n\nHello " << loggedUser.getName() << " | " << "User View\n";
    int choice = showReadMenu({"View Profile", "List & Select from My Reading History", "List & Select from Available Books", "Log Out"});

    switch (choice) {
        case 1:
            loggedUser.print();
            return userView();
            break;
        case 2:
            listSelectSession();
            return userView();
            break;
        case 3:
            listSelectBook();
            return userView();
            break;
        case 4:
            return;
    }
}

void Library::accessSystem() {
    if (loggedUser.getIsAdmin())
        return Library::adminView();
    
    return Library::userView();
}