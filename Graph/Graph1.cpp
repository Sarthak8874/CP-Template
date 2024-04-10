#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<bool> &vis, vector<vector<int>> adj, int cnt, vector<int> &component, vector<int> &parent)
{
    component[node] = cnt;
    parent[node] = par;
    vis[node] = true;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            dfs(i, node, vis, adj, cnt, component, parent);
        }
        else if (vis[i] && i != par)
        {
            cout << "Cycle Fount";
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n + 1, false);
    vector<int> parent(n + 1, 0);
    vector<int> component(n + 1);
    int cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(0, -1, vis, adj, cnt, component, parent);
            cnt++;
        }
    }
}