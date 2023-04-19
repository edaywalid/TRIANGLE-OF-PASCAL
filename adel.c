#include <stdio.h>
#include <stdlib.h>
typedef struct node* Liste;
typedef struct node
{
    int data;
    Liste next;

}node;


void print (Liste head){

    while (head != NULL){
        printf("%d  ",head->data);
        head = head->next;
    }
}
Liste pascal(Liste tete, Liste tete2){

    Liste p = tete2;
    while (tete->next != NULL)
    {
        p->next = malloc(sizeof(node));
        p = p->next;
        p->data = tete->data + (tete->next)->data;
        tete = tete->next;
    }
    p->next = malloc(sizeof(node));
    p->next->data= 1;
    return tete2;
}


    
int main(){
    Liste T[100];
    for (int i = 0; i < 100; i++)
    {
        T[i] = NULL;
    }
    
    for (int i = 0; i < 100; i++)
    {  
        T[i] = malloc ( sizeof (node));
        T[i]->data = 1;
        T[i]->next= NULL;
    }
    int N ;
    printf("enter how many lines u want to get :");
    scanf("%d",&N);

    printf("1\n");
    for (int  i = 0; i < N; i++)
    {
        print(pascal(T[i],T[i+1]));
        printf("\n\n\n");

    }
    
    


    
}
    
