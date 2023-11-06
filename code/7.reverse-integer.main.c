/// Category: algorithms
/// Level: Medium
/// Percent: 27.822197%



 /// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2³¹, 2³¹ - 1], then return 0.
 /// 
 /// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 /// 
 ///  
 /// Example 1:
 /// 
 /// Input: x = 123
 /// Output: 321
 /// 
 /// 
 /// Example 2:
 /// 
 /// Input: x = -123
 /// Output: -321
 /// 
 /// 
 /// Example 3:
 /// 
 /// Input: x = 120
 /// Output: 21
 /// 
 /// 
 ///  
 /// Constraints:
 /// 
 /// 
 /// 	-2³¹ <= x <= 2³¹ - 1
 /// 

#include <stdio.h>
#include "7.reverse-integer.c"

int main(){

  printf("7 reverse integer");
  printf("reverse(123) = %d\n",reverse(123));
  printf("reverse(-321) = %d\n",reverse(-321));
  printf("reverse(120) = %d\n",reverse(120));
  printf("reverse(1534236469) = %d\n",reverse(1534236469));
  printf("reverse(-2147483412) = %d\n",reverse(-2147483412));
  printf("reverse(1463847412) = %d\n",reverse(1463847412));


}
