//
// Created by sharon on 9/13/20.
//
#include <stdbool.h>
#include <time.h>

#ifndef LIBRARYPROJECT_BOOKS_H
#define LIBRARYPROJECT_BOOKS_H

typedef enum zone{ FIRST_ZONE,KIDS, HIGHSCHOOL, ADULT, DOCUMENTARY, COMICS,LAST_ZONE} Zone;
//typedef enum mask{LIBRARIAN=0x000b,BOOKBINDER=0x0034,REPAIRABLE=0x0024} Mask;
typedef enum mask{LIBRARIAN=((1<<1)|(1<<2)|(1<<4)),BOOKBINDER=((1<<3)|(1<<5)|(1<<6)),REPAIRABLE=((1<<3)|(1<<6))} Mask;
typedef enum genre{DRAMA, THRILLER,COMEDY, NON_FICTION}Genre;


//extern const struct book;
typedef struct drama{
    unsigned char textQuality;
    unsigned char plotQuality;
}Drama;

typedef struct thriller{
    float thrillingFactor;
}Thriller;

typedef struct comedy{
    unsigned short humorQuality;
    char humorType;
}Comedy;

typedef struct non_fiction{
    char field[5];
}Non_fiction;

typedef struct book
{
    int interalNumber;
    char name[50];
    int promotion;
    enum zone zoneType;
    enum genre genreType;
    union genreData
    {
        Drama drama;
        Thriller thriller;
        Comedy comedy;
        Non_fiction nonFiction;
    }GenreData;
}Book;

typedef struct bookCopy
{
    int interalNum;
    int serialNum;
    bool is_borrowed;
    time_t* borrowing_times;
    int lastIndexOfBorrowing;
    int conditions;
}BookCopy;


/***************book functions*******************************************/



char* get_zone_name(enum zone);
void print_book(Book*);
void get_nice_book_name(const char*,char*);
void print_nicely(Book const  *);
void print_non_fiction(Book const *);
void print_most_promoted(Book const *);

/***************bookCopy functions*******************************************/


int borrow_copy(BookCopy*,bool ); //returns 0 when the change was happend, else returns -1

void print_copy(BookCopy*);
void init_copy(BookCopy*,int);

bool is_librarian_required(BookCopy*);
bool is_bookbinder_required(BookCopy*);
bool is_repairable(BookCopy*);
bool is_ok(BookCopy*);
bool is_useless(BookCopy*);
bool are_in_same_condition(BookCopy*,BookCopy*);

BookCopy* create_copy(int);
void freeBookCopy(BookCopy*);

#endif //LIBRARYPROJECT_BOOKS_H
