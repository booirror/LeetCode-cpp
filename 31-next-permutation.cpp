class Solution {  
public:  
    void nextPermutation(vector<int>& nums) {  
        int pivot = findPivot(nums);  
        int sidx = findPivotSuccessor(nums, pivot);  
        if (pivot >= 0) {  
            std::swap(nums[pivot], nums[sidx]);  
        }  
        reverseSuffix(nums, pivot+1);  
    }  
      
    int findPivot(vector<int>& nums)  
    {  
        for (int i = nums.size()-2; i >= 0; i--) {  
            if (nums[i] < nums[i+1]) {  
                return i;  
            }  
        }  
        return -1;  
    }  
      
    int findPivotSuccessor(vector<int>&nums, int pivot)  
    {  
        int pv = nums[pivot];  
        int idx = -1;  
        for (int i = pivot+1; i < nums.size(); i++) {  
            if (nums[i] > pv) {  
                if (idx == -1) {  
                    idx = i;  
                } else if (nums[idx] > nums[i]) {  
                    idx = i;  
                }  
            }  
        }  
        return idx;  
    }  
      
    void reverseSuffix(vector<int>& nums, int start)  
    {  
        std::sort(nums.begin()+start, nums.end());  
    }  
};  