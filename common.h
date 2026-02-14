#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <stdlib.h>
#define k 4
typedef struct Node
{
   int val;
   struct Node *next;
   struct Node *far;
   //not one but staring with one only
}Node;
extern Node *head;
extern Node *back;
extern int cnt;
#endif
