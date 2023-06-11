#include "book.hpp"
#include <string>
#include <iostream>
#include <map>
#include <vector>

Book::Book() {
    title = authorName = "";
    isbn =  numOfPages = -1;
}

void Book::setISBN(int isbn) {
    this->isbn = isbn;
}

void Book::setTitle(std::string title) {
    this->title = title;
}

void Book::setAuthorName(std::string authorName) {
    this->authorName = authorName;
}

void Book::setNumOfPages(int numOfPages) {
    this->numOfPages = numOfPages;
}

void Book::setContent(std::vector<std::string> pagesToContent) {
    for (int i {numOfPages}; i > 0; i--){
        this->pagesToContent[i] = pagesToContent.back();
        pagesToContent.pop_back();
    }
}

// Getters

int Book::getISBN() {
    return isbn;
}

std::string Book::getTitle() {
    return title;
}

std::string Book::getAuthorName() {
    return authorName;
}

int Book::getNumOfPages() {
    return numOfPages;
}

std::map<int, std::string> Book::getContent() {
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