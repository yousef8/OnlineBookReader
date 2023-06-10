#ifndef _sessionManager_H_
#define _sessionManager_H_

#include "session.h"
#include "book.h"

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