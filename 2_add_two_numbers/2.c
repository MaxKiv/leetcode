#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
  
  /* printf("Starting LinkedList iteration\n"); */
  for(;l1 != NULL || l2 != NULL; i++){

    int l1val;
    struct ListNode* l1next;
    if(l1 != NULL) {
      l1val = l1->val;
      l1next = l1->next;
    } else {
      l1val = 0;
      l1next = 0;
    }
    /* printf("L1 val: %d\tnext %x\t", l1val, l1next); */

    int l2val;
    struct ListNode* l2next;
    if(l2 != NULL) {
      l2val = l2->val;
      l2next = l2->next;
    } else {
      l2val = 0;
      l2next = 0;
    }
    /* printf("L2 val: %d\tnext %x\t", l2val, l2next); */

    combined[i] = l1val + l2val;
    /* printf("Combined: %d\n", combined[i]); */
    l1 = l1 == NULL ? l1 : l1->next;
    l2 = l2 == NULL ? l2 : l2->next;
  }
  /* printf("size of list found: %d\n", i); */
  /* max_print(combined, i, sizeof(int)); */

  for(int j = 0; j < i; j++) {

    /* printf("combined[%d] = %d ", j, combined[j]); */
    if(combined[j] >= 10) {
      combined[j] -= 10;
      combined[j+1] += 1;
      // last list item >10 edge case
      if(j == i-1) {
        i++;
      }
    }

    /* printf("Inserting into out: %d\n", combined[j]); */
    l1_og->val = combined[j];

    if(l1_og->next == NULL && (j != i -1)) {
      struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
      node->next = NULL;
      node->val = 999;
      l1_og->next = node;
    }
    l1_og = l1_og->next;
  }

  return out;
}


