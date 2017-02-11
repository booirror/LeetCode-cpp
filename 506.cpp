class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> vi(nums.begin(), nums.end());
        vector<string> vs;
        std::sort(nums.begin(), nums.end(), [](int a, int b){
           return a > b; 
        });
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++){
            map[nums[i]] = i;
        }
        for (int a : vi)
        {
            if (map[a] == 0) {
                vs.push_back("Gold Medal");
            } else if (map[a] == 1) {
                vs.push_back("Silver Medal");
            } else if (map[a] == 2) {
                vs.push_back("Bronze Medal");
            } else {
                vs.push_back(std::to_string(map[a] + 1));
            }
        }
        return vs;
    }
};