#include "doublelist.h"
#include "my_data.h"
#include "my_data2.h"

void createList(List &L) {
    /**
    * FS : set first(L) with Null
    */
    //-------------your code here-------------
    first(L) = NULL;
    last(L) = NULL;
    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : return new list element with info = x and next element is Null
    */
    //-------------your code here-------------
    address P = new elmlist;
    info(P) = x;
    prev(P) = NULL;
    next(P) = NULL;
    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : delete element pointed by P
    */
    //-------------your code here-------------
    delete (P);
    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the first element in List L
    */
    //-------------your code here-------------
    if (first(L) == NULL && last(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the last element in List L
    */
    //-------------your code here-------------
    if (first(L)==NULL && last(L)==NULL){
        first(L) = P;
        last(L) = P;
    }else{
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }

    //----------------------------------------
}

address findElm(List L, infotype x) {
    /**
    * IS : List L may be empty
    * FS : returns element with info.ID = x.ID,
           return Null if such ID is not found
    */

    address P;
    //-------------your code here-------------
    if (first(L) != NULL) {
        address P = first(L);
        while ((next(P) != NULL) && (info(P).id != x.id)) {
            P = next(P);
        }
        if (info(P).id == x.id) {
            return P;
        }
        else {
            return NULL;
        }
    }
    //----------------------------------------
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L may be empty
    * FS : first element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    if (first(L) == NULL && last(L) == NULL){
        cout<<"list kosong";
    }else{
        P = first(L);
        if(prev(P)== next(P)){
            P = first(L);
            prev(P) = NULL;
            next(P) = NULL;
            first(L) = NULL;
            last(L) = NULL;
        }else
            first(L) = next(P);
            prev(P) = NULL;
            next(P) = NULL;
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L may be empty
    * FS : last element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    if (first(L)== NULL && last(L) == NULL){
        cout<<"list kosong";
    }else{
        P = last(L);
        if(prev(P) == next(P)){
            prev(P) = NULL;
            next(P) = NULL;
            first(L) = NULL;
            last(L) = NULL;
        }else{
        last(L) = prev(P);
        prev(P) = NULL;
        next(P) = NULL;
        }
    }
    //----------------------------------------
}

void printInfo(List L) {
    /**
    * FS : view info of all element inside List L,
    *      call the view_data function from my_data.h to print the info
    */
    //-------------your code here-------------
    address P;
    if(first(L) == NULL && last(L) == NULL){
        cout<<"list kosong";
    }else{
        P = first(L);
        while(prev(P) != last(L)){
            view_data(info(P));
            cout<<endl;
            P = next(P);
        }
        view_data(info(P));
            cout<<endl;
    }
    //----------------------------------------
}

void insertAfter(List &L, address Prec, address P) {
    /**
    * IS : Prec and P is not NULL
    * FS : element pointed by P is placed behind the element
    *      pointed by pointer Prec
    */
    //-------------your code here-------------
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
    prev(next(P)) = P;
    //----------------------------------------

}
void deleteAfter(List &L, address Prec, address &P) {
    /**
    * IS : Prec is not NULL
    * FS : element which was before behind an element pointed by Prec
    *      is removed and pointed by pointer P
    */
    //-------------your code here-------------
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
    //----------------------------------------
}

