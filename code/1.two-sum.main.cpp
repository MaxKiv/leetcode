#include <vector>
#include <iostream>

#include "1.two-sum.cpp"

int main() {
  std::vector<int> nums {2,7,11,15};
  int target = 9;
  Solution solution;
  auto out = solution.twoSum(nums, target);
  for (const auto & el : out) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}
