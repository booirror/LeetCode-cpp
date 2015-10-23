class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        for (int i = 0; i < n; i++) {
           if (citations[i] >= n - i) {
               if (i == 0) return n;
               if (citations[i-1] <= n-i) return n-i;
           }
        }
        return 0;
    }
};