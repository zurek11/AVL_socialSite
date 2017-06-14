#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE{
    char* value;
    int height;
    struct NODE* LCHILD;
    struct NODE* RCHILD;
}NODE;

typedef struct LIST{
    char* name;
    struct LIST* next;
    struct NODE* root;
}LIST;

LIST* array[10000];

//Funkcia vracajuca vysku listu
int getHeight(NODE* n){
    if (n == NULL)return 0;
    return n->height;
}

//Funkcia vracajuca vacsie z dvoch cisiel
int max(int a, int b) {
    return (a > b)? a : b;
}

//Funkcia vytvarajuca novy list stromu s danou hodnotou
NODE* newNode(char* value){
    NODE* newNode=(NODE*)malloc(sizeof(NODE));
    newNode->value=(char*)malloc(sizeof(char)*(strlen(value)+1));
    strcpy(newNode->value,value);
    newNode->LCHILD=NULL;
    newNode->RCHILD=NULL;
    newNode->height=1;
    return(newNode);
}

//Funkcia vracajuca rozdiel hodnot childov
int getBalance(NODE* node) {
    if (node==NULL)return 0;
    return getHeight(node->LCHILD) - getHeight(node->RCHILD);
}

//Funkcia najde najmensiu hodnotu v strome
NODE* minValue(NODE* node) {
    NODE* temp=node;

    //prehladava na samy spodok dolava na najlavejsieho childa
    while (temp->LCHILD!=NULL) temp = temp->LCHILD;
    return temp;
}

//Rotacia RR
NODE* rightRotate(NODE* z){
    NODE* y=z->LCHILD;
    NODE* temp=y->RCHILD;

    //Rotacia RR
    y->RCHILD=z;
    z->LCHILD=temp;

    //Zmeni vysky
    z->height=max(getHeight(z->LCHILD), getHeight(z->RCHILD))+1;
    y->height=max(getHeight(y->LCHILD), getHeight(y->RCHILD))+1;

    //Vrati novy koren podstromu
    return y;
}

//Rotacia LL
NODE* leftRotate(NODE* z){
    NODE* y = z->RCHILD;
    NODE* temp = y->LCHILD;

    //Rotacia LL
    y->LCHILD=z;
    z->RCHILD=temp;

    //Zmeni vysky
    z->height=max(getHeight(z->LCHILD),getHeight(z->RCHILD))+1;
    y->height=max(getHeight(y->LCHILD),getHeight(y->RCHILD))+1;

    //Vrati novy koren podstromu
    return y;
}

NODE* deleteNode(NODE* node, char* value) {
    //ak sa ma vymazat uz vymazany list
    if(node == NULL)return node;

    if (strcmp(value,node->value)<0) node->LCHILD=deleteNode(node->LCHILD,value);

    else if(strcmp(value,node->value)>0) node->RCHILD=deleteNode(node->RCHILD,value);

    else {
        if((node->LCHILD==NULL) || (node->RCHILD==NULL)){
            NODE* temp;

            if(node->LCHILD)temp=node->LCHILD;
            else temp=node->RCHILD;

            //Ak vymazavany list nema ziadne deti
            if(temp==NULL) {
                temp=node;
                node=NULL;
            }
                //Ak vymazavany list ma prave jedno dieta
            else *node = *temp;
            free(temp);
        }
        else {
            NODE* temp=minValue(node->RCHILD);

            strcpy(node->value,temp->value);

            node->RCHILD=deleteNode(node->RCHILD,temp->value);
        }
    }

    //Ak ma strom iba jeden list vrat ho
    if (node == NULL) return node;

    //Nastavi sa nova vyska listov
    node->height = max(getHeight(node->LCHILD),getHeight(node->RCHILD))+1;

    //rozdiel hodnot childov
    int balance = getBalance(node);

    //Ak po zmazani ostane strom nevyvazeny treba ho vyrovnat

    //LL Rotate
    if (balance > 1 && getBalance(node->LCHILD)>=0) return rightRotate(node);

    //LR Rotate
    if (balance>1 && getBalance(node->LCHILD)<0) {
        node->LCHILD=leftRotate(node->LCHILD);
        return rightRotate(node);
    }

    //RR Rotate
    if (balance<-1 && getBalance(node->RCHILD)<=0) return leftRotate(node);

    //RL Rotate
    if (balance<-1 && getBalance(node->RCHILD)>0) {
        node->RCHILD = rightRotate(node->RCHILD);
        return leftRotate(node);
    }

    return node;
}

