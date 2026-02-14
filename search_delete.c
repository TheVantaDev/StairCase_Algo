#include "common.h"
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
}
