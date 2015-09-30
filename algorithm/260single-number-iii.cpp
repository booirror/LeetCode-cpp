vector<int> singleNumber(vector<int>& nums) {
    int aXorb = 0; 
    for (auto item : nums) aXorb ^= item;
    int lastBit = (aXorb & (aXorb - 1)) ^ aXorb;
    int intA = 0, intB = 0;
    for (auto item : nums) {
        if (item & lastBit) intA = intA ^ item;
        else intB = intB ^ item;
    }
    return vector<int>{intA, intB};   
}