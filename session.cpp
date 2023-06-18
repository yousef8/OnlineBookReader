#include "session.hpp"
#include "book.hpp"
#include "utilities.hpp"

#include <string>
#include <ctime>
#include <chrono>

Session::Session(const Book& book): book(book), currPage(0) {
}

// Getters

const Book& Session::getBook() const{
    return book;
}


int Session::getCurrPage() const{
    return currPage+1;
}

const time_t& Session::getEndSessionTime() const{
    return endSessionTime;
}

// Other
void Session::updateEndSessionTime() {
    endSessionTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}


void Session::start() {
    std::cout << book.getContent()[currPage] << "\n";

    int choice = showReadMenu({"Next", "Previous", "Stop"});
    switch (choice) {
        case 1:
            (currPage == book.getNumOfPages()-1) ? currPage : ++currPage;
            start();
            break;
        case 2:
            (currPage == 0) ? currPage : --currPage;
            start();
            break;
        case 3:
            updateEndSessionTime();
            return;
    }
}