NODE* addNode(NODE* node,char* value){
    //Ak sa pridava koren do stromu
    if(node==NULL) return(newNode(value));
    if(strcmp(value,node->value)==0) return node;
    //Posuvanie sa po vetvach stromu
    if(strcmp(value,node->value)<0) node->LCHILD=addNode(node->LCHILD,value);
    if(strcmp(value,node->value)>0) node->RCHILD = addNode(node->RCHILD,value);

    //Nastavenie vysky listu
    node->height=max(getHeight(node->LCHILD),getHeight(node->RCHILD))+1;
    //Rozdiel hodnot childov
    int balance=getBalance(node);

    //LL Rotation
    if (balance>1 && strcmp(value,node->LCHILD->value)<0)return rightRotate(node);

    //RR Rotation
    if (balance<-1 && strcmp(value,node->RCHILD->value)>0)return leftRotate(node);

    //LR Rotation
    if (balance>1 && strcmp(value,node->LCHILD->value)>0) {
        node->LCHILD=leftRotate(node->LCHILD);
        return rightRotate(node);
    }

    //RL Rotation
    if (balance<-1 && strcmp(value,node->RCHILD->value)<0){
        node->RCHILD=rightRotate(node->RCHILD);
        return leftRotate(node);
    }

    //Vracia sa uplne novy strom vyvazeny
    return node;
}

//vypis k-teho prvku v inOrder zo stromu
char* inOrder(NODE* node, int* k) {
    char *temp;
    if (node==NULL)return NULL;

    temp=inOrder(node->LCHILD,k);
    if(*k==0) return temp;
    --(*k);
    if(*k==0) return node->value;
    return inOrder(node->RCHILD,k);
}

//Funkcia na hornerovu schemu char na int
unsigned int charToInt(char* page){
    int i;
    unsigned int result=1;

    for (i=1;i<strlen(page);++i)result=result*7+page[i];
    result=result%10000;
    return result;
}

//Funkcia hladajuca strom v hash tabulke
LIST* findPage(char *page){
    int hash=charToInt(page);
    LIST* newList;
    if(array[hash]==NULL){
        newList=(LIST*)malloc(sizeof(LIST));
        newList->name=(char*)malloc(sizeof(char)*(strlen(page)+1));
        strcpy(newList->name,page);
        newList->root=NULL;
        newList->next=NULL;
        array[hash]=newList;
        return newList;
    }
    else{
        newList=array[hash];
        while(newList!=NULL){
            if(strcmp(newList->name,page)==0) return newList;
            newList=newList->next;
        }
        newList=(LIST*)malloc(sizeof(LIST));
        newList->name=(char*)malloc(sizeof(char)*(strlen(page)+1));
        strcpy(newList->name,page);
        newList->root=NULL;
        newList->next=array[hash];
        array[hash]=newList;
        return newList;
    }
}

void init(){
    int i;
    for(i=0;i<10000;++i) array[i]=NULL;
}
void like(char *page, char *user){
    LIST* temp=findPage(page);
    temp->root=addNode(temp->root,user);
}

void unlike(char *page, char *user){
    LIST* temp=findPage(page);
    temp->root=deleteNode(temp->root,user);
}

char *getuser(char *page, int k){
    LIST* temp=findPage(page);
    return inOrder(temp->root,&k);
}