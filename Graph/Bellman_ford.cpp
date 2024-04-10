#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void BellmanFord(int n, int src, vector<vector<pair<ll, ll>>> &adj, vector<ll> &dis)
{
     dis.assign(n+1,LLONG_MAX);
    dis[src] = 0;
    vector<pair<ll, pair<ll, ll>>> e;
    for (int i = 0; i <= n; i++)
    {
        for (auto j : adj[i])
        {
            e.push_back({j.second, {i, j.first}});
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (auto j : e)
        {
            if (dis[j.second.first] == LLONG_MAX)
            {
                continue;
            }
            dis[j.second.second] = min(dis[j.second.second], dis[j.second.first] + j.first);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
    }
    int src;
    cin >> src;
    vector<ll> dis(n + 1, LLONG_MAX);
    BellmanFord(n, src, adj, dis);
}