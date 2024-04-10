#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n + 1);
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
    vector<pair<ll, pair<ll, ll>>> e;
    for (int i = 0; i < n; i++)
    {
        for (auto j : adj[i])
        {
            e.push_back({j.second, {i, j.first}});
        }
    }
    dis[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto j : e)
        {
            dis[j.second.second] = min(dis[j.second.second], j.first + dis[j.second.first]);
        }
    }
}