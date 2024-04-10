#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> par, size, rnk;
void dsu(int n)
{
    for (int i = 0; i <= n; i++)
    {
        par.push_back(i);
        size.push_back(1);
        rnk.push_back(0);
    }
}

int findpar(int node)
{
    if (par[node] == node)
    {
        return node;
    }
    return par[node] = findpar(par[node]);
}

void unionsize(int u, int v)
{
    int pu = findpar(u), pv = findpar(v);
    if (pu == pv)
    {
        return;
    }
    if (size[pv] > size[pu])
    {
        par[pu] = pv;
        size[pv] += size[pu];
    }
    else
    {
        par[pv] = pu;
        size[pu] += size[pv];
    }
}

void unionrnk(int u, int v)
{
    int pu = findpar(u), pv = findpar(v);
    if (pu == pv)
    {
        return;
    }
    if (rnk[pu] == rnk[pv])
    {
        par[pu] = pv;
        rnk[pu]++;
    }
    else if (rnk[pu] > rnk[pv])
    {
        par[pv] = pu;
    }
    else
    {
        par[pu] = pv;
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n + 1);
    priority_queue<pair<ll, pair<int, int>>,vector<pair<ll, pair<int, int>>>,greater<pair<ll, pair<int, int>>>> pq;
    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        pq.push({w, {u, v}});
    }
    ll sum = 0;
    dsu(n);
    while (!pq.empty())
    {
        auto f = pq.top();
        ll u = f.second.first, v = f.second.second;
        pq.pop();
        ll paru = findpar(u), parv = findpar(v);
        if (paru == parv)
        {
            continue;
        }
        else
        {
            sum += f.first;
            unionrnk(u,v);
            adj[u].push_back({v, f.first});
            adj[v].push_back({u, f.first});
        }
    }
}