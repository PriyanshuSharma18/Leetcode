class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int rotate=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1) %n] && ++rotate>1){
                return false;
            }
        }
        return true;
    }
};