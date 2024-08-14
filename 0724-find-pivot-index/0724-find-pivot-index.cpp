class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //find left sided sum
        int leftSum=0 ;
        //calculate right sided sum
        int rightSum = accumulate(nums.begin(),nums.end(),0);

        //traverse the whole vector and check all point for pivot condition
        for(int i = 0 ; i<nums.size();i++){
            rightSum-=nums[i];
            if(leftSum == rightSum)
                return i;
            leftSum+=nums[i];
        }
        return -1;
    }
};