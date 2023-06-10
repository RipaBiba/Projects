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


struct treeNode * searchItem(struct treeNode * node, int item)
{
    //Solve using recursion
    if(node->item == item) return node;
    if(node == 0) return 0;
    if(item < node->item) return searchItem(node->left,item);
    else return searchItem(node->right,item);
};

struct treeNode * searchPrev(struct treeNode * node,int item)
{
    // Return the parent node of the item using recursion
    if(node->item == item) return 0;
    if(node->left != 0 && node->left->item == item) return node;
    if(node->right != 0 && node->right->item == item) return node;
    if(item>node->item) return searchPrev(node->right,item);
    else return searchPrev(node->left,item);
};

struct treeNode * makeTreeNode(int item)
{
    struct treeNode * node ;
    node = (struct treeNode *)malloc(sizeof(struct treeNode));
    node->item = item;
    node->left = 0;
    node->right = 0;
    return node;
};

struct treeNode * insertItem(struct treeNode * node, int item)
{
    // Insert item in the tree using recursion
    if(node == 0) return makeTreeNode(item);
    if(item >= node->item) node->right = insertItem(node->right,item);
    else node->left = insertItem(node->left,item);
    return node;
}

int maximum(int a,int b)
{
    if(a>b) return a;
    else return b;
}

int calcNodeHeight(struct treeNode * node)
{
    // return height (maximum distance from node to leaf + 1) using recursion
    int leftH=0,rightH=0;
    if (node ==0) return -1;
    else
    {
        if(node->left!=0)leftH = calcNodeHeight(node->left);
        if(node->right!=0)rightH = calcNodeHeight(node->right);
       /* if(rightH > leftH) return (rightH+1);
        else return (leftH+1);*/
        return maximum(leftH,rightH)+1;
    }
}


int calcHeight(int item) //return height of an item in the tree
{
    // return height of an item using calcNodeHeight function
    struct treeNode *temp =root;
    struct treeNode *temp1;
    int leftH=0,rightH=0;
    if (temp ==0) return 0;
    if(item == temp->item) return calcNodeHeight(temp)-1;
    else
    {
        if(item<temp->item){
            temp1 = temp->left;
            if(item == temp1->item) return calcNodeHeight(temp1)-1;
            if(item < temp1->item) return calcNodeHeight(temp1->left)-1;
            else return calcNodeHeight(temp1->right)-1;
            free(temp1);
        }
        if(item>temp->item){
            temp1 = temp->right;
            if(item == temp1->item) return calcNodeHeight(temp1)-1;
            if(item < temp1->item) return calcNodeHeight(temp1->left)-1;
            else return calcNodeHeight(temp1->right)-1;
            free(temp1);
        }
    }
}

int getSize(struct treeNode * node)
{
    // return size of the tree with node(argument) as root using recursion
    if(node == 0) return 0;
    else return(getSize(node->left)+1+getSize(node->right));
}

int calcNodeDepth(struct treeNode * node)
{
    //calculate depth of level of a node using recursion
    int leftH=0,rightH=0;
    if (node ==0) return 0;
    else
    {
        if(node->left!=0)leftH = calcNodeDepth(node->left);
        if(node->right!=0)rightH = calcNodeDepth(node->right);
        return maximum(leftH,rightH)+1;
    }
}

struct treeNode *findLCA(struct treeNode *node,int item1,int item2)
{
    //Find lowest common ancestors of item1 and item2 using recursion
    if(node == 0) return 0;
    else if(item1 > node->item && item2 > node->item)
    {
        return findLCA(node->right,item1,item2);
    }
    else if(item1 < node->item && item2 < node->item)
    {
        return findLCA(node->left,item1,item2);
    }
    else return node;
}

int calcDepth(int item)
{
    //Return depth or level of an item using calcNodeDepth function
    struct treeNode *temp =root;
    struct treeNode *temp1;
    int leftH=0,rightH=0;
    if (temp ==0) return 0;
    if(item == temp->item) return 0;
    else
    {
        if(item<temp->item){
            temp1 = temp->left;
            if(item == temp1->item) return calcNodeDepth(temp1)-1;
            if(item < temp1->item) return calcNodeDepth(temp1->left)+1;
            else return calcNodeDepth(temp1->right)+1;
        }
        if(item>temp->item){
            temp1 = temp->right;
            if(item == temp1->item) return calcNodeDepth(temp1)-1;
            if(item < temp1->item) return calcNodeDepth(temp1->left)+1;
            else return calcNodeDepth(temp1->right)+1;
        }
    }

}


