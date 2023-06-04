#include "session.h"
#include "book.h"
#include "utilities.h"

#include <string>
#include <ctime>
#include <sstream>


Session::Session(Book book): book(book), currPage(1) {
}

// Getters

Book* Session::getBook() {
    return &book;
}


int Session::getCurrPage() {
    return currPage;
}

std::string Session::getEndSessionTime() {
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
            (currPage == book.getNumOfPages()) ? currPage : ++currPage;
            start();
            break;
        case 2:
            (currPage == 1) ? currPage : --currPage;
            start();
            break;
        case 3:
            updateEndSessionTime();
            return;
    }
}