class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(int i=0; i<k; i++){
            sum += nums[i];
        }

        double avg = sum/k;
        for(int i=0, j=k; j<nums.size(); i++,j++){
            sum -= nums[i];
            sum += nums[j];

            avg = max(avg,sum/k);
        }

        return avg;
    }
};