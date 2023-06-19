#include "sessionManager.hpp"
#include "session.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <map>
SessionManager::SessionManager() = default;

SessionManager::~SessionManager() {
  std::cout << "Deleted All Sessions\n";
}

void SessionManager::listSessions(const std::string& userName) const {
  if (!usernameToSessionsMap.count(userName))
    return;

  for (int i {0}; i < getNumOfSessions(userName); i++) {
    std::cout << i+1 << ". ";
    usernameToSessionsMap.at(userName)[i].print();
  }
}

void SessionManager::startSession(const std::string& userName, const Book& book) {
  usernameToSessionsMap[userName].emplace_back(Session(book));
  usernameToSessionsMap[userName].back().start();
}

void SessionManager::startSession(const std::string& userName, int currSession) {
  usernameToSessionsMap[userName][currSession].start();
}

int SessionManager::getNumOfSessions(const std::string& userName) const {
  if (usernameToSessionsMap.count(userName))
    return usernameToSessionsMap.at(userName).size();

  return 0;
}
