#include <vector>
#include <iostream>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
	vector<int> result;
	int curr = 1;
	for (int i = 0; i < nums.size(); ++i) {
		result.push_back(curr);
		curr = curr * nums[i];
	}

	curr = 1;
	for (int i = nums.size() - 1; i >= 0; --i)
	{
		result[i] = result[i] * curr;
		curr = curr * nums[i];
	}
	return result;
}

void productTest()
{
	vector<int> vec = { 1, 2, 3, 4 };
	vector<int> res = productExceptSelf(vec);
	for (auto i : res) {
		std::cout << i << std::endl;
	}
}