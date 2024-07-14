//by: Pepper Berry
//date: 1/8/2024





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
