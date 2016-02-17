class Solution {
public:
    bool isPowerOfThree2(int n) {
        if (n == 1) {
            return true;
        } else if (n >= 3)
        {
            int val = n % 3;
            if (val != 0) {
                return false;
            }
            return isPowerOfThree2(n/3); 
        }
        return false;
    }
    
    bool isPowerOfThree(int n) {
        return (n > 0 && 1162261467 % n == 0);
    }
};