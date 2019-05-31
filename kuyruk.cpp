#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char name[20];
    char secondName[20];
    int age;
    int priority;
    struct node *next;
};

struct node* head = NULL;
struct node* tail = NULL;
struct node* temp;

char firstName[20], secondName[20];
int age, pri;
char priority[10];

void selection(int chosen);

struct node* createPerson(char name[], char secondName[], int age, int priority)
{
    struct node* newPerson = (struct node*)malloc(sizeof(struct node));
    strcpy(newPerson->name, name);
    strcpy(newPerson->secondName, secondName);
    newPerson->age = age;
    newPerson->priority = priority;
    newPerson->next = NULL;

    return newPerson;
};

void enQueuePerson(char name[], char secondName[], int age, int priority)
{
    struct node* person = createPerson(name, secondName, age, priority);
    
    if(head == NULL && tail == NULL)
    {
        head = person;
        tail = person;
    }
    else
    {

        if(person->priority <= head->priority)
        {
            temp = head;
            head = person;
            person->next = temp;
            return;
        }
      
        if(person->priority >= tail->priority)
        {
            tail->next = person;
            tail = person;
        }

        temp = head;
        while(temp->next != NULL)
        {
            if(person->priority < temp->next->priority)
            {
                struct node* newy;
                newy = temp->next;
                temp->next = person;
                person->next = newy;
            }
            temp = temp->next;
        }
    }
}

void deQueue()
{
    temp = head;
    if(head == NULL)
    {
        printf("\n Kuyruk Bos Lutfen kisi Ekleyin");
        return;
    }

    if(head == tail)
    {
        head = NULL;
        tail = NULL;
        return;
    }

    head = temp->next;	
    free(temp);
}

struct node* whoNext()
{
    if(head == NULL)
    {
        printf("\nKuyruk Bos...");
        return 0;
    }

    return head;
}

void checkPri(int x)
{
    if(x == 1)
            strcpy(priority, "High");
        else if(x == 2)
            strcpy(priority, "Normal");
        else
            strcpy(priority, "Low");
}

void printQueue()
{

    int i = 1;
    if(head == NULL)
    {
        return;
    }
    temp = head;
    while(temp->next != NULL)
    {
        checkPri(temp->priority);
        printf("\n%d. Pozisyon => %s %s %d oncelik ==> %s ", i, temp->name, temp->secondName, temp->age, priority);
        temp = temp->next;
        i++;
    }
    checkPri(temp->priority);
    printf("\n%d. Pozisyon => %s %s %d oncelik ==> %s ", i, temp->name, temp->secondName, temp->age, priority);
}


void menu()
{
    int choise;
    while( 1 == 1 )
    {
        printf("\n Algoritma Uzmani ... ");
        printf("\n 1- Kisi Ekle ... ");
        printf("\n 2- Kisi Cikar ... ");
        printf("\n 3- Siradaki Kim? ");
        printf("\n Seciminizi Yapin ");
        scanf("%d", &choise);
        selection(choise);
    }
}

void selection(int chosen)
{
    switch(chosen)
    {
        case 1:
            printf("\n Kisinin ismi ... ");
            scanf("%s", &firstName[20]);
            printf("\n Kisinin soyadi ... ");
            scanf("%s", &secondName[20]);
            printf("\n Yasi ... ");
            scanf("%d", &age);
            printf("\n oncelik durumunu girin ... (1 yuksek oncelikli | 2 normal | 3 dusuk oncelikli) ");
            scanf("%d", &pri);
            enQueuePerson(firstName, secondName, age, pri);
            printQueue();
            break;
        case 2:
            deQueue();
            printQueue();
            break;
        case 3:
            temp = whoNext();
            printf("\n ****************** \n");
            if(temp != NULL)
            {
                printf("%s %s %d", temp->name, temp->secondName, temp->age);
            }
            break;
    }
}

int main()
{
    menu();
    return 0;
}
