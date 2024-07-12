#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double lld;

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define lcm(a, b) ((a) * (b)) / __gcd(a, b)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long

class SGTree{
public:
    vector<int> seg, lazy;
    int n;

    SGTree(int size) {
        n = size;
        seg.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void propagate(int ind, int low, int high) {
        if (lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
             if (low != high) { // If not a leaf node
                lazy[2 * ind + 1] += lazy[ind]; // Mark left child as lazy
                lazy[2 * ind + 2] += lazy[ind]; // Mark right child as lazy
            }
            lazy[ind] = 0; // Clear the lazy value
        }
    }

    void updateRange(int low, int high, int l, int r, int val, int ind) {
    propagate(ind, low, high); // Apply any pending updates
    if (r < low || l > high) return; // No overlap
    if (l <= low && r >= high) { // Total overlap
        seg[ind] += (high - low + 1) * val; // Update the segment
        if (low != high) { // If not a leaf node
            lazy[2 * ind + 1] += val; // Mark left child as lazy
            lazy[2 * ind + 2] += val; // Mark right child as lazy
        }
        return;
    }
    int mid = (low + high) / 2; // Partial overlap
    updateRange(low, mid, l, r, val, 2 * ind + 1);
    updateRange(mid + 1, high, l, r, val, 2 * ind + 2);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2]; // Update the current node
}

    int query(int low, int high, int pos, int ind) {
        propagate(ind, low, high);
        if (low == high) {
            return seg[ind];
        }
        int mid = (low + high) / 2;
        if (pos <= mid) {
            return query(low, mid, pos, 2 * ind + 1);
        } else {
            return query(mid + 1, high, pos, 2 * ind + 2);
        }
    }
};

void shreyasi() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> forest(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        string row;
        cin >> row;
        for (int j = 1; j <= n; ++j) {
            if (row[j-1] == '*') {
                forest[i][j] = 1;
            }else{
                forest[i][j]=0;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            prefix[i][j] = forest[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    debug(prefix);
    while (q--){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int result = prefix[y2][x2] - prefix[y1-1][x2] - prefix[y2][x1-1] + prefix[y1-1][x1-1];
        cout << result << endl;
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
    int T=1;
    //cin >> T;
    while (T--) {
        shreyasi();
    }
    return 0;
}