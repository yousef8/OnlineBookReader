#ifndef SESSIONMANAGER_6122023_H
#define SESSIONMANAGER_6122023_H

#include "session.hpp"
#include "book.hpp"

#include <string>
#include <map>

class SessionManager{
    private:
        std::map<int, Session*> sessions;        
        int lastId;
    
    public:
        SessionManager();
        ~SessionManager();

        void listSessions() const;
        void startSession(const Book& book);
        Session* getSession(int idx) const;
        void startSession(Session* currSession);
        int getNumOfSessions() const;
};

#endif