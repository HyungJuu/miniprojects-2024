/* 
    File : project02_ver2.h

    Created : 24-03-27
    Author : 김근아
*/
#ifndef PROJECT_VER2_H
#define PROJECT_VER2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200

typedef struct NODE // 구조체 생성 -> 필드
{
    int rental;
    int booknum;
    int bookcount;
    char publisher[SIZE];
    char title[SIZE];
    char author[SIZE];
    struct NODE *next;
} node;

node* bookAdd(node*);
void bookSearch(node*);
node* bookDelete(node*);
void bookShow(node*);
int bookSearchPrint();
void search_T(node*);
void search_A(node*);
void search_P(node*);
node* bookRental(node*, int);
node* bookReturn(node*, int);
void rentalselect(node*);

#endif