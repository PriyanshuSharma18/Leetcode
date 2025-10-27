class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, p = 0;
        for(auto b: bank){
            int c = 0;
            for(int j = 0; j < b.size(); j++){
                if(b[j] == '1'){
                    c++;
                }
            }
            if(c > 0){
                ans += p * c;
                p = c;
            }
        }
        return ans;
    }
};