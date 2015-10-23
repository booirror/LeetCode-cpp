class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        unsigned int x = m ^ n;
        x |= x >> 1, x |= x >> 2, x |= x >> 4, x |= x >> 8, x |= x >> 16;
        return m & ~x;  
    }
};