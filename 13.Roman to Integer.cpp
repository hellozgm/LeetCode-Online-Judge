class Solution {
public:
    int romanToInt(string s) {
        if(s.size() == 0)
            return 0;
        unordered_map<char,int> sMap = {{'I',1},
                                        {'V',5},
                                        {'X',10},
                                        {'L',50},
                                        {'C',100},
                                        {'D',500},
                                        {'M',1000}};
        int ret = 0;
        ret = sMap[s[s.size()-1]];
        for(int i = s.size()-2; i >=0; --i){
            if(sMap[s[i]] < sMap[s[i+1]])
                ret -= sMap[s[i]];
            else
                ret += sMap[s[i]];
        }
        return ret;
    }
};
