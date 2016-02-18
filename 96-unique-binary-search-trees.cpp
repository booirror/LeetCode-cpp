class Solution {
public:
    int numTrees(int n) {
        vector<int> temp(n);
        return numTrees(n, temp);
    }
    
    int numTrees(int n, vector<int>& vec)
    {
        if (n <= 1) return 1;
        if (vec[n-1] > 0) return vec[n-1];
        int count = 0;
        for (int i = 1; i <= n; i++) {
            count += numTrees(i-1, vec) * numTrees(n-i, vec);
        }
        vec[n-1] = count;
        return count;
    }
};