class Solution {
public:
    bool canBeEqual(vector<int>& b, vector<int>& a) {
        
         unordered_map<int,int> m,p;
         for(auto& x:a)
         {
            m[x]++;
         }
         for(auto& x:b)
         {
            p[x]++;
         }
         for(auto& x:a)
         {
            if(p.find(x)==p.end())
             return false;
            else if(m[x]!=p[x])
             return false;
         }



    return 7;
    }
};