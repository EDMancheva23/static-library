#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
    double price;
};

struct Library {
    string name;
    Book* books;
    int count;
    int capacity;
};

Book createBook(const string& title, const string& author, int year, double price);
void printBook(const Book& book);
void initLibrary(Library& library, const string& name);
void freeLibrary(Library& library);
void addBookToLibrary(Library& library, const Book& book);
void printLibrary(const Library& library);
double averageBookPrice(const Library& library);
Book oldestBookInLibrary(const Library& library);