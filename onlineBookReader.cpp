#include "userManager.hpp"
#include "bookManager.hpp"
#include "sessionManager.hpp"

#include "utilities.hpp"
#include "user.hpp"

#include <iostream>
#include <string>
#include <map>

class OnlineReader {
    private:
        SessionManager sessionManager;
        BookManager bookManager;
        UserManager userManager;
    
        void userView() {
            while (true){
                int choice = showReadMenu({"View Profile", "List & Select from Reading History", "List & Select from Available Books", "Log Out"});

                switch(choice) {
                    case 1:
                        userManager.getLoggedUser().print();
                        break;
                    case 2:
                        {
                        sessionManager.listSessions();
                        int sessionIdx = readInt(0, sessionManager.getNumOfSessions());
                        if (!sessionIdx)
                            continue;
                        sessionManager.startSession(--sessionIdx);
                        break;
                        }
                    case 3:
                    {
                        bookManager.listBooks();
                        int bookIdx = readInt(0, bookManager.getNumOfBooks());
                        if (!bookIdx)
                            continue;
                        sessionManager.startSession(bookManager.getBook(bookIdx));
                        break;
                    }
                    case 4:
                        return;
                }
            }
        }

        void adminView() {
            while(true){
                int choice = showReadMenu({"View Profile", "Add Book", "List Books", "Log Out"});

                switch (choice){
                    case 1:
                        userManager.getLoggedUser().print();
                        break;
                    case 2:
                        bookManager.addBook();
                        break;
                    case 3:
                        bookManager.listBooks(true);
                        break; 
                    case 4:
                        return;
                }
            }
        }
    public:
        OnlineReader() = default;

        void Run() {
            // Login Phase
            userManager.accessSystem();
            if (!userManager.getLoggedUser().getId()) {
                std::cout << "GoodBye\n";
                return;
            }

            // Actual System
            if (userManager.getLoggedUser().getIsAdmin())
                adminView();
            else
                userView();

            return Run(); 
        }
    
};
int main()
{
    OnlineReader service;
    service.Run();
}
