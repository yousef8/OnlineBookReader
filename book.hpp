#ifndef BOOK_6122023_H
#define BOOK_6122023_H

#include <vector>
#include <string>

class Book {
    private:
        int isbn;
        std::string title;
        std::string authorName;
        int numOfPages;
        std::vector<std::string> pagesToContent;
    
    public:
        Book();
        // Setters
        void setISBN(int isbn_);
        void setTitle(std::string title_);
        void setAuthorName(std::string authorName_);
        void setNumOfPages(int numOfPages_);
        void setContent(const std::vector<std::string>& pagesToContent_);

        // Getters
        int getISBN() const;
        std::string getTitle() const ;
        std::string getAuthorName() const ;
        int getNumOfPages() const ;
        const std::vector<std::string>& getContent() const;

        // Other
        void print();
        void readBook(int isbn);
};

#endif