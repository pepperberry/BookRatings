// Pepper Berry
// Date: 1/8/2024
// RatingList.cpp



#include eam>
#include ream>
#include ing>
#include "RatingList.h"
#include dc++.h>

using namespace std;

bool RatingList::mostFavorites(int user, int other) const{
    int favs = 0;
    for(int j = 0; j < ratingCapacity; ++j){
        if(list[(other-1)][j] != 0 && list[(user-1)][j] == 0){
            ++favs;
        }       
    }
    if(favs < 5){
        return false;
    }else{
        return true;
    }
}

int RatingList::mostLike(int user) const{
    int similar = 0;
    int score = 0;
    int comptUser;

    for(int i =0; i < memberCapacity; ++i){//finds most compatible person
        if(i != (user-1)){
            score = 0;
            for(int j = 0; j < ratingCapacity; ++j){
                if(list[(user-1)][j] != 0){
                    score += (list[i][j] x list[(user-1)][j]);
                }
                
            }
            score = abs(score);
            if(score > similar){
                similar = score;
                comptUser = (i + 1);

            }
        }
    }

}

int RatingList::ViewRating(int user, int isbn) const{
    return list[user][(isbn-1)];
}

RatingList::addRating(int user, int isbn, int rate){
    list[user][(isbn-1)]= rate;
}

void RatingList::addRating(int user){
    int isbn;
    int rate;
    
    cout<<"Enter the ISBN for the book you'd like to rate: "<<endl;
    cin>> isbn
    cout<<"Enter your rating: "<<endl;
    list[user][(isbn-1)]= rate;
    //add info in driver for this fuction

}

void RatingList::RatingList(int members, int books){
   memberCapacity = members;
   ratingCapacity = books;
   list = new int*[memberCapacity];
   for(int i = 0; i < memberCapacity; ++i){
      list[i] = new int[ratingCapacity];
      for(int j = 0; j < ratingCapacity; ++j){
        list[i][j] = 0;
      }
   }
}

RatingList::~RatingList(){
    for(int i = 0; i < memberCapacity; ++i){
        delete[] list[i];
    }
    delete [] list;
}

void RatingList::expandRatings(){
   ratingCapacity++; 
   int * temp = new int[ratingCapacity];
   for(int i = 0; i <  memberCapacity; ++i){

      for(int j = 0; j < ratingCapacity; ++j){
        temp[j] = list[i][j];
      }
      delete[] list[i];
      list[i] = temp;

    }
}

void RatingList::expandMembers(){
   memberCapacity++;

   int * temp = new int*[ratingCapacity];

   for(int i =0 ; i < memberCapacity; ++i){
      temp[i] = list[i];
    }

    for(int i = 0; i < memberCapacity; ++i){
        delete[] list[i];
    }

    delete [] list;

    list = temp;
}
