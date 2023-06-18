#ifndef SESSION_6122023_H
#define SESSION_6122023_H

#include "book.hpp"
#include <string>
#include <ctime>

class Session {
    private:
        const Book& book;
        int currPage;
        time_t endSessionTime;

        void updateEndSessionTime();
    public:
        Session(const Book& book);

        // Getters
        const Book& getBook() const;
        int getCurrPage() const;
        const time_t& getEndSessionTime() const;

        // Other
        void start();
        void print() const;
};

#endif