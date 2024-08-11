class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        set<int> s;
        for(int x : arr)
            mp[x]++;

        for(auto x : mp){
            if(s.find(x.second)!=s.end())
            return false;
            else
            s.insert(x.second);
            

        }
    return true;
    }
};