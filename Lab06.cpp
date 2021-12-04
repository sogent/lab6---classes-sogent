#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <vector>
#include "LibraryBook.h"

using namespace std;

string remove_r(const string& s)
{
    int last = s.size() - 1;
    while (last >= 0 && s[last] == '\r')
        --last;
    return s.substr(0, last + 1);
}


int main() {
    vector <LibraryBook> LibraryBooks;
    string str;
    ifstream fin1("/Users/sogent/CLionProjects/lab6---classes-sogent/books.txt");
   while(!fin1.eof()) {
       getline(fin1, str);
       string title = str;


       getline(fin1, str);
       string author = str;

       getline(fin1, str);
       string ISBN = str;


       LibraryBook myBooks(title, author, ISBN);
       LibraryBooks.push_back(myBooks);
   }
   fin1.close();


    string newStr;
    vector<string> listISBN;
   ifstream fin2("/Users/sogent/CLionProjects/lab6---classes-sogent/isbns.txt");
   while(!fin2.eof()){
       getline(fin2, newStr);
       string theISBN;
       theISBN=newStr;

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
    cout<<"****"<<endl;


    ofstream fout("checkout.csv");
    while(fout.is_open()){
        for(int i=0;i<LibraryBooks.size();++i) {
            if(LibraryBooks.at(i).isCheckedOut()){

                fout<<"\""<<remove_r(LibraryBooks.at(i).GetTitle())<<"\""<<",";
                fout<<"\""<<remove_r(LibraryBooks.at(i).GetAuthor())<<"\""<<",";
                fout<<"\""<<remove_r(LibraryBooks.at(i).GetISBN())<<"\""<<endl;


                cout<<"\""<<remove_r(LibraryBooks.at(i).GetTitle())<<"\""<<",";
                cout<<"\""<<remove_r(LibraryBooks.at(i).GetAuthor())<<"\""<<",";
                cout<<"\""<<remove_r(LibraryBooks.at(i).GetISBN())<<"\""<<endl;



            }
        }


        fout.close();
    }


	return 0;

}