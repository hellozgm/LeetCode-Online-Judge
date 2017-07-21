class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxArea = 0;
        while(left < right){
			int curArea = min(height[left], height[right])*(right-left);
			if(curArea > maxArea)
                maxArea = curArea;
			if(height[left] < height[right])
				++left;
			else
				--right;
        }
        return maxArea;
    }
};
