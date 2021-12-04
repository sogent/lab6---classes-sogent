//
// Created by Sarah Ogent on 11/14/21.
//
#include <iostream>
#include "LibraryBook.h"
using namespace std;

//default constructor
LibraryBook::LibraryBook(){
    title="";
    author="";
    ISBN="";
    checkedOut=false;
}

//constructor
LibraryBook::LibraryBook(string bookTitle, string bookAuthor, string bookISBN){
    title=bookTitle;
    author=bookAuthor;
    ISBN=bookISBN;
    checkedOut=false;
}

string LibraryBook::GetTitle(){
    return title;
}

string LibraryBook::GetAuthor(){
    return author;
}

string LibraryBook::GetISBN(){
    return ISBN;
}

bool LibraryBook::CheckOut(){
    checkedOut=true;
}
bool LibraryBook::CheckIn(){
    checkedOut=false;
}
bool LibraryBook::isCheckedOut(){
    return checkedOut;
}

