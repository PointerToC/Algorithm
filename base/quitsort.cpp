#include <bits/stdc++.h>

void quick_sort(std::vector<int> &nums, int left, int right);
int partition(std::vector<int> &nums, int left, int right);

int main() {
  std::vector<int> nums = {2, 3, 3, 2, 3, 3, 2, 3, 3};
  quick_sort(nums, 0, nums.size() - 1);
  for (auto num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
  return 0;
}

void quick_sort(std::vector<int> &nums, int left, int right) {
  if (left >= right) {
    return;
  }
  int pivot = partition(nums, left, right);
  quick_sort(nums, left, pivot - 1);
  quick_sort(nums, pivot + 1, right);
}

// 循环不变式证明参见'算法导论'
int partition(std::vector<int> &nums, int left, int right) {
  int pivot = nums[right];
  int l = left - 1;
  for (int i = left; i < right; ++i) {
    if (nums[i] <= pivot) {
      ++l;
      std::swap(nums[l], nums[i]);
    }
  }
  std::swap(nums[l + 1], nums[right]);
  return l + 1;
}
