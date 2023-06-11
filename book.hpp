#ifndef BOOK_6122023_H
#define BOOK_6122023_H

#include <vector>
#include <map>
#include <string>

class Book {
    private:
        int isbn;
        std::string title;
        std::string authorName;
        int numOfPages;
        std::map<int, std::string> pagesToContent;
    
    public:
        Book();
        // Setters
        void setISBN(int isbn);
        void setTitle(std::string title);
        void setAuthorName(std::string authorName);
        void setNumOfPages(int numOfPages);
        void setContent(std::vector<std::string>);

        // Getters
        int getISBN();
        std::string getTitle();
        std::string getAuthorName();
        int getNumOfPages();
        std::map<int, std::string> getContent();

        // Other
        void print();
        void readBook(int isbn);
};

#endif