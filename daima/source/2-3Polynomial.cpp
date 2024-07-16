#include <stdio.h>
#include <stdlib.h>
typedef struct List{
    float coef;
    int expn;
    struct List *next;
}List;
void CreatList(List *&p, int n)
{
    List *s, *q, *pre;
    p = (List *)malloc(sizeof(List));
    p->next = NULL;

    for(int i = 0; i < n; i++)
    {
        s = (List *)malloc(sizeof(List));
       scanf("%f",&s->coef) ;
       scanf("%d",&s->expn);
        pre = p;
        q = p->next;
        while(q && q->expn < s->expn)
        {
            pre = q;
            q = q->next;
        }
        s->next = q;
        pre->next = s;
    }
}
void AddList(List *pa, List *pb)
{
    List *p1 = pa->next, *p2 = pb->next, *p3 = pa, *r;
    while(p1 && p2)
    {
        if(p1->expn == p2->expn)
        {
            float sum = p1->coef + p2->coef;
            if(sum != 0)
            {
                p1->coef = sum;
                p3 = p1;
                p1 = p1->next;
                r = p2;
                p2 = p2->next;
                free(r);
            }
            else
            {
                r = p1;
                p1 = p1->next;
                free(r);
                r = p2;
                p2 = p2->next;
                free(r);
            }
        }
        else if(p1->expn < p2->expn)
        {
            p3->next = p1;
            p3 = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
        }
    }
    p3->next = p1 ? p1 : p2;
    free(pb);
}
int main()
{
    List *pa, *pb, *p;
    int n;
    scanf("%d", &n);
    CreatList(pa, n);
    CreatList(pb, n);
    AddList(pa, pb);
    p = pa->next;
    while(p->next)
    {
        printf("%0.f*x^%d+", p->coef, p->expn);
        p = p->next;
    }
     printf("%0.f*x^%d", p->coef, p->expn);
    return 0;
}