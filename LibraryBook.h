//
// Created by Sarah Ogent on 11/14/21.
//
#include <iostream>
using namespace std;

#ifndef LAB6_CLASSES_SOGENT_LIBRARYBOOK_H
#define LAB6_CLASSES_SOGENT_LIBRARYBOOK_H
class LibraryBook{
public:
    //default constructor
    LibraryBook();

    LibraryBook(string bookTitle, string bookAuthor, string bookISBN);

    //getters
    string GetTitle();

    string GetAuthor();

    string GetISBN();

    bool CheckOut();
    bool CheckIn();
    bool isCheckedOut();


private:
    string title;
    string author;
    string ISBN;
    bool checkedOut;
};
#endif //LAB6_CLASSES_SOGENT_LIBRARYBOOK_H
