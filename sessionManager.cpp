#include "sessionManager.h"
#include "session.h"
#include "utilities.h"

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

void SessionManager::listSessions() {
    for (std::pair<int, Session*> p : sessions){
        std::cout << p.first << ". " << p.second->getBook()->getTitle()
            << " - " <<  p.second->getCurrPage() << "/" << p.second->getBook()->getNumOfPages()
            << " - " << p.second->getEndSessionTime() << "\n";
    }
}

void SessionManager::startSession(Book book) {
    Session* session = new Session(book);
    session->start();
    sessions.insert(std::pair<int, Session*>(++lastId, session));
    return;
}

void SessionManager::listSelectSession() {
    listSessions();
    if (sessions.empty())
        return;

    std::cout << "Which session to open:\n";
    int choice = readInt(1,static_cast<int>(sessions.size()));
    Session* session = sessions[choice];
    session->start();
    return;
}