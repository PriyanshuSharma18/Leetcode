class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> v;
        int n = arr.size();

        // Count set bits for each element
        for(int i = 0; i < n; i++){
            int temp = arr[i];
            int cnt = 0;

            while(temp > 0){
                cnt += temp & 1;
                temp = temp >> 1;
            }

            v.push_back({arr[i], cnt});
        }

        // Sort using custom comparator
        sort(v.begin(), v.end(), comparator);

        // Extract sorted values
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = v[i].first;
        }

        return ans;
    }

private:
    static bool comparator(const pair<int,int>& a, const pair<int,int>& b){
        if(a.second == b.second)
            return a.first < b.first;

        return a.second < b.second;
    }
};