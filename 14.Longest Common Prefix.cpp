//本题思路较为简单，首先找出最短的字符串，pfefix不可能比它长，然后从第一个字符串开始逐个和后面的字符串对比，
//二者的字符不一样时终止，并把新的字符串赋值给prefix，还有另一种按照列比较的方法，也就是先对比vector中所有
//字符串的第一个字符，然后再对比所有字符串中的第二个字符，依次类推，其实这种方法复杂度和第一种一样的，并没有
//变快，实验也证明了这样的，两种算法的运行时间都是6ms
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";  //注意此处一定不能返回NULL
        int minLen = INT_MAX;
        for(int i=0; i<strs.size(); ++i){  //计算所有字符串中的最小值，减小运算量
            if(strs[i].size() < minLen)
                minLen = strs[i].size();
        }
        if(minLen == 0)  //最小值为0，则返回
            return "";
        string prefix(strs[0]);  //prefix先用第一个字符串赋值
        for(int i=1; i<strs.size(); ++i){  //对于从1开始的所有字符串
            int j = 0;
            //对比prefix[j]是否等于strs[i][j],是则继续，否则退出
            while(j<prefix.size() && j<strs[i].size() && j<minLen && (prefix[j] == strs[i][j]))
                ++j;
            if(j < 1)  //j=0说明第一个字符就没对比成功，可以直接返回空了
                return "";
            prefix=prefix.substr(0,j);  //将对比成功的j个字符赋值给prefix
        }
        return prefix;
    }
};
