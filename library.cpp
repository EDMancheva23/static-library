#include "library.h"
#include <limits>
#include <stdexcept>

Book createBook(const string& title, const string& author, int year, double price) {
    Book book;
    book.title = title;
    book.author = author;
    book.year = year;
    book.price = price;
    return book;
}

void printBook(const Book& book) {
    cout << "Заглавие: " << book.title << endl;
    cout << "Автор: " << book.author << endl;
    cout << "Година: " << book.year << endl;
    cout << "Цена: " << book.price << " лв." << endl;
    cout << "------------------------" << endl;
}

void initLibrary(Library& library, const string& name) {
    library.name = name;
    library.count = 0;
    library.capacity = 10;
    library.books = new Book[library.capacity];
}

void freeLibrary(Library& library) {
    delete[] library.books;
    library.books = nullptr;
    library.count = 0;
    library.capacity = 0;
}

void addBookToLibrary(Library& library, const Book& book) {
    if (library.count >= library.capacity) {
        int newCapacity = library.capacity * 2;
        Book* newBooks = new Book[newCapacity];
        for (int i = 0; i < library.count; i++) {
            newBooks[i] = library.books[i];
        }
        delete[] library.books;
        library.books = newBooks;
        library.capacity = newCapacity;
    }
    library.books[library.count] = book;
    library.count++;
}

void printLibrary(const Library& library) {
    cout << "================================" << endl;
    cout << "БИБЛИОТЕКА: " << library.name << endl;
    cout << "Брой книги: " << library.count << endl;
    cout << "================================" << endl;
    for (int i = 0; i < library.count; i++) {
        cout << "Книга #" << (i + 1) << endl;
        printBook(library.books[i]);
    }
}

double averageBookPrice(const Library& library) {
    if (library.count == 0) {
        return 0.0;
    }
    double total = 0.0;
    for (int i = 0; i < library.count; i++) {
        total += library.books[i].price;
    }
    return total / library.count;
}

Book oldestBookInLibrary(const Library& library) {
    if (library.count == 0) {
        throw runtime_error("Библиотеката е празна!");
    }
    int oldestIndex = 0;
    for (int i = 1; i < library.count; i++) {
        if (library.books[i].year < library.books[oldestIndex].year) {
            oldestIndex = i;
        }
    }
    return library.books[oldestIndex];
}