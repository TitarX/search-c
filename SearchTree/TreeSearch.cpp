#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 50

typedef struct tree
{
        int a;
        int index_tree;
        struct tree *left;
        struct tree *right;
}TREE;

TREE*add_to_tree(TREE*,int,int);
TREE*tree(int[],int);
int searchTree(TREE*,int);

int main()
{
        srand(time(NULL));
        clrscr();

        int mas[SIZE];
        TREE*treeSearch;
        int value;
        int index;

        for(int i=0;i<SIZE;i++)
        {
                mas[i]=rand()%10;
                printf("%d ",mas[i]);
                if(!((i+1)%10))
                {
                        printf("\n");
                }

        }
        printf("\n");

        treeSearch=tree(mas,SIZE);

        printf("Vvedite iskomoe znachenie: ");
        scanf("%d",&value);
        index=searchTree(treeSearch,value);
        if(index+1)
        {
                printf("\nIskomoe znachenie nahoditsya v yacheyke s indeksom %d\n",index);
        }
        else
        {
                printf("\nIskomoe znachenie ne naydeno\n");
        }

        getchar();
        getchar();
        return 0;
}

TREE*add_to_tree(TREE*root,int new_value,int i)
{
        if (root==NULL)
        {
                root=(TREE*)malloc(sizeof(TREE));
                root->a=new_value;
                root->index_tree=i;
                root->left=root->right=0;
                return root;
        }
        if (root->a<new_value)
        {
                root->right=add_to_tree(root->right,new_value,i);
        }
        else
        {
                root->left=add_to_tree(root->left,new_value,i);
        }
        return root;
}

TREE*tree(int mas[],int elem_total)
{
        TREE*root;
        int i;
        root=NULL;
        for (i=0;i<elem_total;i++)
        {
                root=add_to_tree(root,mas[i],i);
        }
        return root;
}

int searchTree(TREE*root,int value)
{
        int index=-1;

        while(root!=NULL)
        {
                if(root->a==value)
                {
                        index=root->index_tree;
                        break;
                }
                else
                {
                        if(root->a<value)
                        {
                                root=root->right;
                        }
                        else
                        {
                                root=root->left;
                        }
                }
        }

        return index;
}


