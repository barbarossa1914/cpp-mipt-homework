#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node* next;
    struct node* prev;
};
typedef struct node Node;

struct list{
    Node* head;
    Node* tail;
    size_t size;
};
typedef struct list List;

List init(size_t n){
    List new_list;
    Node* head = (Node*)malloc(sizeof(Node));
    head->value = 0;
    head->prev = NULL;
    Node* tail = (Node*)malloc(sizeof(Node));
    tail->value = 0;
    tail->next = NULL;
    Node* current = head; 
    if (n==0){
        free(tail);
        free(head);
        new_list.head = NULL;
        new_list.tail = NULL;
    }
    else if (n==1){
        new_list.head = head;
        new_list.tail = head;
        head->next = NULL;
        free(tail);
    }
    else if (n==2){
        new_list.head = head;
        new_list.tail = tail;
        head->next = tail;
        tail->prev = head;
    } 
    else{ 
        for (size_t i = 1; i < n-1; i++){
            Node* new_node = (Node*)malloc(sizeof(Node));
            new_node->prev = current;
            current->next = new_node;
            new_node->value = 0;
            current = new_node;
            if (i == n-2){
                new_node->next = tail;
                tail->prev = new_node;
            }
        }
        new_list.head = head;
        new_list.tail = tail;
    }
    new_list.size = n;
    return new_list;
}

void print(const List* pl){
    if (pl->head == NULL)
        printf("List is empty");
    else{
        Node* current = pl->head;
        while (current->next != NULL){
            printf("%i\n", current->value);
            current = current->next;
        }
        printf("%i\n", current->value);
    }
}

void push_back(List* pl, int value){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    if (pl->tail == NULL){
        new_node->prev = NULL;
        pl->head = new_node;
        pl->tail = new_node;
    } else {
        new_node->prev = pl->tail;
        pl->tail->next = new_node;
        pl->tail = new_node;
    }
    pl->size += 1;
}

int pop_back(List* pl){
    if (pl->tail == NULL){
        printf("Error: pop_back from empty list.\n");
        exit(1);
    }
    int res = pl->tail->value;
    Node* old_tail = pl->tail;
    pl->tail = old_tail->prev;
    if (pl->tail != NULL)
        pl->tail->next = NULL;
    else
        pl->head = NULL;
    free(old_tail);
    pl->size -= 1;
    return res;
}

void push_front(List* pl, int value){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->prev = NULL;

    if (pl->head == NULL){
        new_node->next = NULL;
        pl->head = new_node;
        pl->tail = new_node;
    } else {
        new_node->next = pl->head;
        pl->head->prev = new_node;
        pl->head = new_node;
    }
    pl->size += 1;
}

int pop_front(List* pl){
    if (pl->head == NULL){
        printf("Error: pop_front from empty list.\n");
        exit(1);
    }
    
    int res = pl->head->value;
    Node* old_head = pl->head;ы
    pl->head = old_head->next;

    if (pl->head != NULL){
        pl->head->prev = NULL;
    } else {
        pl->tail = NULL;
    }

    free(old_head);
    pl->size -= 1;
    return res;
}

void destroy(List* pl){
    Node* current = pl->head;
    while (current != NULL){
        Node* next = current->next;
        free(current);
        current = next;
    }
    pl->head = NULL;
    pl->tail = NULL;
    pl->size = 0;
}

void splice(List* plist, Node* p, List* pother){
    if (pother->head == NULL) return;

    if (plist->head == NULL) {
        plist->head = pother->head;
        plist->tail = pother->tail;
    } else if (p == NULL) {
        plist->tail->next = pother->head;
        pother->head->prev = plist->tail;
        plist->tail = pother->tail;
    } else {
        Node* prev_p = p->prev;
        pother->tail->next = p;
        p->prev = pother->tail;
        if (prev_p != NULL) {
            prev_p->next = pother->head;
            pother->head->prev = prev_p;
        } else {
            plist->head = pother->head;
            pother->head->prev = NULL;
        }
    }
    plist->size += pother->size;
    pother->head = NULL;
    pother->tail = NULL;
    pother->size = 0;
}

void advance(Node** pp, size_t n){
    for (size_t i = 0; i < n && *pp != NULL; i++) {
        *pp = (*pp)->next;
    }
}

Node* erase(List* pl, Node* p){
    if (p == NULL) {
        return NULL;
    }

    Node* next_node = p->next;

    if (p->prev != NULL) {
        p->prev->next = p->next;
    } else {
        pl->head = p->next;
    }

    if (p->next != NULL) {
        p->next->prev = p->prev;
    } else {
        pl->tail = p->prev;
    }

    free(p);
    pl->size -= 1;

    return next_node;
}