#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;

} *start = NULL;
void radix_sort();
int large_dig();
int digit(int number, int k);
main()
{

    struct node *tmp, *q;
    int i, n, item;
    printf("Enter the number of elements in the list : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {

        printf("Enter element %d : ", i + 1);
        scanf("%d", &item);
        tmp = malloc(sizeof(struct node));
        tmp->info = item;
        tmp->link = NULL;
        if (start == NULL)
            start = tmp;
        else
        {

            q = start;
            while (q->link != NULL)
                q = q->link;

            q->link = tmp;
        }
    }
    radix_sort();
    printf("Sorted list is :\n");
    q = start;
    while (q != NULL)
    {

        printf("%d ", q->info);
        q = q->link;
    }
    printf("\n");
}
void radix_sort()
{

    int i, k, dig, least_sig, most_sig;
    struct node *p, *rear[10], *front[10];
    least_sig = 1;
    most_sig = large_dig(start);
    for (k = least_sig; k <= most_sig; k++)
    {

        for (i = 0; i <= 9; i++)
        {
            rear[i] = NULL;
            front[i] = NULL;
        }
        for (p = start; p != NULL; p = p->link)
        {
            dig = digit(p->info, k);
            if (front[dig] == NULL)
                front[dig] = p;

            else

                rear[dig]->link = p;

            rear[dig] = p;
        }

        i = 0;
        while (front[i] == NULL)

            i++;
        start = front[i];
        while (i < 9)
        {

            if (rear[i + 1] != NULL)

                rear[i]->link = front[i + 1];

            else

                rear[i + 1] = rear[i];

            i++;
        }
        rear[9]->link = NULL;
    }
}
int large_dig()
{

    struct node *p = start;
    int large = 0, ndig = 0;
    while (p != NULL)
    {

        if (p->info > large)

            large = p->info;

        p = p->link;
    }
    while (large != 0)
    {
        ndig++;
        large = large / 10;
    }
    return (ndig);
}
int digit(int number, int k)
{
    int digit, i;
    for (i = 1; i <= k; i++)
    {

        digit = number % 10;
        number = number / 10;
    }
    return (digit);
}
