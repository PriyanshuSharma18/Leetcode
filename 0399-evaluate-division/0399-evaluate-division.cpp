class Solution {
public:
    void dfs(string& a,string &b,map<string,int>& vis,
    map<string,vector<pair<string,double>>>& adj,double ans,double& val)
    {
        vis[a] = 1;
        if(a==b)
        {
            val = ans;
            return;
        }
        for(auto &i:adj[a])
        {
            if(vis.find(i.first)==vis.end())
            {
                dfs(i.first,b,vis,adj,ans*i.second,val);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equ, vector<double>& values, vector<vector<string>>& q) {
        map<string,vector<pair<string,double>>> adj;
        int n = values.size();
        for(int i=0;i<n;i++)
        {
            string a = equ[i][0];
            string b = equ[i][1];
            double val = values[i];
            adj[a].push_back({b,val});
            adj[b].push_back({a,1.0/val});
        }
        map<string,int> vis;
        vector<double> fans;
        for(int i=0;i<q.size();i++)
        {
            double ans = -1.0;
            string a = q[i][0];
            string b = q[i][1];
            if(adj.find(a)!=adj.end())
            {
                double val = -1.0;
                ans = 1;
                dfs(a,b,vis,adj,ans,val);
                ans = val;
            }
            fans.push_back(ans);
            vis.clear();
        }
        return fans;
    }
};