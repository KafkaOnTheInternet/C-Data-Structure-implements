#include<stdio.h>
#include<stdlib.h>

struct node {
	int val;
	struct node* next;
};
struct node *BuildOneTwoThree()
{
	struct node* head = malloc(sizeof(struct node));
	struct node* second = malloc(sizeof(struct node));
	struct node* third = malloc(sizeof(struct node));
	head->val = 1;
	head->next = second;
	second->val = 2;
	second->next = third;
	third->val = 3;
	third->next = NULL;

	return head;
}

void print(struct node* head)
{
	struct node* current = head;
	while(current != NULL) {
		printf("%d\n", current->val);
		current = current->next;
	}
}
void push(struct node** headRef, int value)
{
	struct node* newNode = malloc(sizeof(struct node));
	newNode->val = value;
	newNode->next = *headRef;
	*headRef = newNode;
}
int length(struct node* head)
{
    struct node* current = head;
    int count =0;
    for(current = head; current != NULL; current = current->next) {
        count++;
    }
    return count;
}
struct node* BuildWithCase()
{
    int i;
    struct node* head = NULL;
    struct node* tail;
    push(&head, 1);
    tail = head;
    for(i=2; i<6; i++) {
        push(&(tail->next), i);
        tail = tail->next;
    }
    return head;
}

struct node* BuildWithDummy()
{
    struct node dummy;
    struct node* tail = &dummy;
    dummy.next = NULL;

}

int main() {
	struct node *myList = BuildWithCase();
	int l;
	//push(&myList, 13);
	print(myList);
	printf("Lenght of the list is %d\n", length(myList));
	return 0;
}
