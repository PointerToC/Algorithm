#include <bits/stdc++.h>

int left(int i);
int right(int i);
void max_heapify(std::vector<int> &nums, int idx, int sz);
void build_heapify(std::vector<int> &nums);
void heap_sort(std::vector<int> &nums);

int main() {
  std::vector<int> nums = {0, 2, 1, 5, 4, 9};
  heap_sort(nums);
  for (int i = nums.size() - 1; i >= 1; --i) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}


void max_heapify(std::vector<int> &nums, int idx, int sz) {
  int l = left(idx);
  int r = right(idx);

  int largest = idx;
  if (l <= sz && nums[l] > nums[largest]) {
    largest = l;
  }

  if (r <= sz && nums[r] > nums[largest]) {
    largest = r;
  }

  if (largest != idx) {
    std::swap(nums[idx], nums[largest]);
    max_heapify(nums, largest, sz);
  }
}

inline int left(int i) {
  return i * 2;
}

inline int right(int i) {
  return i * 2 + 1;
}

void build_heapify(std::vector<int> &nums) {
  int n = nums.size() - 1;
  for (int i = n / 2; i >= 1; --i) {
    max_heapify(nums, i, n);
  }
}

void heap_sort(std::vector<int> &nums) {
  build_heapify(nums);
  for (int i = nums.size() - 1; i > 1; --i) {
    std::swap(nums[1], nums[i]);
    max_heapify(nums, 1, i - 1);
  }
}
