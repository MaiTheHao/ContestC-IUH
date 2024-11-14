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

int64_t binPow(int64_t a, int64_t b)
{
    int64_t res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res = res * a % MOD;
            res %= MOD;
        }
        a = a * a % MOD;
        a %= MOD;
        b /= 2;
    }
    return res;
}

int64_t S(int64_t x)
{
    x %= MOD;
    return x * (x + 1) % MOD * (2 * x + 1) % MOD * binPow(6, MOD - 2) % MOD;
}

void solve()
{
    int64_t n, m;
    cin >> n >> m;
    int64_t total = (S(m) - S(n - 1) + MOD) % MOD;
    cout << total;
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