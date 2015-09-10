class Solution {
public:
    int lengthOfLongestSubstring(string s) {
  int max = 0;
  int flag[256];
  memset(flag, 0, 256*sizeof(int));
  int i = 0;
  int len = 0;
  while (i < s.size()) {
  int k = i;
  while (flag[s[k]] == 0) {
  len++;
  flag[s[k]] = len;
  k++;
  if (k >= s.size()) goto OK;
  } 
  {
  if (max < len) {
  max = len;
  }
  i = i + flag[s[i]];
  len = 0;
  memset(flag, 0, 256*sizeof(int));
  }
  }
  OK:
  if (max < len) max = len;
  return max;
    }
};