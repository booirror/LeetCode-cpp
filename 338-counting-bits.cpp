#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> result(num + 1);
		result[0] = 0;
		int i;
		for (i = 1; i <= 2; i++)
			result[i] = 1;
		for (i = 3; i <= num; i++){
			result[i] = result[i / 2] + result[i % 2];
		}
		return result;
	}
};

void testCountBits()
{
	Solution s;
	auto c = s.countBits(0);
	cout << c[0] << endl;
}