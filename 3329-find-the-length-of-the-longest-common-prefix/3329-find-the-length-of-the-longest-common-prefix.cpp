#include<bits/stdc++.h>
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int> mp;

        for(auto it:arr1){

            string a=to_string(it);

            string x="";

            for(auto b:a){
                x+=b;
                mp[x]++;
            }
        }
        int ans=0;
        for(auto it:arr2){

            string a=to_string(it);

            string x="";

            for(auto b:a){
                x+=b;
                if(mp.find(x)!=mp.end()){
                    ans=max(ans,static_cast<int>(x.size()));
                }
            }
        }

        return ans;

        
    }
};