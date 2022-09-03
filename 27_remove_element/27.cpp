#include<algorithm>
#include<iostream>
#include<vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
      auto it = std::remove(nums.begin(), nums.end(), val);
      return (it - nums.begin());
    }
};

int main() {
  
  Solution sol;
  std::vector<int> nums {1,2,3,2,1};
  int val = 2;

  int out = sol.removeElement(nums, val);
  std::cout << out << std::endl;

}
