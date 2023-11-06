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
#include <stdint.h>

const int32_t MAX = INT32_MAX / 10;
const int32_t MIN = INT32_MIN / 10;

int reverse(int x){
  int out = 0;

  while (x) {
    if (out > MAX || out < MIN) {
      return 0;
    }
    out *= 10;
    out += x % 10;
    x /= 10;
  }

  return out;
}
