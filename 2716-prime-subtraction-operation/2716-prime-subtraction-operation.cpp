
class Solution {
public:
    bool checkPrime(int x) {
        if (x <= 1) return false;
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    bool primeSubOperation(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int bound = (i == 0) ? nums[i] : nums[i] - nums[i - 1];
            
            if (bound <= 0) return false;
            
            int largestPrime = 0;
            for (int j = bound - 1; j >= 2; j--) {
                if (checkPrime(j)) {
                    largestPrime = j;
                    break;
                }
            }
            
            nums[i] -= largestPrime;
        }
        
        return true;
    }
};