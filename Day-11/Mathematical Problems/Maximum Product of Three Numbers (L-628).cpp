// If all are positive then -
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        return nums[n-1]*nums[n-2]*nums[n-3];
    }
};

//Better approach.
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1 = INT_MAX;
        int min2 = min1;
        
        int max1 = INT_MIN;
        int max2 = max1;
        int max3 = max2;
        
        for(int i=0; i<nums.size(); i++){
            
            int val = nums[i];
            
            if(val>=max1){
                max3 = max2;
                max2 = max1;
                max1 = val;
            }
            else if(val >= max2){
                max3 = max2;
                max2 = val;
            }
            else if(val >= max3){
                max3 = val;
            }
                
            if(val <= min1){
                min2 = min1;
                min1 = val;
            }
            else if(val <= min2){
                min2 = val;
            }
        }
        return max((min1*min2*max1), (max1*max2*max3));
    }
};
