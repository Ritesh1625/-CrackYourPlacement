// We could have used hashmaps, but we will not use it as we cannot take extra space. Values are here in 1 to n-> these will correspond to 0,n-1.

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int n: nums){
            n = abs(n);
            if(nums[n-1]>0) nums[n-1]*=-1;
            else result.push_back(n);
        }
        return result;
    }
};
