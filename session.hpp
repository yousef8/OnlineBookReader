#ifndef SESSION_6122023_H
#define SESSION_6122023_H

#include "book.hpp"
#include <ctime>
#include <string>

class Session {
    private:
        const Book& book;
        int currPage;
        tm* endSessionTime;

        void updateEndSessionTime();
    public:
        Session(const Book& book);

        // Getters
        const Book& getBook() const;
        int getCurrPage() const;
        std::string getEndSessionTime() const;

        // Other
        void start();
};

#endif