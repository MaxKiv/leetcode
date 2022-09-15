#include <stddef.h>

#include "2.c"
#include "ListNode.h"

int main() {

  struct ListNode* l1c;
  l1c->val = 3;
  l1c->next = NULL;
  struct ListNode* l1b;
  l1b->val = 4;
  l1b->next = l1c;
  struct ListNode* l1a;
  l1a->val = 2;
  l1a->next = l1b;

  struct ListNode* l2c;
  l2c->val = 3;
  l2c->next = NULL;
  struct ListNode* l2b;
  l2b->val = 4;
  l2b->next = l2c;
  struct ListNode* l2a;
  l2a->val = 2;
  l2a->next = l2b;

  struct ListNode* out = addTwoNumbers(l1a, l2a);

}
