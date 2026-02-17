#include <stdio.h>
#include <stdlib.h>
// #define k 4
#include <math.h>
int k=4;
int size=0;
int numLevels=1;
typedef struct Node
{
   int val;
   struct Node *next;
   struct Node *far;
   //not one but staring with one only
}Node;
Node *head=NULL;
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
void updateK()
{   
//     k=(int)sqrt(size);
//     if(k<2) k=2;
   if(size>0)
   {
    k=4;
    if(k<2) k=2;
   }
}
int leveldefine()
{
    if(size<=1) return 1;
    return (int) ceil(log(size)/log(k))+1;
}
//creating node deeply
void create(int val)
{ if(head==NULL)
    {
        head=insert(val);
        back=head;
        // cnt++;
        size=1;
    }
    else{    
                cnt++;
                size++;
        Node *temp=head;
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
    Node * temp=head;
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

    Node *curr=temp;
    while(curr!= NULL)
    {
        if(curr->val==val)
        {
            printf("found at tail\n");
            return;
        }
        curr = curr->next;
    }

    printf("element not found\n");
}
//remember last node should not be pointed by far because after deletion we gonna assign far pointer to it's next.
void delete(int val)
{     if(head==NULL)
    {
        printf("Element not there ");
        return ;
    }
    while(head!=NULL && head->val==val)
    {
        Node *del=head;
        head=head->next;
        size--;
        free(del);
        printf("delted head node properly ");
        return ;
    }
       Node *temp=head;
    Node *prev=NULL;
    while(temp->far!=NULL && temp->far->val<val)
    {
        prev=temp;
        temp=temp->far;
    }
    //if far node and delte node is same at the time
    if(temp->far!=NULL && temp->far->val==val)
    { Node * del=temp->far;
        temp->far=del->far;
        temp->next=del->next;
        free(del);
        size--;
        printf("Node delted successfully");
        return;
    }
    //finded block now searching in block before tail means a last one if not found go ahead
    Node *curr=temp->next;
    prev=temp;
    Node *stop=temp->far;
    while(curr!=stop)
    {
        if(curr->val==val)
        {
            prev->next=curr->next;
            free(curr);
            printf("Node delted done");
            return;
        }
        prev=curr;
        curr=curr->next;
    }
//last tail
 curr=temp->far;
prev=temp->far ?temp->far:prev;
while(curr!=NULL)
{
    if(curr->val==val)
    {
        prev->next=curr->next;
        free(curr);
        printf("Node delted done I think");
        return;
    }
    prev=curr;
    curr=curr->next;
}
printf("Element not found I believe");
size--;
}
void deletebyposn(int pos)
{ Node *temp=head;
    if(pos==0)
    {
        Node *del=head;
        head=head->next;
        free(del);
        return ;
    }
    else{
        int c=pos/k;
        int d=0;
        // checking how many nodes we have travelled using d means in pos if we are at 5 then one node travelled after that we have to search
        while(c>0)
        {
            temp=temp->far;
            c--;
            d++;
        }
        Node *too=temp;
        //searching in block means did division and searching in betn blocks
        // 1--->2-->3 so searching betn 2 and 3
        Node *prev=NULL;
        prev=temp;
        d=k*d;
    //   if(too->far!=NULL)
    //   {
        too=too->far;
        while(temp!=too && d!=pos)
        {   prev=temp;
            temp=temp->next;
            d++;
        }
        prev->next=temp->next;
        free(prev);

    //   }
      //if we reach last far node then we have to search betn last far node to that pointer become null
      // 1-->2-->3----- here we have to search after 3 right  
    //   else{
    //     while(temp!=NULL)
    //     {

    //     }

    //   }

        

    }

}

void searchbyposn(int pos)
{  int c=pos/k;
    Node * temp=head;
    int d=0;
    while(c>0)
    { temp=temp->far;
      c--;
      d++;
    }
    d=d*k;
    while(d!=pos)
    { temp=temp->next;
        d++;
    }
    printf("node found");
}
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
int main()
{
    create(10);
    create(20);
    create(30);
    create(40);
    display(head);
    printf("\n");
    displayfar(head);
    printf("\n");
    search(60);
    deletebyposn(1);
    // delete(20);
    printf("\n");
    printf("below is deleted");
        printf("\n");

    display(head);
    return 0;
}