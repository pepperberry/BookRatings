//by: Pepper Berry
//date: 1/8/2024

//Load external data-driver program should be able to be done before class called will call many classes
//Add new member-Member list
//Add new book
//Login-Member list
//Logout-Member list
//View all your own ratings
//Rate book
//See recommended books
//Quit-driver program should be able to be done outside of a class




#include ream>

using namespace std;


#ifndef MEMBERLIST_H
#define MEMBERLIST_H

class  MemberList{
   public:
      MemberList();
      ~MemberList();

      void addMember();//add via user input
      void addMember(string);//add automatically
      int getMember() const;//gets account num to use with other classes
      string getMemberName(int) const;
      int getMembers() const;
      void login();
      void logout();
      bool isCurrent(int);
      void addFile();
   private:
     int members;//number of members
     struct Member{
            string name;
            int account;//account number
      };
      Member * list;
      int capacity;
      int current;//the current member
      void expand();
};

#endif
