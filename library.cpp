#include "library.h"
#include "utilities.h"
#include "user.h"
#include "book.h"

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
    std::cout << "User View\n";
    return;
}

void Library::accessSystem() {
    if (loggedUser.getIsAdmin())
        return Library::adminView();
    
    return Library::userView();
}