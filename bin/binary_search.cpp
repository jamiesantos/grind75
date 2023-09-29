#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = nums.size() / 2;
        int upper = nums.size();
        int lower = 0;
        int idx_old = -1;
        while(nums[idx] != target) {
          if (nums[0] == target) return 0;

          if (nums[idx] < target) {
            lower = idx;
            idx_old = idx;
            idx = (upper - idx)/2 + idx;
          } else {
            upper = idx;
            idx_old = idx;
            idx = lower/2;
          }
          if (idx == nums.size() || idx_old == idx) return -1;
        }
        return idx;
    }
};

int main() {
  Solution sol;
  vector<int> nums{ -1,0,3,5,9,1 };
  int index = sol.search(nums,0);
  cout << index << endl;
  return 0;
}
