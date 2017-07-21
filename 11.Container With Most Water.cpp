//最大盛水量取决于两边中较短的那条边，而且如果将较短的边换为更短边的话，盛水量只会变少。所以我们可以用两个头尾指针，
//计算出当前最大的盛水量后，将较短的边向中间移，因为我们想看看能不能把较短的边换长一点。这样一直计算到左边大于右边为止就行了。
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxArea = 0;
        while(left < right){
		int curArea = min(height[left], height[right])*(right-left);  //计算当前面积
		if(curArea > maxArea)  //如果当前面积大于最大面积，则赋值
                	maxArea = curArea;
		if(height[left] < height[right])  //是否左端的值小于右端的值，这个很重要，我之前以为是左端的left和left+1对比，right和right-1对比，错误！
			++left;  //是则左端游标右移
		else
			--right;
        }
        return maxArea;
    }
};
