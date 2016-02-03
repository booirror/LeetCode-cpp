#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0) return INT_MAX;
		bool neg = (dividend>0 && divisor<0) || (dividend<0 && divisor>0);
		unsigned int u_dividend = dividend<0 ? -1 * dividend : dividend;
		unsigned int u_divisor = divisor<0 ? -1 * divisor : divisor;
		unsigned int res = 0;
		for (int i = 31; i >= 0; i--) {
			if ((u_dividend >> i) >= u_divisor) {
				res += (1 << i);
				u_dividend -= (u_divisor << i);
			}
		}
		if (neg) {
			if (res>(unsigned int)((1 << 31) + 1)) return INT_MAX;
			else return -1 * res;
		}
		else {
			if (res>INT_MAX) return INT_MAX;
			else return res;
		}
	}
};