// Pepper Berry
// Date: 1/8/2024
// MemberList.cpp
// Purpose: book list's member functions


#include eam>
#include ream>
#include ing>
#include "MemberList.h"
#include dc++.h>

using namespace std;

MemberList::MemberList(){//constructor
   members = 0;
   capacity = 20;
   list = new Member[capacity];
   current = 0;

}

void MemberList::addMember(string person){
   cout <<"";
   if(members == (capacity-1)){
      expand();
   }
   list[members].name = person;
   members++;
   list[(members-1)].account = members;


}

void MemberList::addMember(){
   if(members == (capacity-1)){
      expand();
   }
   cout<<"Enter the name of the new member: ";
   getline(cin, list[members].name);
   members++;
   list[(members-1)].account = members;

   cout << list[(members-1)].name << " (account #: "<<list[(members-1)].account<<") was added."<<endl<<endl;

}

void MemberList::login() {
   cout << "Enter member account: ";
   cin >> current;
   cin.ignore();
   cout << getMemberName((current-1))<<", you are logged in!"<<endl<<endl;

}

void MemberList::logout() {
   current = 0;
}

bool MemberList::isCurrent(int num) {
   return (current == num);
}

int MemberList::getMember() const{
   return current;
}

int MemberList::getMembers() const{
   return members;
}

string MemberList::getMemberName(int num) const{
   return list[num].name;
}

void  MemberList::expand(){//makes book bigger
   capacity++;
   Member * temp = new Member[capacity];//this can be changed depending on how many times we want tot call this function

   for(int i = 0; i < (members); i++){
      temp[i] = list[i];
   }
   delete [] list;
   list = temp;
}

MemberList::~MemberList(){
    delete [] list;
}


void MemberList::addFile(){

}
