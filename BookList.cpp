/ Pepper Berry
// Date: 1/8/2024
// BookList.cpp
// Purpose: book list's member functions


#include eam>
#include ream>
#include ing>
#include "BookList.h"
#include dc++.h>

using namespace std;

BookList::BookList(){//constructor
    books = 0;
    capacity = 20;
    list = new Book[capacity];

}

void BookList::addBook(string writer, string name, string date){
    cout <<"";
    if(books == (capacity-1)){
        expand();
    }
    list[books].author = writer;
    list[books].title = name;
    list[books].year = date;
    books++;
    list[(books-1)].ISBN = books;


}

void BookList::addBook(){
    if(books == (capacity-1)){
        expand();
    }
    cout<<"Enter the author of the new book: ";

    getline(cin, list[books].author);
    cout << "Enter the title of the new book: ";
    getline(cin, list[books].title);
    cout <<"Enter the year (or range of years) of the new book:";
    getline(cin, list[books].year);
    //cout<
    books++;
    list[(books-1)].ISBN = books;

    cout << getBookISBN((books-1))<<", "<< getBookAuthor((books-1))<<", "<<getBookTitle((books-1))
    <<", "<<getBookYear((books-1))<<" was added."<<endl<<endl;

}
int BookList::getBookISBN(int num) const{
    return list[num].ISBN;
}
string BookList::getBookAuthor(int num) const{
    return list[num].author;
}

string BookList::getBookTitle(int num) const{
    return list[num].title;
}

string BookList::getBookYear(int num) const{
    return list[num].year;
}

int BookList::getBookListSize() const{
    return books;
}

BookList::~BookList(){
    delete [] list;
}



void BookList::expand(){//makes book bigger
    capacity++;
    Book * temp = new Book[capacity];//this can be changed depending on how many times we want tot call this function

    for(int i = 0; i < (books); i++){
        temp[i] = list[i];
    }
    delete [] list;
    list = temp;
}

void BookList::addFile(){
    string line;
    string FILENAME;
    string author;
    string title;
    string year;

    //gets file
    cout << "Enter books file:";
    //cin >> FILENAME;
    FILENAME = "books.txt";

    ifstream inputFile(FILENAME);//problem line

    //opening and reading the file

    if(inputFile){
        while(getline(inputFile, line)) {
            //const char* str = line.data();

            char* word = strtok(const_cast<char*>(line.data()), ",");// the author
            author = word;

            word = strtok(NULL, ",");//the title
            title = word;


            word = strtok(NULL, ",");//the year
            year = word;

            addBook(author, title, year);//adds that book


        }
    }else{
        cout <<"Error: cannot open file"<<endl;
    }


    //closing the file
    inputFile.close();

}


