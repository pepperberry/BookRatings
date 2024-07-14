//by: Pepper Berry
//date: 1/8/2024





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
