class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mpp;
        mpp[0]=1;
        int p=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            p+=nums[i];
            int rem=p-k;
            cnt+=mpp[rem];
            mpp[p]+=1;

        }


        return cnt;
    }
};