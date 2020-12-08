#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
void add_end1(struct Node *head,int data) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    struct Node *ptr = head;
    while(ptr->next!=NULL)
        ptr = ptr->next;
    ptr ->next = temp;
}
struct Node *add_end(struct Node *ptr,int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    ptr->next = temp;
    ptr = temp;
    return ptr;
}
void add_pos(struct Node *head,int pos,int data,int count){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    struct Node *ptr = head;
    if(pos>count+1||pos<0)
        printf("Invalid positon!\n");
    else {
        pos --;
        while (pos!=1)
        {
            ptr = ptr->next;
            pos--;
        }
        temp->next = ptr->next;
        ptr->next=temp;}

}
struct Node *add_beg(struct Node *head,int data) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->next=head;
    head=temp;
    return head;
}
void print(struct Node *ptr) {
    if(ptr == NULL)
        printf("List is empty");
    else
    {
            while(ptr!=NULL) {
                printf("%d ",ptr->data);
                ptr = ptr->next;
            }
    }

}
int count_node(struct Node *head) {
    int count =0;
    struct Node *ptr = head;
    if(head == NULL)
        count =0;
    while(ptr!=NULL) {
        count++;
        ptr = ptr->next;

    }
    return count;

}
void display(struct Node *head) {
    struct Node *ptr = head;
    if(ptr == NULL)
        printf("List is empty\n");
    else
    {
        while(ptr!=NULL) {
            printf("%d ",ptr->data);
            ptr = ptr->next; }
    }

}
struct Node *del_list(struct Node *head) {
    struct Node *temp = head;
    if(head == NULL)
        printf("List is empty\n");
    while (head!=NULL)
    {
        temp = temp ->next;
        free(head);
        head = temp;
    }
    return head;

}
struct Node *del_beg(struct Node *head){
    if(head == NULL)
        printf("List is empty\n");
    struct Node *temp = head;
    head = head ->next;
    free(temp);
    temp = NULL;
    return head;
}
void del_last(struct Node **head) {
    struct Node *temp = *head;
    if((*head) == NULL)
        printf("List is empty\n");
    else if((*head) -> next == NULL)
    {
        free(*head);
        (*head) = NULL;
    }
    else
    {
        while (temp ->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp ->next = NULL;

    }

}
void del_pos(struct Node **head,int pos) {
    struct Node *prev = *head;
    struct Node *curent = *head;
    if((*head)== NULL)
        printf("List is empty\n");
    else if (pos == 1)
    {
        (*head) = (*head)->next;
        free(curent);
        curent = NULL;

    }
    else
    {
        while (pos!=1)
        {
            prev = curent;
            curent = curent->next;
            pos --;
        }
        prev->next = curent->next;
        free(curent);
        curent = NULL;
    }

}
void search(struct Node *head,int val) {
    struct Node *ptr = head;
    struct Node *pos = NULL;
    while (ptr!=NULL)
    {
        if(val == ptr->data)
            pos = ptr;
        ptr = ptr->next;
    }
    if(pos == NULL)
        printf("\nData is not found");
    else
        printf("\nData is found");

}
void reverse(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *next = NULL;
    while (*head != NULL)
    {
        next = (*head)->next;
        (*head)->next = prev;
        prev = *head;
        *head = next;
    }
    *head = prev;

}
int main(int argc, char const *argv[])
{
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head ->data = 40;
    head ->next = NULL;
    printf("Before performing any operation, the List is : \n");
    struct Node *ptr = head;
    struct Node *ptr1=head;
    print(ptr);
    int data,no_of_data,i,choice;
    printf("\nEnter how many data you wanted to add in the list : \n");
    scanf("%d",&no_of_data);
    printf("\nEnter your choice, 1 for inserting the data at the begining of list\n2 for inserting the data at the end of list: ");
    scanf("%d",&choice);
    for(i = 0;i<no_of_data;i++) {
        switch (choice)
        {
        case 1:
            scanf("%d",&data);
            head = add_beg(head,data);
            break;
        case 2:
            scanf("%d",&data);
            ptr1 = add_end(ptr1,data);
            break;

        default:
            break;
        }
    }
    switch (choice)
    {
    case 1:
        printf("After adding the data at the begining of the List, the List is : \n");
        display(head);
        break;
    case 2:
        printf("After adding the data at the end  of the List, the List is : \n");
        display(head);
        break;
    default:
        printf("You didn't perform any operation, so the list is same :\n");
        display(head);
        break;
    }
    add_end1(head,90);
    printf("\nNumber of nodes in the List = %d\n",count_node(head));
    printf("If you want to add data in the List at certain positon, enter 1 for add data at the certaion position in the list: ");
    scanf("%d",&choice);
    int pos;
    printf("Enter which position you want to add data : \n");
    scanf("%d",&pos);
    switch (choice)
    {
    case 1:
        if(pos==1) {
           printf("Enter data which you want to add : \n");
           scanf("%d",&data);
           head = add_beg(head,data); }
        else {
            printf("Enter data which you want to add : \n");
            scanf("%d",&data);
            add_pos(head,pos,data,count_node(head));
        }
        break;

    default:
        printf("Wrong option\n");
        break;
    }

    ptr = head;
    switch (choice)
    {
    case 1:
        printf("List after Inserting %d at the %d position : \n",data,pos);
        print(ptr);
        break;

    default:
        printf("You didn't add any data, so the List is same : \n");
        print(ptr);
        break;
    }
    printf("\nIf you want to delete some data from list or delete the whole list\n 1 for delete from the beg. \n 2 for delete at the end \n 3 for delete at particular position \n 4 for delete the whole list \n choose the following option\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        head = del_beg(head);
        printf("After deleting the first element of the list,the list is \n");
        display(head);
        break;
    case 2:
        del_last(&head);
        printf("After deleting the last element of the list,the list is \n");
        display(head);
        break;
    case 3:
        printf("Enter the position : ");
        scanf("%d",&pos);
        del_pos(&head,pos);
        printf("After deleting the element at a certain position,the list is \n");
        display(head);
        break;
    case 4:
        head = del_list(head);
        printf("After deleting the whole list \n");
        display(head);
        break;

    default:
        printf("You did not perform any deletion operation,so the list is same\n");
        display(head);
        break;
    }
    search(head,40);
    reverse(&head);
    printf("\nList in reverse order :\n");
    display(head);
    return 0;
}
