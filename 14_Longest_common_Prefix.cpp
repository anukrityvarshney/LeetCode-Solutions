class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        
        for(int i = 0;i<strs[0].length();++i){
            for(const auto& temp: strs){
                if(i>=temp.length()||strs[0][i]!= temp[i]){
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];    
    }
};
