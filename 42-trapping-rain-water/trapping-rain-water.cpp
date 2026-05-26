class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int leftMax=0, rightMax=0;
        int start=0, end= height.size()-1;

        while(start<end){
            leftMax=max(leftMax, height[start]);
            rightMax=max(rightMax, height[end]);
            
            // ans += min(leftMax, rightMax)-height[i]; // i -> start|end
            if(leftMax<rightMax){
                ans += leftMax-height[start];
                start++;
            }
            else{
                ans += rightMax-height[end];
                end--;
            }
        }

        return ans;
    }
};