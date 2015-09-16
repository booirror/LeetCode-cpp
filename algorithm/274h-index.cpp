class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end(), [](int a, int b)->bool{


        return a > b;
        });
        int n = citations.size();
        for (int i = n-1; i >= 0; i--) {
           if (citations[i] >= i+1) {
               if (i == n-1) return n;
               if (citations[i+1] <= i+1) return i+1;
           }
        }
        return 0;
    }
};