struct treeNode *deleteItem(struct treeNode * node, int item)
{
    //write your code from previous assignment here, you do not need to implement using recursion
    struct treeNode *temp = node;
    struct treeNode *temp1,*temp2,*temp3;
    if(temp==0) return temp;
    if(item>temp->item)
    {
        temp->right = deleteItem(temp->right,item);
    }
    if(item<temp->item)
    {
        temp->left = deleteItem(temp->left,item);
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
            temp->right = deleteItem(temp->right,temp3->item);
            return temp;
        }
    }
    return temp;
}


int getMinItem(struct treeNode * node)
{
    //return the minimum item in the tree using recursion
    if(node->left == 0) return node->item;
    else getMinItem(node->left);
}

int getMaxItem(struct treeNode * node)
{
    //return the maximum item in the tree using recursion
    if(node->right == 0) return node->item;
    else getMaxItem(node->right);
}

int rangeSearch(struct treeNode * node, int leftBound, int rightBound)
{
    //returns number of items in the range of leftBound and rightBound using recursion
    if(node == 0) return 0;
    if(leftBound > node->item) return rangeSearch(node->right,leftBound,rightBound);
    if(leftBound <= node->item && rightBound >= node->item)
    {
        return 1+rangeSearch(node->left,leftBound,rightBound)+rangeSearch(node->right,leftBound,rightBound);
    }
    if(rightBound < node->item) return rangeSearch(node->left,leftBound,rightBound);
}

int findInOrderSuccessor(int item)
{
    //return In order successor of the item in the tree (You need not use recursion)
    struct treeNode *temp = root;
    struct treeNode *temp1=0;
    //while(1)
    if(temp == 0)
    {
        return 0;
    }
    if(temp->item == item)
    {
        temp1 = temp->right;
        if(temp1->left == 0) temp->item = temp1->item;
        while(temp1->left!=0)
        {
            temp1 = temp1->left;
        }
        temp->item = temp1->item;
        temp->right = temp1;
        return temp->right->item;
    }
    if(item < temp->item)
    {
        temp1 = temp;
        temp = temp->left;
        if(item == temp->item) return temp->right->item;
        else if(item < temp->item)
        {
            temp = temp->left;
            return temp1->left->item;
        }
        else if(item > temp->item)
        {
            temp = temp->right;
            return temp1->item;
        }
    }
    else
    {
        temp1 = temp;
        temp = temp->right;
        if(item == temp->item) return temp->right->item;
        else if(item < temp->item)
        {
            temp = temp->left;
            return temp1->left->item;
        }
        else if(item > temp->item)
        {
            temp = temp->right;
            return 0;
        }
    }
}

void printInOrder(struct treeNode * node, int height)
{
    if(node==0) return;
    //print left sub-tree
    printInOrder(node->left, height-1);
    //print item
    for(int i=0;i<height;i++)printf("   ");
    printf("\t%d\n",node->item);
    //print right sub-tree
    printInOrder(node->right, height-1);
}

void printPreOrder(struct treeNode * node, int height)
{
    //Write your code using recursion to print the tree in pre-order
    if(node==0) return;
    //print item
    for(int i=0;i<height;i++)printf("   ");
    printf("\t%d\n",node->item);
    //print left sub-tree
    printPreOrder(node->left, height-1);
    //print right sub-tree
    printPreOrder(node->right, height-1);
}

void printPostOrder(struct treeNode * node, int height)
{
    //Write your code using recursion to print the tree in post-order
    if(node==0) return;
    //print left sub-tree
    printPreOrder(node->left, height-1);
    //print right sub-tree
    printPreOrder(node->right, height-1);
    //print item
    for(int i=0;i<height;i++)printf("   ");
    printf("\t%d\n",node->item);
}

