#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

class NumArray {
public:
	NumArray(vector<int> &nums) :array(nums){
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			sumArray.push_back(sum);
		}
	}

	int sumRange(int i, int j) {
		return sumArray[j] - sumArray[i] + array[i];
	}

	vector<int> sumArray;
	vector<int> &array;
};

void numArrayTest()
{
	vector<int> vi = { -2, 0, 3, -5, 2, -1 };
	NumArray num(vi);
	cout << num.sumRange(0, 2);
	cout << num.sumRange(2, 5);
	cout << num.sumRange(0, 5);
}