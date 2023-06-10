#include <bits/stdc++.h>
#include <string.h>
#include<stdio.h>
#define MaxSize 50


int i;
/*******STACK********/
class StackTools
{
public:
    struct ToolsNode
    {
        int month,date,year,ToolsNumber;
//            string ToolsName,ToolsCategory,BuyerName,SellerName;
        char ToolsName[MaxSize],ToolsCategory[MaxSize],BuyerName[MaxSize],SellerName[MaxSize];
        float SellingPrice,BuyingPrice;
        ToolsNode *previous;
    };
    ToolsNode *Tools;
public:

    StackTools()
    {
        ToolsNode *product1,*product2;
        Tools = NULL;
        product1 = Tools;
        while(product1 != NULL)
        {
            product2 = product1;
            product1 = product1->previous;
            product2->previous = NULL;
            delete product2;
        }
    }
    // void pushDetails(string ToolsName,string ToolsCatagory,double SellingPrice,double BuyingPrice,string BuyerName,string SellerName,int month,int date,int year,int ToolsNumber)
    void pushDetails(char ToolsName[],char ToolsCategory[],float SellingPrice,float BuyingPrice,char BuyerName[],char SellerName[],int month,int date,int year,int ToolsNumber)
    {
        struct ToolsNode *newNode;
        newNode = (struct ToolsNode*) malloc (sizeof(struct ToolsNode)) ;
        for(i=0;i<strlen(ToolsName);i++)newNode->ToolsName[i] = ToolsName[i];
        for(i=0;i<strlen(ToolsCategory);i++)newNode->ToolsCategory[i] = ToolsCategory[i];
        newNode->SellingPrice = SellingPrice;
        newNode->BuyingPrice = BuyingPrice;
        for(i=0;i<strlen(BuyerName);i++)newNode->BuyerName[i] = BuyerName[i];
        for(i=0;i<strlen(SellerName);i++)newNode->SellerName[i] = SellerName[i];
        newNode->month = month;
        newNode->date = date;
        newNode->year = year;
        newNode->ToolsNumber = ToolsNumber;
        if(Tools == NULL)
        {
            Tools = newNode;
            Tools->previous = NULL;
        }
        else
        {
            newNode->previous = Tools;
            Tools = newNode;
        }
    }
    void viewItem(ToolsNode *Item)
    {
        printf("\n________PRODUCT DETAILS_________\n");
        printf("Product ID: %d",Item->ToolsNumber);
        printf("\nProduct Name: %s\n",Item->ToolsName);
        printf("Product Category: %s",Item->ToolsCategory);
        printf("\nProduct's Store Date: %d/%d/%d\n",Item->date,Item->month,Item->year);
        printf("Buying Price: %f",Item->BuyingPrice);
        printf("\nSelling Price: %f\n",Item->SellingPrice);
        printf("Seller Name: %s",Item->SellerName);
        printf("\nBuyer Name: %s\n",Item->BuyerName);
    }

    void pop()
    {
        if(Tools == NULL)
        {
            printf("\nThere is no Item in the Stack.\n");
        }
        else
        {
            ToolsNode *productItem = Tools;
            viewItem(productItem);
            Tools = Tools->previous;
            productItem->previous = NULL;
            delete productItem;
        }
    }

    void print()
    {
        if(Tools == NULL) printf("EMPTY STACK");
        ToolsNode *productTools = Tools;
        while(productTools != NULL)
        {
            viewItem(productTools);
            productTools = productTools->previous;
        }
    }

    void MonthlyProductDetails(int month)
    {
        ToolsNode *mproduct = Tools;
        while(mproduct != NULL)
        {
            if(mproduct->month == month)
            {
                viewItem(mproduct);
                mproduct = mproduct->previous;
            }
        }
    }
};


/*****QUEUE******/

int j;
StackTools ToolsDetails;
class CustomerQueue
{
private:
    struct CustomerNode
    {
        int month,date,year,InstrumentNumber;
//            string InstrumentName,InstrumentCategory,BuyerName,SellerName;
        char InstrumentName[MaxSize],InstrumentCategory[MaxSize],BuyerName[MaxSize],SellerName[MaxSize];
        float BuyingPrice,SellingPrice;
        CustomerNode *next;
    };

