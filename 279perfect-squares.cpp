class Solution {
public:

    bool isSquare(int n) {
        int a = (int)sqrt(n);
        return a*a == n;
    }
    int numSquares(int n) {
        while ((n & 3) == 0) {
            n = n / 4;
        }
        if ((n & 7) == 7) return 4;
        if (isSquare(n)) return 1;
        int sq = (int) sqrt(n);
        for (int i = 1; i <=sq; i++) {
            if (isSquare(n -i*i))
                return 2;
        }
        return 3;
    }
};