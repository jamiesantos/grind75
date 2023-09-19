#include <iostream>
#include <string>
#include <vector>

// Given an array of integers nums and an integer target, return indices
// of the two numbers such that they add up to target.
//
// You may assume that each input would have exactly one solution, and you
// may not use the same element twice.
//
// You can return the answer in any order.

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
	int idx1 = -1;
    int idx2 = -1;
    for (int i = 0; i < nums.size(); i++) {
      idx1 = i;
      int curr = nums[i];
      int diff = target - curr;
	  auto it = find(nums.begin(), nums.end(), diff);
      idx2 = it - nums.begin();
      if ((it != nums.end()) && (idx1 != idx2)) {
        // cout << idx1 << " " << idx2 << endl;
        break;
      }
    }
    return {idx1, idx2};
  }
};

int main() {
  Solution sol;
  vector<int> nums {3,3};
  int target = 6;
  sol.twoSum(nums,target);
  return 0;
}
