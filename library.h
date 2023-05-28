#ifndef _library_H_
#define _library_H_

#include "user.h"

class Library {

private:
    User loggedUser;

    void adminView();

    void userView();

public:
    Library(User loggedUser);

    void accessSystem();
};

#endif