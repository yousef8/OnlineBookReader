#include "library.h"
#include "utilities.h"
#include "user.h"

Library::Library(User loggedUser): loggedUser{loggedUser} {
}

void Library::adminView() {
    std::cout << "\n\nHello " << loggedUser.getName() << " | " << "Admin View\n";
    int choice = showReadMenu({"View Profile", "Add Book", "List Books", "Log Out"});

    switch (choice) {
        case 1:
            loggedUser.print();
            break;
        case 2:
            std::cout << "To Do" << "\n";
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