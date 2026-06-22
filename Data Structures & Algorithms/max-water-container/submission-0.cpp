class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxWater = INT_MIN;
        int left = 0;
        int right = heights.size()-1;
        while(left < right){
            int area = min(heights[left],heights[right]) * (right-left);
            maxWater = max(area,maxWater);
            if(heights[left] < heights[right]){
                left++;
            }else{
                right--;
            }
        }

        return maxWater;
    }
};
