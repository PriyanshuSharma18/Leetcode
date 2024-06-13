// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int j=-1;
//         for(int i=0;i<n;i++){
//              if(a[i]== 0){
//                 j=i;
//              }
             
//         }
//         if(j==-1 return a);
    
//     for(int i=j+1;i<n;i++){
//         if(a[i] != 0){
//             swap(a[i],a[j]);
//             j++;
//         }
//     }return a;
// };
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int* zeroPtr = nullptr;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0 && zeroPtr == nullptr) {
                zeroPtr = &nums[i]; // Initialize zeroPtr at the first zero encountered
            } else if (nums[i] != 0 && zeroPtr != nullptr) {
                *zeroPtr = nums[i]; // Place non-zero element at the position of the first zero
                nums[i] = 0; // Set current element to zero
                zeroPtr++; // Move zeroPtr to the next position
            }
        }
    }
};