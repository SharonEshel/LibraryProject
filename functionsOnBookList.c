//
// Created by sharon on 9/17/20.
//

#include "functionsOnBookList.h"
//#include "books.h"
#define MIN(a,b) ((a) < (b) ? (a) : (b))


int get_min_promotion(Book books[],int length)
{
    int minPromotion=100;
    for(int i=0;i<length;i++){
        minPromotion=MIN(minPromotion,books[i].promotion);
    }
    return minPromotion;
}

float get_min_thrilling_factor(Book books[],int length)
{
    float minFactor=5;
    for(int i=0;i<length;i++){
        if(books[i].genreType==THRILLER)
            minFactor=MIN(minFactor,books[i].GenreData.thriller.thrillingFactor);
    }
    return minFactor;
}

BookCopy* getBookCopyBySerialNum(int serial,BookCopy * booksCopy[],int length){
    for(int i=0;i<length;i++)
        if(booksCopy[i]->serialNum==serial)
            return booksCopy[i];
    return 0;
}

void do_for_books(Book const * books, int num, void (*f)(Book const *)){
    for (int i=0; i<num; i++)
        (*f)(&books[i]);
}