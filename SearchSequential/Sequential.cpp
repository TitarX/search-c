#include<stdio.h>
#include<conio.h>

#define SIZE 50

int sequentialSearch(int[],int,int);

int main()
{
        clrscr();

        int index,value;
        int mas[SIZE];

        for(int i=0;i<SIZE;i++)
        {
                mas[i]=i+10;
                printf("%d ",mas[i]);
                if(!((i+1)%10))
                {
                        printf("\n");
                }
        }
        printf("\n");

        printf("Vvedite iskomoe znachenie: ");
        scanf("%d",&value);
        index=sequentialSearch(mas,SIZE,value);
        if(index+1)
        {
                printf("\nIskomoe znachenie nahoditsya v yacheyke s indeksom: %d\n",index);
        }
        else
        {
                printf("\nIskomoe znachenie ne naydeno\n");
        }

        getchar();
        getchar();
        return 0;
}

int sequentialSearch(int mas[],int n,int value)
{
        int index=-1;
        for(int i=0;i<n;i++)
        {
                if(mas[i]==value)
                {
                        index=i;
                        break;
                }
        }
        return index;
}

