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
  for(int i = 0; l1->next != NULL || l2->next != NULL; i++){
    combined[i] = l1->val + l2->val;
    l1 = l1->next;
    l2 = l2->next;
  }
  max_print(combined, 101, sizeof(int));

  for(int i = 0; i < 100; i++) {
    if(combined[i] >= 10) {
      combined[i+1] += 1;
    }
    printf("combined[i] = %d", combined[i]);
    l1_og->val = combined[i];
    l1_og = l1_og->next;
  }
  return out;
}

