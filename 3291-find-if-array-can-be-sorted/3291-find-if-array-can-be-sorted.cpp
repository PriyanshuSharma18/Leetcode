class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> bitCount(n,0);
        for(int i=0; i<n; i++) 
            bitCount[i] = __builtin_popcount(nums[i]);
        
        int prevMax = 0;
        int curMax,curMin;
        
        for(int i=0; i<n; i++) {
            curMax = nums[i];
            curMin = nums[i];
            
            while(i+1<n && bitCount[i] == bitCount[i+1]) {
                curMax = max(curMax, nums[i+1]);
                curMin = min(curMin, nums[i+1]);
                i++;
            }
            
            if(curMin >= prevMax) {
                prevMax = curMax;
            }else{
                return false;
            }
        }
        
        return true;
    }
};