//by: Pepper Berry
//date: 1/8/2024

//Load external data-driver program should be able to be done before class called will call many classes
//Add new member-Member list
//Add new book- book list
//Login-Member list
//Logout-Member list
//View all your own ratings
//Rate book
//See recommended books
//Quit-driver program should be able to be done outside of a class



#include ream>

using namespace std;


#ifndef BOOKLIST_H
#define BOOKLIST_H

class  BookList{
   public:
      BookList();
      ~BookList();
      void addBook(string, string, string);//for automatic entry
      void addBook();//for user entry
      int getBookISBN(int) const;
      string getBookAuthor(int) const;
      string getBookTitle(int) const;
      string getBookYear(int) const;
      int getBookListSize() const;
      void addFile();


   private:
        struct Book{
            string author;
            string title;
            int ISBN;
            string year;
         };
         Book * list;
         int books;
         int capacity;
         void expand();


};

#endif
