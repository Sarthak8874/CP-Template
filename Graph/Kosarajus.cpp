#include <iostream>
#include <bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(), v.end()
using namespace std;
void dfs(int node,stack<int> &st,vector<int> &vis,vector<vector<ll>> &adj){
    vis[node] =1;
    for(auto i : adj[node]){
        if(!vis[i]){
            dfs(i,st,vis,adj);
        }
    }
    st.push(node);
}

void dfs2(int node,vector<int> &vis,vector<vector<ll>> &adj,vector<int> &temp){
    vis[node] =1;
    temp.push_back(node);
    for(auto i : adj[node]){
        if(!vis[i]){
            dfs2(i,vis,adj,temp);
        }
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<ll>>adj(n+1),tadj(n+1);
    for(int i = 0;i<m;i++){
        ll u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        tadj[u].push_back(v);
    }  
    stack<int>st;
    vector<int>vis(n+1);
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            dfs(i,st,vis,adj); 
        }
    }
    vis.assign(n+1,0);
    vector<int> temp;
    vector<vector<int>>scc;
    int idx = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(vis[node] == 0){
            dfs2(node,vis,tadj,temp);
            scc.push_back(temp);
            temp.clear();
        }
    }
}