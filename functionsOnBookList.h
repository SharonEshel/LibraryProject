//
// Created by sharon on 9/17/20.
//

#ifndef LIBRARYPROJECT_FUNCTIONSONBOOKLIST_H
#define LIBRARYPROJECT_FUNCTIONSONBOOKLIST_H
#include "books.h"

int get_min_promotion(Book books[],int length);
float get_min_thrilling_factor(Book books[],int length);
BookCopy* getBookCopyBySerialNum(int ,BookCopy * [],int );
void do_for_books(Book * books, int num, void (*f)(Book *));



#endif //LIBRARYPROJECT_FUNCTIONSONBOOKLIST_H
