#define NO_OF_CHARS 256
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.length();
        int res= 0;
        vector<int> lastIndex(NO_OF_CHARS, -1);
        int i= 0;
        for(int j=0;j<n;j++){
            i= max(i, lastIndex[s[j]]+1);
            res= max(res, j-i+1);
            lastIndex[s[j]]=j;
        }
        return res;
    }
};
