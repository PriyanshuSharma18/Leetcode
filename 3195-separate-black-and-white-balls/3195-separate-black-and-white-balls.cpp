class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') c++;
            else ans+=c;
        }
        return ans;
        // for(int i=s.size()-1;i>=0;i--){
        //     if(s[i]=='0') c++;
        //     else ans+=c;
        // }
        // return ans;
    }
};