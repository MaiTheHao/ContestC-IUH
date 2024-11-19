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

void solve() {
    ll n, x; cin >> n >> x;
    ll ans = 0;
    map<ll, ll> save; save[0] = 1;
    for(ll i = 0, sum = 0; i < n; i++) {
        ll v; cin >> v;
        sum = (sum + v) % x;
        ans += save[sum]++;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../input.in", "r", stdin);
    freopen("../error.log", "w", stderr);
    freopen("../output.out", "w", stdout);
    #endif
    cerr << "------START LOGGING------" << endl;
    int t = 1, count = 0;
    //cin >> t;
    while (t--) {
        solve();
        cerr << "------END WHILE NUMBER " << ++count << "------" << endl;
    }
    cerr << "------END LOGGING------" << endl;
    return 0;
}