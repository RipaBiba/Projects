#include<stdio.h>
#include<stdlib.h>

#define FALSE_VALUE 0
#define TRUE_VALUE 1

struct treeNode
{
    int item;
    struct treeNode * left; //points to left child
    struct treeNode * right; //points to right child
};

struct treeNode * root;


void initializeTree()
{
    root = 0;
}

/****** Complete the following functions using Loop ******/
struct treeNode * searchItem(int item)
{
    // return the treeNode holding the item
    struct treeNode *temp = root;
    if(temp == 0) return 0;
    while(temp!=0)
    {
        if(temp->item == item) return temp;
        else if(item > temp->item) temp = temp->right;
        else temp = temp->left;
    }
    return temp;

};

int insertItem(int item)
{
    //If success return TRUE_VALUE, else return FALSE_VALUE
       struct treeNode *newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
       //newNode = root;
       newNode->item = item;
       newNode->right = 0;
       newNode->left = 0;
       struct treeNode *temp = root;
       if(temp == 0){
            root = newNode;
           // return temp;
       }
       else{
            while(temp!=0)
            {
                if(item >= temp->item)
                {
                    if(temp->right == 0)
                    {
                        temp->right = newNode;
                        break;
                   }
                    temp = temp->right;
                }
                else
                {
                    if(temp->left == 0)
                    {
                        temp->left = newNode;
                        break;
                    }
                    temp = temp->left;
                }
            }
       }
       //return temp->item;
}

struct treeNode *deleteItem(int item)
{
    //If success return TRUE_VALUE, else return FALSE_VALUE
    struct treeNode *temp = root;
    struct treeNode *temp1,*temp2,*temp3;
    if(temp==0) return temp;
    if(item>temp->item)
    {
        //temp->right = deleteItem(temp->right,item);
        temp1 = temp->right;
        temp->right = temp1->right;
        free(temp1);
        return temp;
    }
    if(item<temp->item)
    {
        //temp->left = deleteItem(temp->left,item);
        temp1 = temp->left;
        temp->left = temp1->left;
        free(temp1);
        return temp;
    }
    else
    {
        /*** CASE 01 ***/
        if(temp->left == 0 && temp->right == 0)
        {
            free(temp);
            temp = 0;
            return temp;
        }
        /*** CASE 02 ***/
        else if(temp->left == 0 || temp->right == 0)
        {
            if(temp->right == 0)
            {
                temp2 = temp;
                temp = temp->left;
                free(temp2);
                return temp;
            }
            else if(temp->left == 0)
            {
                temp2 = temp;
                temp = temp->right;
                free(temp2);
                return temp;
            }
        }
        /*** CASE 03 ***/
        else
        {
            temp3 = temp->right;
            if(temp3->left == 0) temp->item = temp3->item;
            while(temp3->left!=0)
            {
                temp3 = temp3->left;
            }
            temp->item = temp3->item;
            //temp->right = deleteItem(temp->right,temp3->item);
            temp->right = temp3->right;
            free(temp3);
            return temp;
        }
    }
    return temp;
}

int calcLevel(int item)
{
    //return level/depth of an item in the tree
    int c = 0;
    struct treeNode *temp=root;
    if(temp == 0) return 0;
    while(temp!=0)
    {
        if(item == temp->item) return c;
        else if(item>temp->item)
        {
            ++c;
            temp = temp->right;
        }
        else
        {
            ++c;
            temp = temp->left;
        }
    }
    return c;
}

int getMinItem() // return the minimum item in the tree
{
    struct treeNode *temp = root;
    if(temp->left == 0) return temp->item;
    while(temp->left!=0)
    {
        temp = temp->left;
    }
    return temp->item;
}

int getMaxItem() // return the maximum item in the tree
{
    struct treeNode *temp = root;
    if(temp->right == 0) return temp->item;
    while(temp->right!=0)
    {
        temp = temp->right;
    }
    return temp->item;

}
void printInOrder(struct treeNode *node)
{
    if(node==0) return;
    printInOrder(node->left);
    printf("\t%d\n",node->item);
    printInOrder(node->right);
}
int main(void)
{
    initializeTree();
    while(1)
    {
        printf("\n");
        printf("_____ MENU _____");
        printf("\n1.Insert Item.\n2.Delete Item.\n3.Search Item.");
        printf("\n4.Print level of an Item. ");
        printf("\n5.Get Minimum.\n6.Get Maximum ");
        printf("\n7.Print InOrder.\n8.Exit.\n");

        int ch;
        printf("Enter your Choice: ");
        scanf("%d",&ch);
        printf("\n");
        if(ch==1)
        {
            int item;
            printf("Enter Item: ");
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            printf("Enter Item: ");
            scanf("%d", &item);
            deleteItem(item);
            printf("%d Deleted Successfully\n",item);
        }
        else if(ch==3)
        {
            int item;
            printf("Enter Item: ");
            scanf("%d", &item);
            struct treeNode * res = searchItem(item);
            if(res!=0) printf(" %d Found.\n",item);
            else printf(" %d not Found.\n",item);
        }
        else if(ch==4)
        {
            int item;
            printf("Enter Item: ");
            scanf("%d", &item);
            int level = calcLevel(item);
            printf("Level of %d is %d\n",item,level);
        }
        else if(ch==5)
        {
            printf("Minimum value of Tree is %d\n",getMinItem());
        }
        else if(ch==6)
        {
            printf("Maximum value of tree is %d\n",getMaxItem());
        }
        else if(ch==7)
        {
           printf("_____ Tree InOrder _____");
           printf("\n-----------------------------\n");
           printInOrder(root);
           printf("-----------------------------\n");
        }
        else if(ch==8)
        {
            break;
        }
    }
}

