#ifndef SESSIONMANAGER_6122023_H
#define SESSIONMANAGER_6122023_H

#include "session.hpp"
#include "book.hpp"

#include <string>
#include <vector>
#include <map>

class SessionManager{
    private:
        std::map<std::string, std::vector<Session>> usernameToSessionsMap;
    
    public:
        SessionManager();
        ~SessionManager();

        void listSessions(const std::string& userName) const;
        void startSession(const std::string& userName, const Book& book);
        void startSession(const std::string& userName, int currSession);
        int getNumOfSessions(const std::string& userName) const;
};

#endif
