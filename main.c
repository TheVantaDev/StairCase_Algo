#include "common.h"
Node *head=NULL;
Node *back=NULL;
int cnt=1;
#include "insert_create.c"
#include "byposition.c"
#include "search_delete.c"
#include "display.c"
int main()
{
    create(10);
    create(20);
    create(30);
    create(40);
    create(60);
    display(head);
    printf("\n");
    displayfar(head);
    printf("\n");
    search(10);
    deletebyposn(2);
    // delete(20);
    printf("\n");
    printf("below is deleted");
        printf("\n");


    display(head);
    return 0;
}
