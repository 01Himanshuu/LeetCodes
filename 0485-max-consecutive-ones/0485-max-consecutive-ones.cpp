class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counter=0;
        int max=0;
        int n=nums.size();
        for(int i=0;i<=n-1;i++){
            if(nums[i]==1){
                counter++;
                }
            if(counter>max){
                max=counter; } 
            if(nums[i]==0){
                counter=0;
                } 
                 } 

        return max;
    }
};