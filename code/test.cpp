#include <algorithm>
#include <vector>
#include <ranges>
#include <iostream>

using std::vector;

int main() {
  std::vector<int> nums {2,7,11,15};
  for (const auto & el : nums | std::ranges::views::take(2)) {
    std::cout << el;
  }
}

