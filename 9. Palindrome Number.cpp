//本题最为直接的方式是将x反转然后比较反转前后的值是否一致，但是这样会导致内存不是O(1)
//因此采用比较首尾数字是否一致的方法，这样不用额外空间
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)   //负数不是回文
            return false;
        int len = 1;
        while(x/len >= 10){    //计算x的长度，不是用通常的长度为len位这样的表示方法，而是len直接和x的长度相同，这样方便后面的操作。
            len *=10;          //还要注意一点，用x/len >=10表示，而不是x >=len*10 的方式是因为，当x极大的时候，10*len会溢出。
        }
        while(x > 0){
            if(x%10 != x/len)   //判断x的首尾数字是否一致
                return false;
            x = (x % len) / 10;   //x掐头去尾留中间，高明的方法
            len /=100;      //len缩小两位
        }
        return true;        
    }
};
