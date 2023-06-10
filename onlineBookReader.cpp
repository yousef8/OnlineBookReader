#include "userManager.h"
#include "bookManager.h"
#include "sessionManager.h"

#include "utilities.h"
#include "user.h"

#include <iostream>
#include <string>
#include <map>

class OnlineReader {
    private:
        SessionManager sessionManager;
        BookManager bookManager;
        UserManager userManager;
    
    public:
        OnlineReader() = default;
        void Run() {
            // Login Phase
            userManager.accessSystem();
            if (!userManager.getLoggedUser().getId()) {
                std::cout << "Goodbye from run\n";
                return;
            } 
        }
    
};
int main()
{
    OnlineReader service;
    service.Run();
}