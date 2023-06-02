#include "library.h"
#include "utilities.h"
#include "user.h"
#include "book.h"

Library::Library(User loggedUser): loggedUser{loggedUser} {
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
            std::cout << "To Do" << "\n";
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