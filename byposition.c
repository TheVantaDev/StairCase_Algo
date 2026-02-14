#include "common.h"
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
