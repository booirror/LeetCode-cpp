class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>& vec = nums;
        int np = 0;
    int zp = 0;
    while (zp < vec.size() && np < vec.size()) {
    while (vec[zp] != 0 ) zp++;
    while (vec[np] == 0 || np <= zp) np++;
    if (zp >= vec.size() || np >= vec.size()) {
    break;
    }
    std::swap(vec[zp], vec[np]);
    zp++; np++;
    }
    }
};