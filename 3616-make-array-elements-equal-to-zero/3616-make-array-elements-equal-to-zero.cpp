class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        
        int total=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                int lsum=0;
                for(int j=0;j<i;j++){
                    lsum+=nums[j];
                }
                int rsum=0;
                for(int j=i;j<nums.size();j++){
                    rsum+=nums[j];
                }
                if(lsum==rsum){
                    total+=2;
                }else if((lsum==(rsum-1)) || (rsum==(lsum-1))){
                    total++;
                }
            }
        }
        return total;
    }
};