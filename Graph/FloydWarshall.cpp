#include <iostream>
#include <bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(), v.end()
using namespace std;

void FloydWarshall(ll n, vector<vector<pair<ll, ll>>> &adj, vector<vector<ll>> &cost)
{
    cost.assign(n + 1, vector<ll>(n + 1, LLONG_MAX));
    for (int i = 1; i <= n; i++)
    {
        cost[i][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto j : adj[i])
        {
            cost[i][j.first] = min(cost[i][j.first], j.second);
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    vector<vector<ll>> cost;
    FloydWarshall(n,adj,cost);
}