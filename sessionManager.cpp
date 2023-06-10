#include "sessionManager.h"
#include "session.h"
#include "utilities.h"
#include "book.h"

#include <iostream>
#include <map>
#include <string>

SessionManager::SessionManager(): lastId(0) {
}

SessionManager::~SessionManager() {
    for (auto p : sessions)
        delete p.second;
    std::cout << "Deleted All Sessions\n";
}

void SessionManager::listSessions() const {
    for (std::pair<int, Session*> p : sessions){
        std::cout << p.first << ". " << p.second->getBook()->getTitle()
            << " - " <<  p.second->getCurrPage() << "/" << p.second->getBook()->getNumOfPages()
            << " - " << p.second->getEndSessionTime() << "\n";
    }
}

void SessionManager::startSession(const Book& book) {
    Session* session = new Session(book);
    session->start();
    sessions.insert(std::pair<int, Session*>(++lastId, session));
    return;
}

Session* SessionManager::getSession(int idx) const{
    return sessions.at(idx);
}

void SessionManager::startSession(Session* currSession) {
    currSession->start();
}

int SessionManager::getNumOfSessions() const {
    return sessions.size();
}