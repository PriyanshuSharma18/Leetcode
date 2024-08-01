class Solution {
public:
    static int countSeniors(vector<string>& details) {
        return count_if(details.begin(), details.end(), [](string& s){
            return stoi(s.substr(11,2))>60;
        });
    }
};





auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();