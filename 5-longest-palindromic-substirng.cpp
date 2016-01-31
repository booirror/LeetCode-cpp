#include <iostream>
#include <string>
using namespace std;

void getPalindrome(string& s, int left, int right, int &out1,int &out2)
{
	if (left < right && s[left] != s[right]) {
		out1 = out2 = left;
		return;
	}
	int size = s.size();
	while (left > 0 && (right + 1 < size) && s[left-1] == s[right+1]) {
		left--;
		right++;
	}
	out1 = left;
	out2 = right;
}

string longestPalindrome(string s) {
	int size = s.size();
	int left = 0;
	int len = 1;
	for (int i = 0; i < size; i++) {
		int l, r;
		getPalindrome(s, i, i, l, r);
		if (r - l+1 > len) {
			len = r - l + 1;
			left = l;
		}
		getPalindrome(s, i, i+1, l, r);
		if (r > l && r - l + 1 > len) {
			len = r - l + 1;
			left = l;
		}
	}
	return s.substr(left, len);
}

int longestpalindrome_test()
{
	string s = "ccc";
	cout << longestPalindrome(s) << endl;
	return 0;
}

