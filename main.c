#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
        int value;
        struct Node *next;
} Node;
Node *NewNode(int value);
void PrintNode(Node *n, char output[], size_t output_size);

typedef struct LinkedList {
        Node *head;
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
    // AddToEnd(l, 10);
    // AddToStart(l, 9);
    // AddToStart(l, 8);
    PrintLinkedList(l);
    AddAtIndex(l, 1, 11);
    PrintLinkedList(l);
}

Node *NewNode(int value) {
    Node *n = malloc(sizeof(struct Node));
    n->value = value;
    n->next = NULL;
    return n;
}
void PrintNode(Node *n, char output[], size_t output_size) {
    if (n == NULL) {
        printf("NULL node passed in\n");
        return;
    }
    if (output_size == 0) {
        printf("output size set to 0\n");
        return;
    }

    snprintf(output, output_size, "%d", n->value);
    return;
}

LinkedList *NewLinkedList() {
    LinkedList *l = malloc(sizeof(LinkedList));
    l->head = NULL;
    return l;
}

void PrintLinkedList(LinkedList *l) {
    if (l == NULL) {
        printf("Linked list passed in is NULL\n");
        return;
    }

    if (l->head == NULL) {
        printf("Empty list\n");
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

    Node *new_node = NewNode(value);
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

    Node *new_node = NewNode(value);
    if (l->head == NULL) {
        l->head = new_node;
        return;
    }

    new_node->next = l->head;
    l->head = new_node;
}

void AddAtIndex(LinkedList *l, int index, int value) {
    if (l == NULL) {
        printf("Linked list passed in is NULL\n");
        return;
    }

    if (index < 0) {
        printf("invalid index provided\n");
        return;
    }

    Node *new_node = NewNode(value);
    if (index == 0) {
        AddToStart(l, value);
        return;
    }

    Node *current = l->head;
    Node *prev = NULL;
    int counter = 0;
    while (current != NULL) {
        if (index == counter) {
            prev->next = new_node;
            new_node->next = current;
            return;
        }

        prev = current;
        current = current->next;
        counter++;
    }

    if (prev != NULL && index == counter + 1) {
        prev->next = new_node;
    }
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
