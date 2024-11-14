#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define R0F(i, a) for (int i = (a); i >= 0; i--)
#define trav(a, x) for (auto &a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
#define debug(x) cerr << #x << " = " << x << endl

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const db PI = acos((db)-1);
const int MAXN = 1e5 + 5;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    vector<ll> lHeights(n + 2), rHeights(n + 2);
    for (ll i = 1; i <= n; i++)
    {
        lHeights[i] = min({i, a[i - 1], lHeights[i - 1] + 1});
        rHeights[n + 1 - i] = min({i, a[n - i], rHeights[n + 2 - i] + 1});
    }

    ll maxHeight = 0;
    for (ll i = 1; i <= n; i++)
    {
        maxHeight = max(maxHeight, min(lHeights[i], rHeights[i]));
    }

    cout << maxHeight << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}