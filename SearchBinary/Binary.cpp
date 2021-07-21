//Массив для поиска должен быть отсортирован по возрастанию

#include<stdio.h>
#include<conio.h>

#define SIZE 50

int binarySearch(int[],int,int);

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
        index=binarySearch(mas,SIZE-1,value);
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

int binarySearch(int mas[],int e,int value)
{
        int b=0,i;
        int index=-1;
        do
        {
                i=(b+e)/2;
                if(mas[i]==value)
                {
                        index=i;
                        break;
                }
                else
                {
                        if(value<mas[i])
                        {
                                e=i-1;
                        }
                        else
                        {
                                b=i+1;
                        }
                }
        }
        while(b<=e);
        return index;
}

