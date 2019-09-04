#include <stdio.h>
#include <stdlib.h>

struct list_node {
    int data;
    struct list_node *next, *prev;
};

typedef struct list_node list_node;

struct int_linked_list {
    struct list_node *head, *tail;
};

typedef struct int_linked_list int_linked_list;

// Returns a pointer to the node at index @idx in the linked list pointed to by
// @list. If @idx is outside the bounds of @list, the behaviour is undefined.
list_node *node_at(int_linked_list *list, int idx) {
    if (idx == -1)
        return NULL;
    list_node *ret = list->head;
    while (idx--)
        ret = ret->next;
    return ret;
}

// Returns the integer value at index @idx in the linked list pointed to by
// @list. If @idx is outside the bounds of @list, the behaviour is undefined.
int val_at(int_linked_list *list, int idx) {
    return node_at(list, idx)->data;
}

// Creates a new node holding value @val and prepends it to the linked list
// pointed to by @list.
void push_front(int_linked_list *list, int val) {
    list_node *new_node = malloc(sizeof(list_node));
    new_node->data = val, new_node->prev = NULL, new_node->next = list->head;
    if (list->head == NULL)
        list->head = list->tail = new_node;
    else
        list->head->prev = new_node, list->head = new_node;
}

// Creates a new node holding value @val and appends it to the linked list
// pointed to by @list.
void push_back(int_linked_list *list, int val) {
    list_node *new_node = malloc(sizeof(list_node));
    new_node->data = val, new_node->prev = list->tail, new_node->next = NULL;
    if (list->tail == NULL)
        list->head = list->tail = new_node;
    else
        list->tail->next = new_node, list->tail = new_node;
}

// Creates a new node holding value @val and inserts it at after node @node in
// the linked list pointed to by @list. If @node is not a node from @list, the
// behaviour is undefined.
void insert_node(int_linked_list *list, list_node *node, int val) {
    if (node == NULL) {
        push_front(list, val);
        return;
    }
    if (node == list->tail) {
        push_back(list, val);
        return;
    }
    list_node *new_node = malloc(sizeof(list_node));
    new_node->data = val, new_node->prev = node, new_node->next = node->next;
    node->next->prev = new_node, node->next = new_node;
}

// Creates a new node holding value @val and inserts it in index @idx in the
// linked list pointed to by @list. If @idx is outside the bounds of @list, the
// behaviour is undefined.
void insert_at(int_linked_list *list, int idx, int val) {
    insert_node(list, node_at(list, idx - 1), val);
}

// Removes the head of the linked list pointed to by @list.
// If @list is already empty, the behaviour is undefined.
void pop_front(int_linked_list *list) {
    if (list->head == list->tail) {
        free(list->head);
        list->head = list->tail = NULL;
    } else {
        list->head = list->head->next;
        free(list->head->prev);
        list->head->prev = NULL;
    }
}

// Removes the tail of the linked list pointed to by @list.
// If @list is already empty, the behaviour is undefined.
void pop_back(int_linked_list *list) {
    if (list->head == list->tail) {
        free(list->head);
        list->head = list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
        free(list->tail->next);
        list->tail->next = NULL;
    }
}

// Removes the node pointed to by @node from the linked list pointed to by
// @list. If @node is not a node from @list, the behaviour is undefined.
void pop_node(int_linked_list *list, list_node *node) {
    if (node == list->head) {
        pop_front(list);
        return;
    }
    if (node == list->tail) {
        pop_back(list);
        return;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
}

// Removes the node at index @idx from the linked list pointed to by @list.
// If @idx is outside the bounds of @list, the behaviour is undefined.
void pop_at(int_linked_list *list, int idx) {
    pop_node(list, node_at(list, idx));
}

// Clears the linked list pointed to by @list.
void clear(int_linked_list *list) {
    while (list->head != NULL)
        pop_node(list, list->head);
}

// Prints the elements of the linked list pointed to by @list on one line.
void print_list(const int_linked_list *arg) {
    for (const list_node *itr = arg->head; itr != NULL; itr = itr->next)
        printf("%d ", itr->data);
    printf("\n");
}

int main(int argc, char *argv[]) {
    int_linked_list list;
    list.head = list.tail = NULL;
    while (1) {
        char type;
        scanf("%c", &type);
        if (type == 'i') {
            int idx, val;
            scanf("%d %d", &idx, &val);
            insert_at(&list, idx, val);
        }
        if (type == 'd') {
            int idx;
            scanf("%d", &idx);
            pop_at(&list, idx);
        }
        print_list(&list);
    }
    clear(&list);
    return 0;
}