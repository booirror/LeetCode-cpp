#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void twoSum(vector<int>& nums, int target, int start, int end, vector<vector<int>>& vvi, int z1, int z2)
{
	if (start >= end) {
		return;
	}
	if (2 * nums[start] > target || 2 * nums[end] < target) {
		return;
	}
	int i = start;
	int j = end;
	int sum, x;
	while (i < j) {
		sum = nums[j] + nums[i];
		if (sum == target) {
			vvi.push_back(vector<int> {z1, z2, nums[i], nums[j]});
			x = nums[i];
			while (++i < j && nums[i] == x) {
				;
			}
			x = nums[j];
			while (--j > i && nums[j] == x) {
				;
			}
		}
		else if (sum < target) {
			i++;
		}
		else {
			j--;
		}
	}
}

void threeSum(vector<int>& nums, int target, int start, int end, vector<vector<int>>& vvi, int z1)
{
	if (start + 1 >= end) return;
	int max = nums[end];
	if (3 * nums[start] > target || 3 * max < target) {
		return;
	}
	int i, z;
	for (i = start; i < end - 1; i++) {
		z = nums[i];
		if (i > start && nums[i - 1] == z) {
			continue;
		}
		if (z + 2 * max < target) {
			continue;
		}
		if (3 * z > target) {
			break;
		}
		if (3 * z == target) {
			if (i + 1 < end && nums[i + 2] == z) {
				vvi.push_back(vector<int>{z1, z, z, z});
			}
			break;
		}
		twoSum(nums, target - z, i + 1, nums.size() - 1, vvi, z1, z);
	}
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> vvi;

	if (nums.size() < 4) {
		return vvi;
	}
	std::sort(nums.begin(), nums.end());
	int max = nums[nums.size() - 1];
	if (4 * nums[0] > target || 4 * max < target)
		return vvi;
	int i, z;
	for (i = 0; i < nums.size(); i++) {
		z = nums[i];
		if (i > 0 && z == nums[i - 1]) {
			continue;
		}
		if (z + 3 * max < target) {
			continue;
		}
		if (z * 4 > target) {
			break;
		}
		if (4 * z == target) {
			if (i + 3 < nums.size() && nums[i + 3] == z) {
				vvi.push_back(vector<int>{
					z, z, z, z
				});
			}
			break;
		}
		threeSum(nums, target - z, i + 1, nums.size() - 1, vvi, z);
	}
	return vvi;
}

int test4Sum()
{
	vector<int> S = { 1,0 ,-1 ,0 ,-2,2 };
	int target = 0;
	vector<vector<int>> vvi  = fourSum(S, target);
	for (auto& vi : vvi) {
		for (auto& v : vi) {
			cout << v << ' ';
		}
		cout << endl;
	}
	return 0;
}