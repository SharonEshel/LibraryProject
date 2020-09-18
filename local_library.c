//
// Created by sharon on 9/15/20.
//
#include "books.h"

    struct book books[] = {
        {1001, "Sun Don't Shine",                      40,   ADULT,DRAMA,{.drama={50,55}}},
        {1002, "Irma la dos",                          -100, DOCUMENTARY,THRILLER,{.thriller={0.5}}},
        {1003, "Starship Troopers: Invasion",          -68,  KIDS,COMEDY,{.comedy={200,'N'}}},
        {1004, "Year of the Jellyfish",                5,    ADULT,NON_FICTION,{.nonFiction={"CHEM"}}},
        {1005, "After Life",                           -95,  DOCUMENTARY,DRAMA,{.drama={70,75}}},
        {1006, "Rest Stop",                            20,   HIGHSCHOOL,THRILLER,{.thriller={1}}},
        {1007, "Wuthering Heights",                    56,   KIDS,COMEDY,{.comedy={200,'N'}}},
        {1008, "New Adventures of Pippi Longstocking", 11,   HIGHSCHOOL,NON_FICTION,{.nonFiction={"HIST"}}},
        {1009, "She Does Not Drink, Smoke or Flirt",   23,   KIDS,DRAMA,{.drama={20,25}}},
        {1010, "F.I.S.T.",                             97,   HIGHSCHOOL,THRILLER,{.thriller={1.5}}},
        {1011, "Cruise",                               -97,  HIGHSCHOOL,COMEDY,{.comedy={600,'S'}}},
        {1012, "Letter to Elia, A",                    54,   KIDS,NON_FICTION,{.nonFiction={"MUSC"}}},
        {1013, "To Be and to Have",                    -57,  ADULT,DRAMA,{.drama={90,95}}},
        {1014, "Get Hard",                             -66,  HIGHSCHOOL,THRILLER,{.thriller={2}}},
        {1015, "A Nation's Battle for Life",           51,   ADULT,COMEDY,{.comedy={700,'P'}}},
        {1016, "Place Called Chiapas",                 76,   COMICS,NON_FICTION,{.nonFiction={"CHEM"}}},
        {1017, "A Drama of the Wilderness",            55,   COMICS,DRAMA,{.drama={30,35}}},
        {1018, "Ladies Man",                           46,   ADULT,THRILLER,{.thriller={2.5}}},
        {1019, "Film Geek",                            -100, COMICS,COMEDY,{.comedy={900,'O'}}},
        {1020, "Raining Stones",                       -83,  DOCUMENTARY,NON_FICTION,{.nonFiction={"MUSC"}}}
};


    const struct book* startBooks(){
    return &books[0];
}

int bookLength(){
    return sizeof(books)/sizeof(struct book);
}

bool interalExist(int userInteralNum){
        for(int i=0;i<bookLength();i++)
            if(books[i].interalNumber==userInteralNum)
                return true;
        return false;
    }



