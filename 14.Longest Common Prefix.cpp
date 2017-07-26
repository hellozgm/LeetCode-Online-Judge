class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        int minLen = INT_MAX;
        for(int i=0; i<strs.size(); ++i){
            if(strs[i].size() < minLen)
                minLen = strs[i].size();
        }
        if(minLen == 0)
            return "";
        string prefix(strs[0]);
        for(int i=1; i<strs.size(); ++i){
            int j = 0;
            while(j<prefix.size() && j<strs[i].size() && j<minLen && (prefix[j] == strs[i][j]))
                ++j;
            if(j < 1)
                return "";
            prefix=prefix.substr(0,j);
        }
        return prefix;
    }
};
