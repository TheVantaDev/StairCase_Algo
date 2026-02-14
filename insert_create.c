#include "common.h"
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
{ if(head==NULL)
    {
        head=insert(val);
        back=head;
        // cnt++;
    }
    else{
                cnt++;
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
