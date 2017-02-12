class Solution {
public:
    string addStrings(string num1, string num2) {
        int eb = 0;
        int len = max(num1.size(), num2.size());
        vector<char> vc;
        char a, b;
        for (int i = 0; i < len; i++)
        {
            if (i < num1.size()) {
                a = num1[num1.size()-1-i];    
            } else {
                a = '0';
            }
            if (i < num2.size()) {
                b = num2[num2.size()-1-i];
            } else {
                b = '0';
            }
            
            int val = a - '0' + b - '0' + eb;
            eb = val / 10;
            char c = '0' + val % 10;
            vc.push_back(c);
        }
        if (eb > 0) {
            vc.push_back('0' + eb);
        }
        string result(vc.rbegin(), vc.rend());
        return result;
    }
};