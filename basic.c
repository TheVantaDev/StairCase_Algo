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
Node *root=NULL;
int cnt=1;
Node *insert(int val)
{
    Node *ptr=(Node *)malloc(sizeof(Node));
    ptr->val=val;
    ptr->next=NULL;
    return ptr;
}
//creating node deeply
void create(int val)
{ if(root==NULL)
    {
        root=insert(val);
        // cnt++;
    }
    else{
        Node *temp=root;
        Node *back=root;
        while(temp->next!=NULL)
        {  temp=temp->next;
        }
        cnt++;
        if(cnt==k)
        {
            cnt==0;
            back->far=temp;
            back=temp;
        }
        temp->next=insert(val);
    }

}
void display(Node *root)
{ while (root!=NULL)
{
   printf("%d->",root->val);
    root=root->next;
} 
}
void displayfar(Node *root)
{  while (root!=NULL)
{
printf("%d----->",root->val);
root=root->far;
}
}


void main()
{
    create(10);
    create(20);
    create(30);
    create(40);
    display(root);
    printf("\n");
    displayfar(root);
}