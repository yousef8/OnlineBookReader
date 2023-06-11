#ifndef _session_H_
#define _session_H_

#include "book.hpp"
#include <ctime>
#include <string>

class Session {
    private:
        Book book;
        int currPage;
        tm* endSessionTime;

        void updateEndSessionTime();
    public:
        Session(Book book);

        // Getters
        Book* getBook();
        int getCurrPage();
        std::string getEndSessionTime();

        // Other
        void start();
};

#endif