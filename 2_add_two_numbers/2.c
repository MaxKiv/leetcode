#include <stddef.h>
#include <math.h>
#include <stdio.h>

#include "util.h"
#include "ListNode.h"

/* Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
*/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  int combined[101] = {-1};
  struct ListNode* l1_og = l1;
  struct ListNode* out = l1;
  int i = 0;
  
  printf("Starting LinkedList iteration\n");
  for(;l1 != NULL || l2 != NULL; i++){
    printf("L1 val: %d\tnext %x\n", l1->val, l1->next);
    printf("L2 val: %d\tnext %x\n", l2->val, l2->next);
    int l1val = l1 == NULL ? 0 : l1->val;
    int l2val = l2 == NULL ? 0 : l2->val;
    combined[i] = l1->val + l2->val;
    l1 = l1->next;
    l2 = l2->next;
  }

  printf("size of list found: %d\n", i);
  max_print(combined, i, sizeof(int));

  for(int j = 0; j < i; j++) {
    printf("combined[i] = %d ", combined[j]);
    if(combined[j] >= 10) {
      combined[j] -= 10;
      combined[j+1] += 1;
    }
    printf("Inserting into out: %d\n", combined[j]);
    l1_og->val = combined[j];
    l1_og = l1_og->next;
  }
  return out;
}

