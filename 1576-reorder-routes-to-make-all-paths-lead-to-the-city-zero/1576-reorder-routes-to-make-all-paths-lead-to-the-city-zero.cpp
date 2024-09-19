class Solution {
public:
    int minReorder(int n, vector<vector<int>>& v) {
        int ns=v.size();
        vector<int>adj[n];
        vector<int>vis(n,0);
        set<pair<int,int>>s;
        for(int i=0;i<ns;i++)
        {
            adj[v[i][0]].push_back(v[i][1]);
            adj[v[i][1]].push_back(v[i][0]);
            s.insert({v[i][0],v[i][1]});
        }
        queue<int>q;
        q.push(0);
        // vis[0]=1;
        int count=0;
        while(!q.empty())
        {
            auto p= q.front();
            q.pop();
            if(vis[p]==0)
            {
                vis[p]=1;
                for(auto i:adj[p])
                {
                    q.push(i);
                    if(vis[i]==0&&s.count({p,i}))
                    count++;
                }
            }
        }
        return count;  
    }
};