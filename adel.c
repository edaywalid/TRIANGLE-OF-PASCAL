#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node *Liste;
typedef struct node
{
    int data;
    Liste next;

} node;

void print(Liste head)
{

    while (head != NULL)
    {
        printf("%d  ", head->data);
        head = head->next;
    }
}
Liste pascal(Liste tete, Liste tete2)
{

    Liste p = tete2;
    while (tete->next != NULL)
    {
        p->next = malloc(sizeof(node));
        p = p->next;
        p->data = tete->data + (tete->next)->data;
        tete = tete->next;
    }
    p->next = malloc(sizeof(node));
    p->next->data = 1;
    return tete2;
}

void F(Liste T[], int N, int nb)
{
    int i = 0;
    bool found = false;
    if (nb == 1)
    {
        i = 0;
    }
    else
    {
        i = 1;
        while (i < N && !found)
        {
            Liste p = T[i];
            while (p != NULL)
            {
                if (p->data < nb)
                {
                    p = p->next;
                }
                else
                {
                    found = true;
                    break;
                }
            }
            T[i] = pascal(T[i], T[i + 1]);
            i++;
        }
    }

    for (int j = 0; j < i - 1; j++)
    {
        print(T[j]);
        pascal(T[j], T[j + 1]);
        printf("\n\n");
    }
}

void Liberer(Liste T[], int N)
{
    for (int i = 0; i < N; i++)
    {
        Liste p = T[i];
        while (p != NULL)
        {
            Liste temp = p;
            p = p->next;
            free(temp);
        }
    }
}

void construire(Liste T[], int nbLIGNE)
{
    for (int i = 0; i < nbLIGNE; i++)
    {
        print(T[i]);
        pascal(T[i], T[i + 1]);
        printf("\n\n");
    }
}
int main()
{
    int N;
    printf("enter the number of lines :");
    scanf("%d", &N);
    Liste T[N + 1];
    for (int i = 0; i < N + 1; i++)
    {
        T[i] = NULL;
    }

    for (int i = 0; i < N + 1; i++)
    {
        T[i] = malloc(sizeof(node));
        T[i]->data = 1;
        T[i]->next = NULL;
    }
    
    
    printf("\n\nyour whole triangle :\n\n");
    construire(T, N);
    Liberer(T, N);
    for (int i = 0; i < N + 1; i++)
    {
        T[i] = malloc(sizeof(node));
        T[i]->data = 1;
        T[i]->next = NULL;
    }
    
    int X;
    printf("which number u want to stop in :");
    scanf("%d", &X);
    F(T, N, X);

    Liberer(T, N);

    return 0;
}
