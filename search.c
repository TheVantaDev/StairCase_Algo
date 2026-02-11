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
Node *back=NULL;
int cnt=1;
Node *insert(int val)
{
    Node *ptr=(Node *)malloc(sizeof(Node));
    ptr->val=val;
    ptr->next=NULL;
    ptr->far=NULL;
    return ptr;
}
//creating node deeply
void create(int val)
{ if(root==NULL)
    {
        root=insert(val);
        back=root;
        // cnt++;
    }
    else{
                cnt++;
        Node *temp=root;
        while(temp->next!=NULL)
        {  temp=temp->next;
        }
        if(cnt==k)
        {
            cnt=1;
            back->far=temp;
            back=temp;
        }
        temp->next=insert(val);
    }

}
void search(int val)
{
    Node * temp=root;
    while(temp->far!=NULL)
    {
        if(temp->far->val < val)
        {
            temp=temp->far;
        }
        else if(temp->far->val==val)
        {
            printf("element found at far node\n");
            return;
        }
        else
        {
            Node *curr = temp;
            while(curr != temp->far)
            {
                if(curr->val == val)
                {
                    printf("element found in block\n");
                    return;
                }
                curr = curr->next;
            }
            break;
        }
    }

    Node *curr = temp;
    while(curr != NULL)
    {
        if(curr->val == val)
        {
            printf("found at tail\n");
            return;
        }
        curr = curr->next;
    }

    printf("element not found\n");
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


int main()
{
    create(10);
    create(20);
    create(30);
    create(40);
    display(root);
    printf("\n");
    displayfar(root);
    printf("\n");
    search(60);
    return 0;
}