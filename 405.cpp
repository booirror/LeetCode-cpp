#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	char* hex = "0123456789abcdef";
	string toHex(int num) {
		return toHexEx(num);
	}

	string toHexEx(unsigned int num) {
		string s;
		if (num > 15) {
			unsigned int sub = num % 16;
			s += hex[sub];
			return toHexEx(num >> 4) + s;
		}
		else {
			s += hex[num];
			return s;
		}
	}
};

void main_405()
{
	Solution s;
	string ss = s.toHex(26);

	std::cout << ss << std::endl;
}