#ifndef LISTNODE
#define LISTNODE

#include <stdio.h>

/* Definition of the singly-linked list. */
struct ListNode {
  int val;
  struct ListNode *next;
};

void printList(struct ListNode* node) {
  while(node != NULL) {
    printf("%d ", node->val);
    node = node->next;
  }
  printf("\n");
}

#endif
