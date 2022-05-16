class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return;
        int z = 0;
        int j = 1;
        while(j < n){
            if(nums[z] == 0 && nums[j]!=0){
                swap(nums[z],nums[j]);
                z++;               
            }
            if(nums[z]!=0)z++;
             j++;
        }
    }
};
