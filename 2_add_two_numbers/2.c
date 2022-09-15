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
  for(;l1->next != NULL && l2->next != NULL; i++){
    combined[i] = l1->val + l2->val;
    l1 = l1->next;
    l2 = l2->next;
  }

  printf("size of list found: %d\n", i);
  max_print(combined, i, sizeof(int));

  for(int j = 0; j < i; j++) {
    //TODO why is combined[i] = 6 and why is size 1 found?
    printf("combined[i] = %d ", combined[j]);
    if(combined[j] >= 10) {
      combined[j+1] += 1;
    }
    printf("Inserting into out: %d\n", combined[j]);
    l1_og->val = combined[j];
    l1_og = l1_og->next;
  }
  return out;
}

