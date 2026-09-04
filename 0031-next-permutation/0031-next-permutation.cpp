class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int id=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                id=i;
                break;
            }
        }
        if(id==-1){
            reverseArray(nums,0);
            return;
        }
        int s=-1;
        for(int i=n-1;i>id;i--){
            if(nums[i]>nums[id]){
                s=i;
                break;
            }
        }
        swap(nums[id],nums[s]);
        reverseArray(nums,id+1);
        }
private:
    void reverseArray(vector<int>& nums, int start) {
        int left = start;
        int right = nums.size() - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

};