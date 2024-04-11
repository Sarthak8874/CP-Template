#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define fin(i, a, b) for (ll i = a; i < b; i++)
#define sz(v) v.size()
#define fit(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define all(v) v.begin(), v.end()
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define pow2(i) (1ll << i)
#define maxheap(type) priority_queue<type>
#define minheap(type) priority_queue<type, vector<type>, greater<type>>


class HashedString
{
public:
    const ll M = 1e9 + 9;
    const ll B = 9973;

    vector<ll> pow;
    vector<ll> p_hash;

    HashedString(const string &s)
    {
        pow.push_back(1);
        while (pow.size() <= s.size())
        {
            pow.push_back((pow.back() * B) % M);
        }
        p_hash.assign(s.length() + 1, 0);
        p_hash[0] = 0;
        for (int i = 0; i < s.size(); i++)
        {
            p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
        }
    }

    ll get_hash(int start, int end)
    {
        ll raw_val = p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]);
        return (raw_val % M + M) % M;
    }
};
void solve()
{
    string s, a;
    cin >> s >> a;
    HashedString h = HashedString(s);
    HashedString ha = HashedString(a);
    cout << (h.get_hash(0, 2) == ha.get_hash(1, 3));
}
int main()
{
    fastio();
    int t;
    // t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}