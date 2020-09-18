//
// Created by sharon on 9/18/20.
//

#include <stdio.h>
#include "books.h"
#include <stdlib.h>
#include "functionsOnBookList.h"
#define BOOK_SIZE (20)



int main() {

    extern struct book books[BOOK_SIZE];
    extern int interalExist(int userInteralNum);
    int serialNum;
    int userChoose;
    bool borrow;
    struct bookCopy *myBookCopy;
    struct bookCopy **booksCopy;
    int allocate;

    for (int i = 0; i < BOOK_SIZE; i++) {
        print_book(&books[i]);
    }

    do_for_books(books, BOOK_SIZE, (void (*)(Book *)) &print_non_fiction);
    printf("Print book list nicely\n");
    do_for_books(books, BOOK_SIZE, (void (*)(Book *))&print_nicely);
    printf("Most Promoted:\n");
    do_for_books(books, BOOK_SIZE,(void (*)(Book *)) &print_most_promoted);

    printf("Minimal promotion: %d\n",get_min_promotion(books,BOOK_SIZE));
    printf("Mnimal factor: %f\n",get_min_thrilling_factor(books,BOOK_SIZE));




    printf("how many Book-copies to allocate?\n");
    scanf("%d", &allocate);
    booksCopy = malloc(sizeof(struct bookCopy *) *(long unsigned int) allocate);

    for (int i = 0; i < allocate; i++) {
        int userInteralNum;
        printf("Enter an interal number of a book copy\n");
        scanf("%d", &userInteralNum);
        if (interalExist(userInteralNum))
            booksCopy[i] = create_copy(userInteralNum);
        else
            do {
                printf("Enter a valid number\n");
                scanf("%d", &userInteralNum);
            } while (!interalExist(userInteralNum));
    }

    do {
        printf("1. Borrow a book-copy\n2. Return a book-copy\n9. Exit\n");
        scanf("%d", &userChoose);
        if (userChoose == 1 || userChoose == 2) {
            printf("enter the book-copy’s serial\n");
            scanf("%d", &serialNum);
            myBookCopy = getBookCopyBySerialNum(serialNum, booksCopy, allocate);
            while(myBookCopy==0)
            {
                printf("The input is not valid, Enter again\n");
                scanf("%d", &serialNum);
                myBookCopy = getBookCopyBySerialNum(serialNum, booksCopy, allocate);
            }
            if (userChoose == 1) {
                myBookCopy->borrowing_times = realloc(myBookCopy->borrowing_times, sizeof(size_t));
                myBookCopy->borrowing_times[myBookCopy->lastIndexOfBorrowing++] = time(0);
                borrow = true;
            } else
                borrow = false;

            if (borrow_copy(myBookCopy, borrow) == -1)
                printf("The action could not be happend\n");

        } else if (userChoose != 9)
            printf("The input is not valid\n");
    }while (userChoose!=9);
    printf("goodBye\n");

    //free

    for (int i = 0; i < allocate; i++) {
        free(booksCopy[i]->borrowing_times);
        freeBookCopy(booksCopy[i]);
    }
    free(booksCopy);
    return 0;
}