//
// Created by sharon on 9/13/20.
//
#include "books.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

extern bool interalExist(int userInteralNum);
static char *s[] = {"KIDS", "HIGHSCHOOL", "ADULT", "DOCUMENTARY", "COMICS"};
/************************************************BOOK*******************************************************/



static void print_genre(Book *myBook) {
    switch (myBook->genreType)
    {
        case DRAMA  :  /* access bar.foo.a;*/
        {
            printf("genre: DRAMA; ");
            printf("plot quality: %d; ",myBook->GenreData.drama.plotQuality);
            printf("text quality: %d\n",myBook->GenreData.drama.textQuality);
            break;
        }
        case THRILLER :
        {
            printf("genre: THRILLER; ");
            printf("thrilling factor: %f\n",myBook->GenreData.thriller.thrillingFactor);
            break;
        }
        case COMEDY:
        {
            printf("genre: COMEDY; ");
            printf("humor quality: %d; ",myBook->GenreData.comedy.humorQuality);
            printf("humor type: %c\n",myBook->GenreData.comedy.humorType);
            break;
        }
        case NON_FICTION:
        {
            printf("genre: NON_FICTION; ");
            printf("field: %s; \n",myBook->GenreData.nonFiction.field);
            break;
        }
    }
}
char* get_zone_name(Zone zoneType) {
    if(zoneType<= FIRST_ZONE || zoneType>=LAST_ZONE)
        return 0;
    return s[zoneType-1];
}

void print_book(Book* myBook){
    printf("name: %s, interal nunber: %d, promotion: %d, zone type: %s, ",
           myBook->name,myBook->interalNumber,myBook->promotion,get_zone_name(myBook->zoneType));
    print_genre(myBook);
}

void get_nice_book_name(const char* src,char* dst){
    strcpy(dst, src);
    if(dst[0]!='\n') {
        dst[0] = (char) toupper(dst[0]);
        for (int i = 1; dst[i] != 0; i++)
            if (dst[i-1]==' ')
                dst[i]=(char)toupper(dst[i]);
            else
                dst[i]=(char)tolower(dst[i]);
    }

}

void print_non_fiction( Book const* b){
   if(b->genreType==NON_FICTION)
       printf("name: %s, field: %s\n",b->name,b->GenreData.nonFiction.field);
   else
        printf("---\n");
}

void print_nicely(Book const * b){
    char* st=malloc(sizeof(b->name));
    get_nice_book_name( b->name,st);
    printf("%s\n",st);
    free(st);
}

void print_most_promoted( Book const* b){
    if(b->promotion>50)
        printf("%d\n",b->promotion);
}


/************************************************BOOK COPY*******************************************************/


void print_copy(BookCopy* myBookCopy){
    printf("interal nunber: %d, serial number: %d, is_borrowed: %s ,conditions: %s\n",
           myBookCopy->interalNum,myBookCopy->serialNum,myBookCopy->is_borrowed ? "true" : "false", myBookCopy->conditions ? "true" : "false");
    for (int i=0; i<myBookCopy->lastIndexOfBorrowing;i++)
    {
        struct tm *tm = localtime(&(myBookCopy->borrowing_times[i]));
        printf("%s", asctime(tm));
        printf("%s",(const char *) myBookCopy->borrowing_times[i]);
    }
}
int borrow_copy(BookCopy* myBookCopy,bool b){
    if(myBookCopy->is_borrowed==b)
        return -1;
    else
        myBookCopy->is_borrowed=!b;
    return 0;
}

void init_copy(BookCopy* myBookCopy,int interalNum){
    int static serialNumbers=10000;
    myBookCopy->interalNum=interalNum;
    myBookCopy->serialNum=serialNumbers++;
    myBookCopy->is_borrowed=false;
    myBookCopy->borrowing_times=0;
    myBookCopy->lastIndexOfBorrowing=0;
    myBookCopy->conditions=0;
    //serialNumbers++;
}

bool is_librarian_required(BookCopy* myBookCopy){
    if((myBookCopy->conditions&LIBRARIAN)!=0)
        return true;
    return false;
}
bool is_bookbinder_required(BookCopy* myBookCopy){
    if((myBookCopy->conditions&BOOKBINDER)!=0)
        return true;
    return false;
}
bool is_repairable(BookCopy* myBookCopy){
    if((myBookCopy->conditions&REPAIRABLE)==0)
        return true;
    return false;
}

bool is_ok(BookCopy* myBookCopy){
    if(myBookCopy->conditions==0)
        return true;
    return false;
}
bool is_useless(BookCopy* myBookCopy){
    if(myBookCopy->conditions>=15)
        return true;
    return false;
}
bool are_in_same_condition(BookCopy* myBookCopy1,BookCopy* myBookCopy2){
    if(myBookCopy1->conditions==myBookCopy2->conditions)
        return true;
    return false;
}

BookCopy* create_copy(int interal){
    if(!interalExist(interal))
        return 0;
    BookCopy* bc=malloc(sizeof(BookCopy));
    init_copy(bc,interal);
    return bc;
}

void freeBookCopy(BookCopy* bc){
    free(bc);
}