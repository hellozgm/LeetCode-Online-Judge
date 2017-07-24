//本题十分巧妙，首先要弄清楚每个罗马数字所表示的int数字，然后其规律是对于罗马数字中的每一个字符，如果该字符对应的int数字大于或等于
//后面一个罗马字符所对应的int数字，则总数加上当前数字，否则减去当前数字。
//例如MMCCCXLIX 对应的int是2349，便满足这个规律
class Solution {
public:
    int romanToInt(string s) {
        if(s.size() == 0)
            return 0;
        unordered_map<char,int> sMap = {{'I',1},  //将罗马数字中每个字符所对于的int数字存储在哈希表中
                                        {'V',5},
                                        {'X',10},
                                        {'L',50},
                                        {'C',100},
                                        {'D',500},
                                        {'M',1000}};
        int ret = 0;
        ret = sMap[s[s.size()-1]];  //将最末尾的罗马字符转化为int数字
        for(int i = s.size()-2; i >=0; --i){  //从右向左遍历
            if(sMap[s[i]] < sMap[s[i+1]])  //是否当前罗马字符对于的int数字小于后面的一个？
                ret -= sMap[s[i]];  //是则减去当前int数字
            else
                ret += sMap[s[i]];  //否则加上当前int数字
        }
        return ret;
    }
};