int main(void)
{
    initializeTree();
    while(1)
    {
        printf("\n");
        printf("_____ MENUE _____");
        printf("\n1.Insert Item.\n2.Search Parent.\n3.Search Item.");
        printf("\n4.Print Height of Tree.\n5.Print height of an Item.");
        printf("\n6.Print InOrder.\n7.Print PreOrder.\n8.Print PostOrder.");
        printf("\n9.Print depth of an Item.\n10.Print Size of Tree.\n11.Get Minimum.\n12.Get Maximum.");
        printf("\n13.Delete Item.\n14.Range Search.\n15.Find LCA.\n16.Find InOrder Successor.\n17.Print depth of Tree.\n18.Exit.\n");
        int ch;
        printf("Enter your Choice: ");
        scanf("%d",&ch);
        printf("\n");
        if(ch==1)
        {
            int item;
            printf("Enter Item: ");
            scanf("%d", &item);
            root = insertItem(root, item);
        }
        else if(ch==2)
        {
            int item;
            printf("Enter Item: ");
            scanf("%d", &item);
            struct treeNode * res = searchPrev(root, item);
            if(res==0) printf("No parent found.\n");
            else printf("Parent of %d is : %d\n",item,res->item);
        }
        else if(ch==3)
        {
            int item;
            printf("Enter Item: ");
            scanf("%d", &item);
            struct treeNode * res = searchItem(root, item);
            if(res!=0) printf(" %d Found.\n",item);
            else printf(" %d not Found.\n");
        }
        else if(ch==4)
        {
            int height = calcNodeHeight(root);
            printf("Height of the Tree is: %d\n", height);
        }
        else if(ch==5)
        {
            int item;
            scanf("%d", &item);
            int height = calcHeight(item);
            printf("Height of %d is: %d\n", item, height);
        }
        else if(ch==6)
        {
            int h = calcNodeHeight(root);
            printf("_____ Tree InOrder _____");
            printf("\n-----------------------------\n");
            printInOrder(root,h);
            printf("-----------------------------\n");
        }
        else if(ch==7)
        {
            int h = calcNodeHeight(root);
            printf("_____ Tree PreOrder _____");
            printf("\n-----------------------------\n");
            printPreOrder(root, h);
            printf("-----------------------------\n");
        }
        else if(ch==8)
        {
            int h = calcNodeHeight(root);
            printf("_____ Tree PostOrder _____");
            printf("\n-----------------------------\n");
            printPostOrder(root,h);
            printf("-----------------------------\n");
        }
        else if(ch==9)
        {
            int item;
            printf("Enter Item: ");
            scanf("%d", &item);
            int depth = calcDepth(item);
            printf("Depth of %d is: %d\n", item, depth);
        }
        else if(ch==10)
        {
            printf("Size of tree is : %d\n",getSize(root));
        }
        else if(ch==11)
        {
            printf("The Minimum item of Tree is: %d\n",getMinItem(root));
        }
        else if(ch==12)
        {
            printf("The Maximum item of Tree is: %d\n",getMaxItem(root));
        }
        else if(ch==13)
        {
            int item;
            printf("Enter Item: ");
            scanf("%d",&item);
            struct treeNode *func = deleteItem(root,item);
            if(func!=0) printf(" %d Deleted Successfully\n",item);
            else printf("Item is not Present in the Tree");
        }
        else if(ch==14)
        {
            int leftBound,rightBound;
            printf("Enter Left Bound: ");
            scanf("%d",&leftBound);
            printf("Enter Right Bound: ");
            scanf("%d",&rightBound);
            int num = rangeSearch(root,leftBound,rightBound);
            printf("Range value: %d\n",num);
        }
        else if(ch==15)
        {
            int item1,item2;
            printf("Enter One Item: ");
            scanf("%d",&item1);
            printf("Enter Another Item: ");
            scanf("%d",&item2);
            struct treeNode *lca = findLCA(root,item1,item2);
            printf("LCA of %d and %d is: %d\n",item1,item2,lca->item);
        }
        else if(ch==16)
        {
            int item;
            printf("Enter Item: ");
            scanf("%d",&item);
            int n = findInOrderSuccessor(item);
            printf("InOrder Successor of %d is: %d\n",item,n);
        }
        else if(ch==17)
        {
            int d = calcNodeDepth(root)-1;
            printf("Depth of Tree is: %d\n",d);
        }
        else if(ch==18)
        {
            break;
        }
    }
}


