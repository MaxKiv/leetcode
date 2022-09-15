#include <stddef.h>
#include <stdlib.h>

#include "2.c"
#include "ListNode.h"

int main() {

  struct ListNode* a1 = (struct ListNode*) malloc(sizeof(struct ListNode));
  struct ListNode* a2 = (struct ListNode*) malloc(sizeof(struct ListNode));
  struct ListNode* a3 = (struct ListNode*) malloc(sizeof(struct ListNode));
  struct ListNode* a4 = (struct ListNode*) malloc(sizeof(struct ListNode));
  struct ListNode* a5 = (struct ListNode*) malloc(sizeof(struct ListNode));
  struct ListNode* a6 = (struct ListNode*) malloc(sizeof(struct ListNode));
  struct ListNode* a7 = (struct ListNode*) malloc(sizeof(struct ListNode));

  a1->val = 9;
  a1->next = a2;
  a2->val = 9;
  a2->next = a3;
  a3->val = 9;
  a3->next = a4;
  a4->val = 9;
  a4->next = a5;
  a5->val = 9;
  a5->next = a6;
  a6->val = 9;
  a6->next = a7;
  a7->val = 9;
  a7->next = NULL;

  struct ListNode* b1 = (struct ListNode*) malloc(sizeof(struct ListNode));
  struct ListNode* b2 = (struct ListNode*) malloc(sizeof(struct ListNode));
  struct ListNode* b3 = (struct ListNode*) malloc(sizeof(struct ListNode));
  struct ListNode* b4 = (struct ListNode*) malloc(sizeof(struct ListNode));

  b1->val = 9;
  b1->next = b2;
  b2->val = 9;
  b2->next = b3;
  b3->val = 9;
  b3->next = b4;
  b4->val = 9;
  b4->next = NULL;

  printf("printing a1\n");
  printList(a1);
  printf("printing b1\n");
  printList(b1);
  fflush(stdout);

  struct ListNode* out = addTwoNumbers(a1, b1);
  printf("output list and what it should be\n");
  printList(out);
  printf("\n8 9 9 9 0 0 0 1");

}
