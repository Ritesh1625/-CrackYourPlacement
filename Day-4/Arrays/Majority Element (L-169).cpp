// The majority element is the element that appears more than ⌊n / 2⌋ times.
// We can use Hashmap here. T.C- O(n), S.C-O(n)

// Optimal Solution - By Moore's Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int res = 0;
        
        for(auto num:nums){
            if(count == 0)
                res = num;
            if(num != res){
                count--;
            }
            else{
                count++;
            }
        }
        return res;
    }
};
