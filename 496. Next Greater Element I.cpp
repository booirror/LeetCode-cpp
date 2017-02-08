class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        std::unordered_map<int, int> m;
        vector<int> vi;
        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            m[a] = i;
        }
        for (int i = 0; i < findNums.size(); i++)
        {
            int a = findNums[i];
            if (m.find(a) != m.end()) {
                int j = m[a]+1;
                while (j < nums.size())
                {
                    if (nums[j] > a) {
                        vi.push_back(nums[j]);
                        break;
                    }
                    j++;
                }
                if (j >= nums.size()) {
                    vi.push_back(-1);   
                }
            }
        }
        return vi;
    }
};