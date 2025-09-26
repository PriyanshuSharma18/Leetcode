class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return 0;
        int count=0;
        sort(nums.begin(), nums.end());

        for(int i=n-1; i>1; i--){
            int r=i-1;
            int l=0;
            while(l<r){
                int sum=nums[l]+nums[r];
                if(sum>nums[i]){
                    count+=(r-l);
                    r--   ;
                

                }else{
                   l++;
                }
            }

    
        }
        return count; 
    }
};