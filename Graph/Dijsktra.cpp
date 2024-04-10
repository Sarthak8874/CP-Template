#include <iostream>
#include <bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(), v.end()
using namespace std;
void print(vector<vector<ll>> &par, int node)
{
    if (par[node].size() == 0)
    {
        return;
    }
    cout << node << endl;
    for (auto i : par[node])
    {
        print(par, i);
    }
}
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
        adj[v].push_back({u, d});
        adj[u].push_back({v, d});
    }

    vector<ll> dis(n + 1, LLONG_MAX), vis(n + 1, 0);
    vector<vector<ll>> par(n + 1);
    int src;
    cin >> src;
    set<pair<ll, int>> s;
    dis[src] = 0;
    s.insert({0, src});
    while (!s.empty())
    {   
        auto t = s.begin();
        int u = (*t).second;
        s.erase(t);
        for (auto &edge : adj[u])
        {
            int v = edge.first;
            ll weight = edge.second;
            if (dis[v] > dis[u] + weight)
            {
                s.erase({dis[v], v});
                dis[v] = dis[u] + weight;
                par[v].clear();
                par[v].push_back(u);
                s.insert({dis[v], v});
            }
            else if (dis[v] == dis[u] + weight)
            {
                par[v].push_back(u);
            }
        }
    }

    print(par, 4);
    // while (!s.empty())
    // {
//  ll u = (*s.begin()).second,w = (*s.begin()).first;
//         vis[u] = 1;
//         s.erase(s.begin());
//         for (auto i : adj[u])
//         {
//             if (!vis[i.first])
//             {
//                 s.erase({dis[i.first],i.first});
//                 dis[i.first] = min(i.second+w,dis[i.first]);
//                 s.insert({dis[i.first],i.first});
//             }
//         }
    // }
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << dis[i] << " ";
    // }
}