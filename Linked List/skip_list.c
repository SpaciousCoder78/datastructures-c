//skip list
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVEL 3

struct Node {
    int key;
    struct Node* forward[MAX_LEVEL+1];
};

struct SkipList {
    struct Node *header;
    int level;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->key = key;
    for(int i = 0; i <= MAX_LEVEL; i++) {
        newNode->forward[i] = NULL;
    }
    return newNode;
}

struct SkipList* createSkipList() {
    struct SkipList* list = (struct SkipList*) malloc(sizeof(struct SkipList));
    list->header = createNode(-1);
    list->level = 0;
    return list;
}

void insert(struct SkipList* list, int key) {
    struct Node* update[MAX_LEVEL+1];
    struct Node* current = list->header;

    for(int i = list->level; i >= 0; i--) {
        while(current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if(current == NULL || current->key != key) {
        int rlevel = rand() % (MAX_LEVEL+1);

        if(rlevel > list->level) {
            for(int i = list->level+1; i <= rlevel; i++) {
                update[i] = list->header;
            }
            list->level = rlevel;
        }

        struct Node* newNode = createNode(key);

        for(int i = 0; i <= rlevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

void display(struct SkipList* list) {
    printf("\n*****Skip List*****\n");
    for(int i = 0; i <= list->level; i++) {
        struct Node* node = list->header->forward[i];
        printf("Level %d: ", i);
        while(node != NULL) {
            printf("%d ", node->key);
            node = node->forward[i];
        }
        printf("\n");
    }
}

int main() {
    struct SkipList* list = createSkipList();
    int choice, key;

    while(1) {
        printf("\n1.Insert\n2.Display\n3.Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the key to insert: ");
                scanf("%d", &key);
                insert(list, key);
                break;
            case 2:
                display(list);
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}
