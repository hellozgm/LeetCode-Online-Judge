//本题重点是将罗马数字的每个重要的位数都保存在数组中，然后对于num中的每一位都去数组中查找对应的罗马数字。
class Solution {
public:
    string intToRoman(int num) {
        string roma[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",  //将每一位的0~9都存储在数组中，以待后面查找
                         "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",  //用一维数组代替二维数组，因为string没有二维数组。
                         "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
                         "", "M", "MM", "MMM"};
        string ret;
        int cnt = 0;  //模拟二维数组的某一行
        while(num != 0){
            ret.insert(0,roma[cnt*10+num%10]);  //cnt*10+num%10表示当前位数的数字对应的罗马数字，然后再ret的开头插入即可
            num /= 10;
            ++cnt;  //模拟二维数组的下一行
        }
        return ret;
    }
};
