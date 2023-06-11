#include "book.hpp"
#include <string>
#include <iostream>
#include <map>
#include <vector>

Book::Book() {
    title = authorName = "";
    isbn =  numOfPages = -1;
}

void Book::setISBN(int isbn_) {
    isbn = isbn_;
}

void Book::setTitle(std::string title_) {
    title = title_;
}

void Book::setAuthorName(std::string authorName_) {
    authorName = authorName_;
}

void Book::setNumOfPages(int numOfPages_) {
    numOfPages = numOfPages_;
}

void Book::setContent(const std::vector<std::string>& pagesToContent_) {
        for (auto& content : pagesToContent_)
            pagesToContent.push_back(content);
}

// Getters

int Book::getISBN() const {
    return isbn;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthorName() const {
    return authorName;
}

int Book::getNumOfPages() const {
    return numOfPages;
}

const std::vector<std::string>& Book::getContent() const{
    return pagesToContent;
}

// Other

void Book::print() {
    std::cout << "\n" << "ISBN : " << getISBN()
        << "\n" << "Title : " << getTitle()
        << "\n" << "Author : " << getAuthorName()
        << "\n" << "Number of Pages : " << getNumOfPages() << "\n";
}

void Book::readBook(int isbn) {
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