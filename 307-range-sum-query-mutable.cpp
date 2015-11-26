#include <iostream>
#include <vector>

using namespace std;

class NumArray2 {
public:
	NumArray2(vector<int> &nums) :vnums(nums){
		this->minMod = 0;
		sums.resize(nums.size());
	}

	void update(int i, int val) {
		this->vnums[i] = val;
		minMod = i;
	}

	int sumRange(int i, int j) {
		if (j >= minMod) {
			sum(minMod, j);
			minMod = j + 1;
		}
		if (i == 0) {
			return sums[j];
		}
		else {
			return sums[j] - sums[i - 1];
		}
	}

private:
	void sum(int s, int e)
	{
		if (s == 0)
		{
			sums[0] = vnums[0];
			s = s + 1;
		}
		for (int i = s; i <= e; ++i)
		{
			sums[i] = sums[i - 1] + vnums[i];
		}
	}

	vector<int>& vnums;
	vector<int> sums;
	int minMod = 0;
};

void numArrayMutableTest()
{
	vector<int> nums = { 1, 3, 5 };
	 NumArray2 numArray(nums);
	 cout << numArray.sumRange(0, 2) << endl;
	 numArray.update(1, 2);
	 cout << numArray.sumRange(0, 2) << endl;
}