#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct stack {
    char* data;
    int top;
    int capacity;
} stack;

node* makeNode(int data);
void addNode(node** head, int data);
void printList(node *list);
void initialize(stack* s);
int push(stack* s, char value);
int isEmpty(stack* s);
char pop(stack* s);
char peek(stack* s);

void insertAfterN(node* head, int M, int N)
{
    // your code here
}

int isPalindrome(char *str)
{
   // your code here
}


node* makeNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(node** head, int data) 
{
    node* newNode = makeNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(node *list)
{
    node *current = list;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }

    printf("\n");
    return;
}

void initialize(stack* s)
{
    s->capacity = 10;
    s->data = (char*)malloc(s->capacity * sizeof(char));
    s->top = -1;
}

int push(stack* s, char value)
{
    if (s->top == s->capacity - 1)
    {
        s->capacity *= 2;
        s->data = (char*)realloc(s->data, s->capacity * sizeof(char));
    }

    s->top++;
    s->data[s->top] = value;
    return 1;
}

int isEmpty(stack* s)
{
    return s->top == -1;
}

char pop(stack* s)
{
    if (isEmpty(s))
        return 'I';

    char value = s->data[s->top];
    s->top--;
    return value;
}

char peek(stack* s)
{
    if (isEmpty(s))
        return 'I';

    return s->data[s->top];
}

int main(int argc, char** argv)
{
    srand(time(NULL));

    node *list = NULL;

    for (int i = 0; i < 10; i++)
    {
        addNode(&list, (rand() % 5));
    }

    printf("Linked list insertion results:\n");
    printf("List before insertion:\n");
    printList(list);

    insertAfterN(list, 500, 3);
    printf("List after insertion:\n");
    printList(list);
    printf("\n");

    char *testCases[] = {"racecar", "nogood", "hannah", "a", "aad", "ada"};

    int answerKey[] = {1, 0, 1, 1, 0, 1};
    int userAnswer;

    printf("Palindrome tests:\n");
    for (int i = 0; i < sizeof(testCases)/sizeof(testCases[0]); i++)
    {
        userAnswer = isPalindrome(testCases[i]);
        printf("Test %d expected %d, returned %d\n", i+1, answerKey[i], userAnswer);
    }
    
    printf("\n");
    printf("The linked list should insert a 500 after every 3.\n");
    printf("It is possible that the random number generator didn't generate any 3s.\n");
    printf("If that is the case, just run the program again until it does.\n");

}