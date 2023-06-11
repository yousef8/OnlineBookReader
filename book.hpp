#ifndef BOOK_6122023_H
#define BOOK_6122023_H

#include <iostream>
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
        Book(){
           title = authorName = "";
            isbn =  numOfPages = -1;
        }

        // Setters
        void setISBN(int isbn_){
            isbn = isbn_;
        }

        void setTitle(std::string title_){
            title = title_;
        }
        
        void setAuthorName(std::string authorName_) {
            authorName = authorName_;
        }
        
        void setNumOfPages(int numOfPages_){
            numOfPages = numOfPages_;
        }
        
        void setContent(const std::vector<std::string>& pagesToContent_){
            for (auto& content : pagesToContent_)
                pagesToContent.push_back(content);
        }

        // Getters
        int getISBN() const{
            return isbn;
        }
        
        std::string getTitle() const {
            return title;
        }
        
        std::string getAuthorName() const {
            return authorName;
        }
        
        int getNumOfPages() const {
            return numOfPages;
        }
        
        const std::vector<std::string>& getContent() const{
            return pagesToContent;
        }

        // Other
        void print(){
            std::cout << "\n" << "ISBN : " << getISBN()
                << "\n" << "Title : " << getTitle()
                << "\n" << "Author : " << getAuthorName()
                << "\n" << "Number of Pages : " << getNumOfPages() << "\n";
        }
        
        void readBook(int isbn){
            setISBN(isbn);

            std::cout << "Enter Title : ";
            std::string title;
            std::cin >> title;
            setTitle(title);

            std::cout << "Enter Author Name : ";
            std::string name;
            std::cin >> name;
            setAuthorName(name);

            std::cout << "How many pages : ";
            int count;
            std::cin >> count;
            setNumOfPages(count);

            std::vector<std::string> bookContent;
            for (int i {1}; i <= count; i++) {
                std::cout << "Enter page #" << i << " : ";
                std::string content;
                std::cin >> content;
                bookContent.push_back(content);
            }
            setContent(bookContent);

            return;
        }
};

#endif