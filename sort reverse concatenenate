#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node*));
    if(newNode==NULL)
    {
        printf("memory allocation failed \n");
        exit(0);
    }
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

Node* insertAtBeginning(Node *head,int value)
{
    Node* newNode=createNode(value);
    newNode->next=head;
    return newNode;
}


Node* concat(Node* head1,Node* head2)
{
    Node* temp=head1;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=head2;
    return head1;
}

Node *sort(Node* head)
{
    Node *current,*temp;
    int t;
    current=head;
    while(current!=NULL)
    {
        temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data>temp->next->data)
            {
                t=temp->data;
                temp->data=temp->next->data;
                temp->next->data=t;
            }
            temp=temp->next;
        }
        current=current->next;
    }
    return head;
}

Node* reverse(Node* head)
{
    Node *prev=NULL,*next,*temp;
    temp=head;
    while(temp!=NULL)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
    return head;
}

void displaylinkedlist(Node *head1,Node* head2)
{
    Node *t1=head1,*t2=head2;
    printf("\n linked list 1:");
    while(t1!=NULL)
    {
        printf("%d",t1->data);
        t1=t1->next;
    }
    printf("NULL");
    printf("\n linked list 1:");
    while(t2!=NULL)
    {
        printf("%d",t2->data);
        t2=t2->next;
    }
    printf("NULL");
}

int main()
{
    Node *list1 = NULL;
    Node *list2 = NULL;
    int choice,value;
    printf("\n available options are:");
    printf("\n 1.insertAtBeginning for list1");
    printf("\n 2.insertAtBeginning for list2");
    printf("\n 3.concation");
    printf("\n 4.sorting");
    printf("\n 5.reversing");
    printf("\n 6.display");
    printf("\n 7.Quit");

    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("enter the data for list1");
                    scanf("%d",&value);
                    list1=insertAtBeginning(list1,value);
                    break;
            case 2: printf("enter the data for list2");
                    scanf("%d",&value);
                    list2=insertAtBeginning(list2,value);
                    break;
            case 3: printf("After concatenation:\n");
                    list1 = concat(list1, list2);
                    printf(list1);
                    break;
            case 4: printf("After Sorting:\n");
                    list1 = sort(list1);
                    list2 = sort(list2);
                    printf(list1);
                    printf(list2);
                    break;
            case 5: printf("After reversing:\n");
                    list1 = reverse(list1);
                    printf(list1);
                    break;
            case 6: displaylinkedlist(list1,list2);
                    break;
            case 7:exit(0);
                    break;
            default:printf("\n invalid choice");
                    break;
        }
    }
}
