class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
          int s=accumulate(nums.begin(),nums.end(),0), t=s-x, l=0, sum=0, mx=-1;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            while(l<=r && sum>t) sum-=nums[l++];
            if(sum==t) mx=max(mx,r-l+1);
        }
        return mx<0?-1:nums.size()-mx;
    }
};