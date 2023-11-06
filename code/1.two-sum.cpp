#include <algorithm>
#include <vector>
#include <ranges>

using std::vector;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    nums | std::ranges::views::filter([&target](int a){return a <= target;});
    return nums;
  }
};
