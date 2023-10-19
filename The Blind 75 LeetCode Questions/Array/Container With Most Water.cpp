class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0, h=n-1, ans=0;
        while(l<h){
            int current_area = (h-l)*min(height[l],height[h]);
            ans = max(ans, current_area);
            if(height[l]<height[h])
                l++;
            else
                h--;   
        }
        return ans;
    }
};
