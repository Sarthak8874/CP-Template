#include <iostream>
#include <bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(), v.end()
using namespace std;

void Dijstra(ll s, ll n, vector<ll> &dis, vector<ll> &par, vector<vector<pair<ll, ll>>> &adj)
{
    dis.assign(n + 1, LLONG_MAX);
    par.assign(n + 1, -1);
    dis[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        ll u = pq.top().second, d = pq.top().first;
        pq.pop();
        if (d != dis[u])
        {
            continue;
        }
        for (auto j : adj[u])
        {
            if (dis[j.first] > j.second + d)
            {
                dis[j.first] = j.second + d;
                par[j.first] = u;
                pq.push({dis[j.first], j.first});
            }
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
        adj[v].push_back({u, d});
        adj[u].push_back({v, d});
    }

    vector<ll> dis(n + 1, LLONG_MAX);
    vector<ll>par(n + 1);
    int src;
    cin >> src;
    Dijstra(src,n,dis,par,adj);
    for (int i = 0; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
}