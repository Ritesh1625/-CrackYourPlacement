// Brute Force
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        return n*(n+1)*0.5 - accumulate(nums.begin(),nums.end(),0);
    }
};

//Another approach
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i=0; i<nums.size(); i++){
            ans^= nums[i]^i ;    
        }
        
        ans^=(n);
        return ans;
    }
};
