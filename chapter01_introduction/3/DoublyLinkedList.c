#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNode {
  struct sNode* prev;
  struct sNode* next;
  char* string;
} Node;

/* 3 cases: append to prev / first item / append to end
 * - note: Node** list needed to update head of list
 *         If you just pass in Node* head, you cannot do so
 */
void insert(Node** list, Node* prev, const char* string) {
  Node* node = malloc(sizeof(Node));
  node->string = malloc(strlen(string) + 1);
  strcpy(node->string, string);

  // first try to append to prev
  if (prev != NULL) {
    node->next = prev->next;
    // point prev->next back to node, if not NULL
    if (prev->next != NULL)
      prev->next->prev = node;
    prev->next = node;
    node->prev = prev;
  } else {
    // node becomes head of list
    if (*list == NULL) {
      *list = node;
    } else { // append to head of list
      node->next = (*list)->next;
      if ((*list)->next != NULL)
        (*list)->next->prev = node;
      node->prev = (*list);
      (*list)->next = node;
    }
  }
}

Node* find(Node* head, const char* string) {
  while(head != NULL) {
    if (strcmp(head->string, string) == 0) {
      return head;
    }
    head = head->next; // ok to reassign copy of ptr
  }
  return NULL;
}

void delete(Node** list, Node* node) {
  if(node == NULL)
    return;

  // reassign ptrs
  if (node->next != NULL)
    node->next->prev = node->prev;
  if (node->prev != NULL)
    node->prev->next = node->next;

  // if deleting head, update list
  if (*list == node)
    *list = node->next;

  // free memory
  free(node->string);
  free(node);
}

void dump(Node* list) {
  while (list != NULL) {
    printf("%p [prev %p next %p] %s\n",
           list, list->prev, list->next, list->string);
    list = list->next;
  }
}

int main(void) {
  printf("Hello, World!\n");

  Node* list = NULL;
  insert(&list, NULL, "one");
  insert(&list, NULL, "four");
  insert(&list, find(list, "one"), "two");
  insert(&list, find(list, "two"), "three");
  dump(list);

  printf("-- delete three --\n");
  delete(&list, find(list, "three"));
  dump(list);

  printf("-- delete one --\n");
  delete(&list, find(list, "one"));
  dump(list);

  return 0;
}
