#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <vector>
#include "LibraryBook.h"

using namespace std;


int main() {
    vector <LibraryBook> LibraryBooks;

    string str;
    ifstream fin("/Users/sogent/CLionProjects/lab6---classes-sogent/books.txt");
   while(!fin.eof()) {
       getline(fin, str);
       string title = str;



       getline(fin, str);
       string author = str;

       getline(fin, str);
       string ISBN = str;



       LibraryBook myBooks(title, author, ISBN);

       LibraryBooks.push_back(myBooks);
   }
   fin.close();

    string str3;
    ifstream fin3("/Users/sogent/CLionProjects/lab6---classes-sogent/books.txt");
    while(!fin3.eof()) {
        getline(fin3, str3);
        string title = str3;



        getline(fin3, str3);
        string author = str3;

        getline(fin3, str3);
        string ISBN = str3;




    }
    fin3.close();


    string newStr;
    vector<string> listISBN;
   ifstream fin2("/Users/sogent/CLionProjects/lab6---classes-sogent/isbns.txt");
   while(!fin2.eof()){
       getline(fin2, newStr);
       string theISBN;
       theISBN=newStr;
        cout<<theISBN<<endl;

        listISBN.push_back(theISBN);
   }
   fin2.close();


    int checkInOutCount=0;
    for(int i=0;i<LibraryBooks.size();++i) {
        for (int j = 0; j < listISBN.size(); ++j) {
            if (LibraryBooks.at(i).GetISBN() == listISBN.at(j)) {
                checkInOutCount += 1;
                cout << LibraryBooks.at(i).GetTitle() << endl;

                if(checkInOutCount%2==0){
                    LibraryBooks.at(i).CheckIn();
                }else{
                    LibraryBooks.at(i).CheckOut();
                }

            }
        }
    }



cout<<"****"<<endl;
    for(int i=0;i<LibraryBooks.size();++i) {
        if(LibraryBooks.at(i).isCheckedOut()){
            cout<<LibraryBooks.at(i).GetTitle()<<endl;
            cout<<"checked out"<<endl;
        }else{
            cout<<LibraryBooks.at(i).GetTitle()<<endl;
            cout<<"checked in"<<endl;
        }
    }


    ofstream fout("checkout.csv");
    while(fout.is_open()){
        for(int i=0;i<LibraryBooks.size();++i) {
            if(LibraryBooks.at(i).isCheckedOut()){
                //fout<<"\""<<"\"";
                //fout<<"\""<<LibraryBooks.at(i).GetTitle()<<"\","<<"\""<<LibraryBooks.at(i).GetAuthor()<<"\","<<"\""<<LibraryBooks.at(i).GetISBN()<<"\"";
                fout<<LibraryBooks.at(i).GetTitle()<<",";
                cout<<LibraryBooks.at(i).GetTitle();
                cout<<",";

            }
        }


        fout.close();
    }


	return 0;

}