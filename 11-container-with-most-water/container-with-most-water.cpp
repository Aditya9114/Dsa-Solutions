class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int area;
        int ans = INT_MIN;
        while( left < right){
            int minimum = min(height[left],height[right]);
            area = (right-left) * minimum;
            ans = max(ans, area);
            if(minimum == height[left]){
                left ++;
            }
            else{
                right --;
            }
        }
        return ans;
    }
};