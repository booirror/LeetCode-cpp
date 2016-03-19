/**
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int begin = 0;
		int end = nums.size()-1;
		vector<int> vs;
		while (begin <= end) {
			int mid = (begin + end) / 2;
			if (nums[mid] == target) {
				int min = mid;
				while (min >= 0 && nums[mid] == nums[min])
					min--;
				int max = mid;
				while (max <= end && nums[mid] == nums[max]) {
					max++;
				}
				vs.push_back(min+1);
				vs.push_back(max - 1);
				return vs;
			}
			else if (nums[mid] > target) {
				end = mid - 1;
			}
			else {
				begin = mid + 1;
			}
		}
		vs.push_back(-1);
		vs.push_back(-1);
		return vs;
	}
};