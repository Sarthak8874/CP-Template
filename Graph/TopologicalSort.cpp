#include <iostream>
#include <bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(), v.end()
using namespace std;
void dfs(int node, int par, vector<int> &vis, vector<int> &ans, vector<vector<int>> &adj)
{
    vis[node] = 1;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            dfs(i, node, vis, ans, adj);
        }
    }
    ans.push_back(node);
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int>deg(n+1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }
    vector<int> vis(n + 1, 0);
    queue<int>q;
    for(int i = 1;i<=n;i++){
        if(deg[i] == 0){
            q.push(i);
            vis[i] = 1;
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int t = q.front();
        ans.push_back(t);
        q.pop();
        for(auto i : adj[t]){
            deg[i]--;
            if(!vis[i] && deg[i] == 0){
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    
}
