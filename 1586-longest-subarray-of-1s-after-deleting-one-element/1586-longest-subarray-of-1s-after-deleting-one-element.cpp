class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int one =0,zero=0,res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)zero++;

            while(zero>1){

                if(nums[one] ==0) zero--;
                one++;
            }
            res = max(res,i - one);
        }
        return res;
    }
};