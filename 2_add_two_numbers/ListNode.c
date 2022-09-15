#ifndef LISTNODE
#define LISTNODE

#include <stdio.h>

/* Definition of the singly-linked list. */
struct ListNode {
  int val;
  struct ListNode *next;
};

int printList(struct ListNode* node) {
  if(node == NULL) {
    return 1;
  }
  printf("%d ", node->val);
  return printList(node->next);
}

#endif
