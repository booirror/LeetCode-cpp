#include <iostream>
#include <string>
#include <vector>
using namespace std;

string stringAdd(const string& a, const string& b)
{
	int asize = a.length();
	int bsize = b.length();
	int max = asize > bsize ? asize : bsize;
	int m = 0;
	string newb;
	string newa;
	if (asize > bsize) {
		newb = string(asize - bsize, '0');
		newb.append(b);
		newa = a;
	}
	else if (asize < bsize) {
		newa = string(bsize - asize, '0');
		newa.append(a);
		newb = b;
	}
	else {
		newa = a;
		newb = b;
	}
	vector<char> result = vector<char>(max + 1);
	for (int i = max - 1; i >= 0; --i)
	{
		int c = (newa[i] + newb[i] + m - 2 * '0');
		m = c / 10;
		char v = c % 10 + '0';
		result[max-1-i] = v;
	}
	result[max] = ('0' + m);
	string s = string(result.rbegin(), result.rend());
	if (s[0] == '0')
		return s.substr(1);
	return s;
}

bool isAdditiveNumber(string num)
{
	int size = num.length();
	for (int j = 1; j <= size - 2; ++j)
	{
		string a = num.substr(0, j);
		if (a[0] == '0' && j > 1)
			continue;
		for (int k = 1; k <= size - 1; ++k) {
			string b = num.substr(j, k);
			if (a[0] == '0' && k > 1)
				continue;
			string result = stringAdd(a, b);
			if (j + k + result.length() > size)
				continue;
			string val = num.substr(j + k, result.length());
			int pass = j + k;
			string aa;
			while (result.compare(val) == 0)
			{
				pass += val.length();
				if (size == pass)
					return true;
				aa = b;
				b = result;
				result = stringAdd(aa, b);
				val = num.substr(pass, result.length());
			}
		}
	}
	return false;
}


void number_main()
{
	cout << isAdditiveNumber("111122335588143") << endl;
}

