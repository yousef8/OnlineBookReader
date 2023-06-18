#include "sessionManager.hpp"
#include "session.hpp"
#include "utilities.hpp"
#include "book.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

SessionManager::SessionManager() = default;

SessionManager::~SessionManager() {
    std::cout << "Deleted All Sessions\n";
}

void SessionManager::listSessions() const {
  for (int i {0}; i < getNumOfSessions(); i++) {
    std::cout << i+1 << ". ";
    sessions[i].print();
  }
}

void SessionManager::startSession(const Book& book) {
  sessions.emplace_back(Session(book));
  sessions.back().start();
}

void SessionManager::startSession(int currSession) {
    sessions[currSession].start();
}

int SessionManager::getNumOfSessions() const {
    return sessions.size();
}
