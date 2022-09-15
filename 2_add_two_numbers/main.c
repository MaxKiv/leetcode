#include <stddef.h>
#include <stdlib.h>

#include "2.c"
#include "ListNode.h"

int main() {

  struct ListNode* a1 = (struct ListNode*) malloc(sizeof(struct ListNode));
  struct ListNode* a2 = (struct ListNode*) malloc(sizeof(struct ListNode));
  struct ListNode* a3 = (struct ListNode*) malloc(sizeof(struct ListNode));

  a1->val = 2;
  a1->next = a2;
  a2->val = 4;
  a2->next = a3;
  a3->val = 3;
  a3->next = NULL;

  struct ListNode* b1 = (struct ListNode*) malloc(sizeof(struct ListNode));
  struct ListNode* b2 = (struct ListNode*) malloc(sizeof(struct ListNode));
  struct ListNode* b3 = (struct ListNode*) malloc(sizeof(struct ListNode));

  b1->val = 5;
  b1->next = b2;
  b2->val = 6;
  b2->next = b3;
  b3->val = 4;
  b3->next = NULL;

  printf("printing a1\n");
  printList(a1);
  printf("printing b1\n");
  printList(b1);
  fflush(stdout);

  struct ListNode* out = addTwoNumbers(a1, a2);
  printList(out);

}
