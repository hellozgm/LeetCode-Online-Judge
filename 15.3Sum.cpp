//本题关键在于如何处理j,k的比较问题，要引入左右夹逼的方法，这样让复杂度降为O(n^2)，同时要十分注意防止重复的问题，
//利用提前判断的方法，从根源上防止重复发生。
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());  // 先排序
        for(auto i=nums.begin(); i<nums.end()-2; ++i){  // 遍历i
            while(i>nums.begin() && *i==*(i-1))  // 如果当前数字和前一个重复，则跳过，注意用if是不行的，if，continue可以代替while
                ++i;
            auto j = i+1, k = nums.end()-1;  //设置j,k的初始位置
            while(j < k){  //保证j<k
                if(*i + *j + *k < 0)  //如果和小于0则++j,其实在这后面加不加判断当前数字是否和前面的数字相等，都一样
                    ++j;
                else if(*i + *j + *k > 0)  //同理
                    --k;
                else{
                    result.push_back({*i,*j,*k});  //和为0，则将每一个都存到结果中
                    ++j;  //++j和--k必须都运行，因为单纯的j或k还有可能重复
                    --k;
                    while(j<k && *j==*(j-1) && *k==*(k+1))  //防止重复情况发生
                        ++j;
                }
            }
        }
        return result;
    }
};
