class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        int n=nums.size();
        for(int i=0;i<=n-1;i++){
            x=x^nums[i]; 
                }
       return x; 
    }
    
};