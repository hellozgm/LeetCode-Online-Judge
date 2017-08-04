class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());
        for(auto i=nums.begin(); i<nums.end()-2; ++i){
            while(i>nums.begin() && *i==*(i-1))
                ++i;
            auto j = i+1, k = nums.end()-1;
            while(j < k){
                if(*i + *j + *k < 0)
                    ++j;
                else if(*i + *j + *k > 0)
                    --k;
                else{
                    result.push_back({*i,*j,*k});
                    ++j;
                    --k;
                    while(j<k && *j==*(j-1) && *k==*(k+1))
                        ++j;
                }
            }
        }
        return result;
    }
};
