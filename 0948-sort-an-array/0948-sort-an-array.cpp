class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
             vector< pair<int , int > > v;
            for(int i = 0; i<nums.size(); i++)
              v.push_back ({nums[i] , i });
              sort(v.begin() , v.end());
              for(int i= 0; i<v.size(); i++)
                nums[i] = v[i].first ;

                return nums ;
    }
          
};