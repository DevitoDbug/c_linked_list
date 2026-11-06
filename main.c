#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
        int value;
        struct Node *next;
} Node;
Node *NewNode();
void PrintNode(Node *n, char output[], size_t output_size);

typedef struct LinkedList {
        struct Node *head;
} LinkedList;
LinkedList *NewLinkedList();
void PrintLinkedList(LinkedList *l);
void AddToEnd(LinkedList *l, int value);
void AddToStart(LinkedList *l, int value);
void AddAtIndex(LinkedList *l, int value, int index);
void DeleteAtIndex(LinkedList *l, int index);
void CleanUpList(LinkedList *l);

int main() {
    LinkedList *l = NewLinkedList();
    AddToEnd(l, 10);
    AddToEnd(l, 9);
    AddToEnd(l, 8);
    AddToEnd(l, 7);
    AddToEnd(l, 6);
    AddToEnd(l, 5);
    AddToStart(l, 11);
    PrintLinkedList(l);
    AddAtIndex(l, 100, 3);
    PrintLinkedList(l);
    DeleteAtIndex(l, 3);
    PrintLinkedList(l);
    CleanUpList(l);
}

Node *NewNode() {
    Node *n = malloc(sizeof(struct Node));
    return n;
}
void PrintNode(Node *n, char output[], size_t output_size) {
    if (n == NULL) {
        printf("NULL node passed in");
        return;
    }
    if (output_size == 0) {
        printf("output size set to 0");
        return;
    }

    snprintf(output, output_size, "%d", n->value);
    return;
}

LinkedList *NewLinkedList() {
    LinkedList *l = malloc(sizeof(LinkedList));
    return l;
}

void PrintLinkedList(LinkedList *l) {
    if (l == NULL) {
        printf("Linked list passed in is NULL");
        return;
    }

    if (l->head == NULL) {
        printf("Empty list");
        return;
    }

    Node *current = l->head;

    while (current != NULL) {
        size_t size = 100;
        char output[size];
        PrintNode(current, output, size);
        printf("%s", output);

        if (current->next != NULL) {
            printf("->");
        }
        current = current->next;
    }
    printf("\n");
}

void AddToEnd(LinkedList *l, int value) {
    if (l == NULL) {
        printf("Linked list passed in is NULL");
        return;
    }

    Node *new_node = NewNode();
    new_node->value = value;
    if (l->head == NULL) {
        l->head = new_node;
        return;
    }

    Node *current = l->head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void AddToStart(LinkedList *l, int value) {
    if (l == NULL) {
        printf("Linked list passed in is NULL");
        return;
    }

    Node *new_node = NewNode();
    new_node->value = value;
    if (l->head == NULL) {
        l->head = new_node;
        return;
    }

    new_node->next = l->head;
    l->head = new_node;
}

void AddAtIndex(LinkedList *l, int value, int index) {
    if (l == NULL) {
        printf("Linked list passed in is NULL");
        return;
    }

    if (index < 0) {
        printf("invalid index provided");
        return;
    }

    Node *new_node = NewNode();
    new_node->value = value;
    if (l->head == NULL && index == 0) {
        l->head = new_node;
        return;
    }

    Node *current = l->head;
    int counter = 0;
    while (current->next != NULL) {
        if (index == counter + 1) {
            new_node->next = current->next;
            current->next = new_node;
            return;
        }

        current = current->next;
        counter++;
    }

    current->next = new_node;
}

void DeleteAtIndex(LinkedList *l, int index) {
    if (l == NULL) {
        printf("Linked list passed in is NULL");
        return;
    }

    if (index < 0) {
        printf("invalid index provided");
        return;
    }

    if (l->head == NULL) {
        return;
    }

    Node *current = l->head;
    Node *deleteNode = NULL;
    int counter = 0;
    while (current->next != NULL) {
        if (index == counter + 1) {
            deleteNode = current->next;
            current->next = current->next->next;
            if (deleteNode != NULL) {
                free(deleteNode);
            }
            return;
        }

        current = current->next;
        counter++;
    }
}

void CleanUpList(LinkedList *l) {
    if (l == NULL) {
        printf("Linked list passed in is NULL");
        return;
    }
    Node *current = l->head;
    while (current != NULL) {
        Node *nextNode = current->next;
        Node *deletedNode = current;
        if (current != NULL) {
            free(deletedNode);
        }
        current = nextNode;
    }
}
