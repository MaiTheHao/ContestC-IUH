#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORE(i, a, b) for (ll i = (a); i <= b; i++)
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

/*
    Ta có công thức tính XOR từ 0 đến n:
        - XOR(0, n) = n;
            > Nếu n chia hết cho 4.
        - XOR(0, n) = 1;
            > Nếu n chia cho 4 dư 1.
        - XOR(0, n) = n + 1;
            > Nếu n chia cho 4 dư 2.
        - XOR(0, n) = 0;
            > Nếu n chia cho 4 dư 3.
*/
// Hàm này tính XOR từ 0 tới n.
ll XOR(ll n)
{
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

// XOR(A, B) = XOR(0, B) ^ XOR(0, A-1)
// Hàm này tính XOR(A, B)
ll calc(ll x, ll y)
{
    return XOR(y) ^ XOR(x - 1);
}

void solve()
{
    ll q;
    cin >> q;

    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        cout << calc(x, y) << endl;
    }
}

void setupIO()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    // freopen("logger.log", "w", stderr);
    // freopen("output.out", "w", stdout);
#endif
}

int main()
{
    setupIO();
    int t = 1, count = 0;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}