#ifndef SESSIONMANAGER_6122023_H
#define SESSIONMANAGER_6122023_H

#include "session.hpp"
#include "book.hpp"

#include <string>
#include <vector>

class SessionManager{
    private:
        std::vector<Session> sessions;        
    
    public:
        SessionManager();
        ~SessionManager();

        void listSessions() const;
        void startSession(const Book& book);
        void startSession(int currSession);
        int getNumOfSessions() const;
};

#endif
