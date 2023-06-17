#include "session.hpp"
#include "book.hpp"
#include "utilities.hpp"

#include <string>
#include <ctime>
#include <sstream>


Session::Session(const Book& book): book(book), currPage(0) {
}

// Getters

const Book& Session::getBook() const{
    return book;
}


int Session::getCurrPage() const{
    return currPage+1;
}

std::string Session::getEndSessionTime() const{
    std::ostringstream oss;

    oss << 1900+ endSessionTime->tm_year << "-";
    oss << 1 + endSessionTime->tm_mon << "-";
    oss << endSessionTime->tm_mday << " ";

    oss << endSessionTime->tm_hour << ":";
    oss << endSessionTime->tm_min << ":";
    oss << endSessionTime->tm_sec;

    return oss.str();
}

// Other
void Session::updateEndSessionTime() {
    std::time_t now = time(0);

    endSessionTime = localtime(&now);
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