    CustomerNode *head,*current,*temp;

public:
    CustomerQueue()
    {
        head = NULL;
        temp = NULL;
        current = NULL;
    };
    //  void EnqueueDetails(string InstrumentName,string InstrumentCatagory, double SellingPrice,double BuyingPrice,string BuyerName,string SellerName,int month,int date,int year,int InstrumentNumber)
    void EnqueueDetails(char InstrumentName[],char InstrumentCategory[], float SellingPrice,float BuyingPrice,char BuyerName[],char SellerName[],int month,int date,int year,int InstrumentNumber)
    {
        struct CustomerNode *newNode;
        newNode = (struct CustomerNode*) malloc (sizeof(struct CustomerNode)) ;
        newNode->next = NULL;
        for(j=0;j<=strlen(InstrumentName);j++)newNode->InstrumentName[j] = InstrumentName[j];
        for(j=0;j<=strlen(InstrumentCategory);j++)newNode->InstrumentCategory[j] = InstrumentCategory[j];
        newNode->SellingPrice = SellingPrice;
        newNode->BuyingPrice = BuyingPrice;
        for(j=0;j<=strlen(BuyerName);j++)newNode->BuyerName[j] = BuyerName[j];
        for(j=0;j<=strlen(SellerName);j++)newNode->SellerName[j] = SellerName[j];
        newNode->month = month;
        newNode->date = date;
        newNode->year = year;
        newNode->InstrumentNumber = InstrumentNumber;
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            current = head;
            while(current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void viewItem(CustomerNode *Item)
    {
        printf("\n________PRODUCT DETAILS_________\n");
        printf("Product ID: %d",Item->InstrumentNumber);
        //printf("Product Name: %s",Item->InstrumentName.c_str());
        printf("\nProduct Name: %s\n",Item->InstrumentName);
        //printf("Product Category: %s",Item->InstumentCatagory.c_str());
        printf("Product Category: %s",Item->InstrumentCategory);
        printf("\nProduct's Store Date: %d/%d/%d\n",Item->date,Item->month,Item->year);
        printf("Buying Price: %f",Item->BuyingPrice);
        printf("\nSelling Price: %f\n",Item->SellingPrice);
        //printf("Seller Name: %s",Item->SellerName.c_str());
        //printf("Buyer Name: %s",Item->BuyerName.c_str());
        printf("Seller Name: %s",Item->SellerName);
        printf("\nBuyer Name: %s\n",Item->BuyerName);

    }

    void seeProductData()
    {
        if(head == NULL) {
            printf("\nThere is nothing to show.\n");
            return;
        }
        current = head;
        while(current != NULL)
        {
            viewItem(current);
            current = current->next;
        }
    }

    void deleteData(int InstrumentNumber)
    {
        CustomerNode* deleteI=NULL ;
        if(current == NULL)
        {
            printf("\n(%d) is not Available.\n",InstrumentNumber);
        }
        else if(head->InstrumentNumber == InstrumentNumber) {
            deleteI = head;
            head = head->next;
            delete deleteI;
        }
        else {
            current = head;
            while(current != NULL)
            {
                if(current->next->InstrumentNumber == InstrumentNumber)
                {
                    deleteI = current->next;
                    current->next = current->next->next;
                    delete deleteI;
                    printf("\n(%d) %s has been deleted\n", current->InstrumentNumber, current->InstrumentName);
                }
                current = current->next;
            }
        }
    }

    void StoreSoldDetails()
    {
        CustomerNode *storeI = NULL;
        if(head == NULL)
        {
            printf("\nNo Product Available.\n");
        }
        else
        {
            current = head;
            while(current != NULL)
            {
                temp = current;
                ToolsDetails.pushDetails(current->InstrumentName,current->InstrumentCategory,current->SellingPrice,current->BuyingPrice,current->BuyerName,current->SellerName,current->month,current->date,current->year,current->InstrumentNumber);
                deleteData(current->InstrumentNumber);
                current = current->next;
            }
            printf("\nAll product data has been stored.\n");
        }
    }
};


/*******LINKED LIST*********/
int k;
CustomerQueue Customer;
class LinkedListProductDetails
{
private:
    struct LinkedListNode
    {
        int month,date,year,ProductNumber;
        char ProductName[MaxSize],ProductCategory[MaxSize],SellerName[MaxSize];
        float SellingPrice,BuyingPrice;
        LinkedListNode* next;
    };

    LinkedListNode* head,*current;

public:
    LinkedListProductDetails()
    {
        head = NULL;
        current = NULL;
    }

    void AddProduct(char ProductName[],char ProductCategory[],float SellingPrice,float BuyingPrice,char SellerName[], int month,int date,int year,int ProductNumber)
    {
        //printf("%s\n", ProductCatagory.c_str());
        LinkedListNode * newNode ;
        newNode = (struct LinkedListNode*) malloc (sizeof(struct LinkedListNode)) ;
        newNode->next = NULL;
        for(k=0;k<=strlen(ProductName);k++)newNode->ProductName[k] = ProductName[k];
        for(k=0;k<=strlen(ProductCategory);k++)newNode->ProductCategory[k] = ProductCategory[k];
        for(k=0;k<=strlen(SellerName);k++)newNode->SellerName[k] = SellerName[k];
        newNode->month = month;
        newNode->date = date;
        newNode->year = year;
        newNode->ProductNumber = ProductNumber;
        newNode->SellingPrice = SellingPrice;
        newNode->BuyingPrice = BuyingPrice;

        if(head==NULL)
        {
            head = newNode;

        }
        else
        {
            current=head;
            while(current->next!=NULL)
            {
                current=current->next;
            }
            current->next = newNode;
        }
    }

    void deleteProductDetails(int ProductNumber)
    {
        LinkedListNode* deleteP=NULL ;
        if(current == NULL)
        {
            printf("\n(%d) is not Available.\n",ProductNumber);
        }
        else if(head->ProductNumber == ProductNumber)
        {
            deleteP = head;
            head = head->next;
            delete deleteP;
        }
        else {
            current = head;
            while(current != NULL)
            {
                if(current->next->ProductNumber == ProductNumber){
                    deleteP = current->next;
                    current->next = current->next->next;
                    delete deleteP;
                    printf("\n(%d) %s has been deleted.\n", ProductNumber, current->ProductName);
                }
                current = current->next;
            }
        }
    }

    void StoreOrderPrductDetails(int ProNumber, char BuyerName[])
    {
        LinkedListNode* storeP=NULL;
        current = head;
        while(current != NULL)
        {
            if(current -> ProductNumber == ProNumber)
            {
                Customer.EnqueueDetails(current->ProductName,current->ProductCategory,current->SellingPrice,current->BuyingPrice,BuyerName,current->SellerName,current->month,current->date,current->year,current->ProductNumber);
                deleteProductDetails(ProNumber);
                printf("\nThe Product %d no data has been stored.\n",ProNumber);
                return;
            }
            current = current->next;
        }
        printf("\n(%d) is not Available.\n",ProNumber);
        delete storeP;
    }
    void viewItem(LinkedListNode* Item)
    {
        printf("\n________PRODUCT DETAILS_________\n");
        printf("\nProduct ID: %d\n",Item->ProductNumber);
        //printf("Product Name: %s",Item->ProductName.c_str());
        printf("Product Name: %s",Item->ProductName);
        //printf("Product Category: %s",Item->ProductCatagory.c_str());
        printf("\nProduct Category: %s\n",Item->ProductCategory);
        printf("Product's Store Date: %d/%d/%d",Item->date,Item->month,Item->year);
        printf("\nBuying Price: %f\n",Item->BuyingPrice);
        printf("Selling Price: %f",Item->SellingPrice);
        //printf("Seller Name: %s",Item->SellerName.c_str());
        printf("\nSeller Name: %s\n",Item->SellerName);
    }
    void searchProduct()
    {
        if(head == NULL) {
            printf("\nThere is no Item to show.\n");
            return;
        }
        current = head;
        while(current != NULL)
        {
            viewItem(current);
            current = current->next;
        }
    }
};


LinkedListProductDetails ProductDetails;
int month,date,year;
static int ProductNumber = 1;
//string ProductName,ProductCatagory,SellerName,BuyerName;
char ProductName[MaxSize] ,ProductCategory[MaxSize] ,SellerName[MaxSize] ,BuyerName[MaxSize];
float SellingPrice,BuyingPrice;

/********MENU*********/
int MENU()
{
    int n;
    printf("\n_________MENU________\n");
    printf("\n 1.Add Product at the Store.\n 2.See Product.\n 3.Take Order.\n 4.See Order.\n 5.Process Order.");
    printf("\n 6.Monthly Item Details.\n 7.Sold Tools.\n 8.Last sold Item.\n 9.Exit.\n");
    printf("\nEnter your Choice:\t");
    scanf("%d", &n);
    return n;
}

/******ADD Product Details******/
void AddProductInfo()
{
    printf("\nProduct Number: %d",ProductNumber);
    printf("\nEnter Product Name: ");
    scanf("%s", &ProductName);
    printf("Enter Product Category: ");
    scanf("%s", &ProductCategory);
    printf("Enter Date: ");
    scanf("%d",&date);
    printf("Enter Month: ");
    scanf("%d",&month);
    printf("Enter Year: ");
    scanf("%d",&year);
    printf("Enter Buying Price: ");
    scanf("%f",&BuyingPrice);
    printf("Enter Selling Price: ");
    scanf("%f",&SellingPrice);
    printf("Enter Seller Name: SHARIP\n");
   // scanf("%s",&SellerName);
}

/***********MAIN**********/
int main()
{
    int choice,number;
//    string name;
    char name[MaxSize];
    while(true)
    {
        choice = MENU();
        if(choice == 1)
        {
            AddProductInfo();
            ProductDetails.AddProduct(ProductName,ProductCategory,SellingPrice,BuyingPrice,SellerName,month,date,year,ProductNumber);
            ++ProductNumber;
        }
        else if(choice == 2)
        {
            ProductDetails.searchProduct();
        }
        else if(choice == 3)
        {
            printf("Enter Product Number: ");
            scanf("%d",&number);
            printf("Enter Buyer Name: ");
            scanf("%s",&BuyerName);
            ProductDetails.StoreOrderPrductDetails(number,BuyerName);
        }
        else if(choice == 4)
        {
            //ProductDetails.seeProductData();
            Customer.seeProductData();
        }
         else if(choice == 5)
        {
            //printf("Enter Product Number: ");
            //scanf("%d",&number);
            Customer.StoreSoldDetails();
            printf("\nAll Item Sold Completely.\n");
        }
        else if(choice == 6)
        {
            printf("Enter Month: ");
            scanf("%d",&number);
            ToolsDetails.MonthlyProductDetails(number);
        }
        else if(choice == 7)
        {
            ToolsDetails.print();
        }
        else if(choice == 8)
        {
            ToolsDetails.pop();
        }
        else if(choice == 9)
        {
            break;
        }
    }

    return 0;
}
