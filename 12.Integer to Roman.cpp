class Solution {
public:
    string intToRoman(int num) {
        string roma[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
                         "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
                         "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
                         "", "M", "MM", "MMM"};
        string ret;
        int cnt = 0;
        while(num != 0){
            ret.insert(0,roma[cnt*10+num%10]);
            num /= 10;
            ++cnt;
        }
        return ret;
    }
};
