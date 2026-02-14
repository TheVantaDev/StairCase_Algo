#include "common.h"
void display(Node *head)
{ while (head!=NULL)
{
   printf("%d->",head->val);
    head=head->next;
} 
}
void displayfar(Node *head)
{  while (head!=NULL)
{
printf("%d----->",head->val);
head=head->far;
}
}
