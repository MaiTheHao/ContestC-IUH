#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define lb double long
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define all(x) begin(x), end(x)

const int MOD=(int) 1e9+7;
const int MAX=1e6;
const int MAXN=1e6;

bool cmp(pair<ll, ll> a1, pair<ll, ll> a2) {
    return a1.fi > a2.fi;
}

void Solve() {
    ll n, s, cnt = 0, sum = 0;
    pair<ll, ll> arr[MAXN];
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) cin >> arr[i].fi >> arr[i].se;

    sort(arr + 1, arr + n + 1, cmp);
    for (int i = 1; i <= n; ++i) {
        ll tmp = ceil((double)arr[i].fi / arr[i].se);
        if (tmp <= s) {
            cnt += tmp;
            s -= tmp;
            arr[i].fi = 0;
        } else {
            arr[i].fi -= s * arr[i].se;
            cnt += s;
            break;
        }
    }

    for (int i = 1; i <= n; ++i) sum += arr[i].fi;
    cout << sum << endl;
}

signed main (){
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int T(1);
    // cin >> T;
    while(T--) Solve();

    return 0;
}