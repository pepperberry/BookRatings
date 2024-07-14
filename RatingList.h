//by: Pepper Berry

//date: 1/8/2024





#include eam>
#include ream>
#include ing>
#include "RatingList.h"
#include dc++.h>

using namespace std;


#ifndef RATINGLIST_H
#define RATINGLIST_H

class  RatingList{
   public:
      RatingList(int, int);
      ~RatingList();
      void addRating(int, int, int);//for adding automatically
      void addRating(int);//for adding by user
      void ViewRating(int, int) const;//helps see all your ratings per book
      int mostLike(int) const;//finds the person closes to you
      bool mostFavorites(int, int) const; //find the amount of books to display at 3 level
      void addFile();
   private:
      int **list;
      int memberCapacity;
      int ratingCapacity;
      void expandRatings();
      void expandMembers();
};


#endif
