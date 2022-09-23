#include <stdio.h>

#include "9.c"

int run5() {
  int a = 5;
  bool answer = true;
  bool out = isPalindrome(a);
  if(out == answer) {
    return 1;
  } else {
    return 0;
  }
}

int run4() {
  int a = 10;
  bool answer = false;
  bool out = isPalindrome(a);
  if(out == answer) {
    return 1;
  } else {
    return 0;
  }
}

int run3() {
  int a = -121;
  bool answer = false;
  bool out = isPalindrome(a);
  if(out == answer) {
    return 1;
  } else {
    return 0;
  }
}

int run2() {
  int a = 123;
  bool answer = false;
  bool out = isPalindrome(a);
  if(out == answer) {
    return 1;
  } else {
    return 0;
  }
}

int run1() {
  int a = 121;
  bool answer = true;
  bool out = isPalindrome(a);
  if(out == answer) {
    return 1;
  } else {
    return 0;
  }
}

int runTests() {

  int t1 = run1();
  printf("test1: %d", t1);

  int t2 = run1();
  printf("test2: %d", t2);

  int t3 = run1();
  printf("test3: %d", t3);

  int t4 = run1();
  printf("test4: %d", t4);

  int t5 = run1();
  printf("test5: %d", t5);

  int out = 1;
  out *= t1;
  out *= t2;
  out *= t3;
  out *= t4;
  out *= t5;
  return out;
}

int main() {
  if(runTests()) {
    printf("~~~~ PASSED ~~~~");
  }
  return 0;
}
