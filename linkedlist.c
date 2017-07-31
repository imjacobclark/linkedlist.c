#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct LinkedListNode {
    int data;
    struct LinkedListNode *next;
};

struct LinkedList {
    int size;
    struct LinkedListNode *head;
    struct LinkedListNode *tail;
};

struct LinkedList create_linked_list(){
    struct LinkedList linkedList;

    linkedList.size = 0;
    linkedList.head = NULL;
    linkedList.tail = NULL;

    return linkedList;
}

struct LinkedListNode *malloc_linkedlistnode(){
    struct LinkedListNode *linkedListNode;
    linkedListNode = (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));
    return linkedListNode;
}

struct LinkedList append(struct LinkedList *linkedList, int data){
    struct LinkedListNode *linkedListNode = malloc_linkedlistnode();
    linkedListNode->data = data;
    linkedList->tail->next = linkedListNode;
    linkedListNode->next = NULL;

    linkedList->tail = linkedListNode;

    if(linkedList->head == NULL){
        linkedList->head = linkedListNode;
    }

    linkedList->size++;
    return *linkedList;
}

struct LinkedList prepend(struct LinkedList *linkedList, int data){
    struct LinkedListNode *linkedListNode = malloc_linkedlistnode();
    linkedListNode->data = data;
    linkedListNode->next = linkedList->head;

    linkedList->head = linkedListNode;

    if(linkedList->tail == NULL){
        linkedList->tail = linkedListNode;
    }

    linkedList->size++;
    return *linkedList;
}

bool empty(struct LinkedList *linkedList){
    return linkedList->size != 0;
}

int value_at(struct LinkedList *linkedList, int index){
    struct LinkedListNode head = *linkedList->head;
    struct LinkedListNode next;

    for(int i = 0; i <= linkedList->size; i++){
        if(i != 0){
            head = *head.next;
        }

        if(i == index){
            return head.data;
        }
    }

    return -1;
}

struct LinkedList insert_at(struct LinkedList *linkedList, int index, int data){
    struct LinkedListNode *head = linkedList->head;

    for(int i = 0; i <= linkedList->size; i++){
        if(i+1 == index){
            struct LinkedListNode *linkedListNode = malloc_linkedlistnode();
            linkedListNode->data = data;
            linkedListNode->next = head->next;
            head->next = linkedListNode;
            linkedList->size++;

            return *linkedList;
        }

        head = head->next;
    }

    return *linkedList;
}

int front(struct LinkedList *linkedList){
    return linkedList->head->data;
}

int back(struct LinkedList *linkedList){
    return linkedList->tail->data;
}

int main(){
    struct LinkedList linkedList;
    linkedList = create_linked_list();

    printf("List is %s\n", (linkedList.size ? "not empty" : "empty"));

    for(int i = 0; i <= 10; i++){
        linkedList = prepend(&linkedList, i * 2);
    }

    linkedList = append(&linkedList, 100);

    struct LinkedListNode head = *linkedList.head;
    struct LinkedListNode tail = *linkedList.tail;

    printf("List is %s\n", (linkedList.size ? "not empty" : "empty"));

    linkedList = insert_at(&linkedList, 3, 1000);

    printf("Value at 1: %d\n", value_at(&linkedList, 1));
    printf("Value at 5: %d\n", value_at(&linkedList, 5));
    printf("Value at 3: %d\n", value_at(&linkedList, 3));
    printf("Front: %d\n", front(&linkedList));
    printf("Back: %d\n", back(&linkedList));

    for(int i = 0; i <= linkedList.size; i++){
        if(head.next == NULL){
            printf("Size of list: %d\n", linkedList.size);
            exit(0);
        }

        if(i != 0){
            head = *head.next;
        }

        printf("Index %d: %d\n", i, head.data);
    }
}
