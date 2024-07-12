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

class SGTree {
public:
    vector<int> seg;
    int size;

    SGTree(int n) {
        size = n;
        seg.resize(4 * n);
        build(0, n - 1, 0);
    }

    void build(int low, int high, int pos) {
        if (low == high) {
            seg[pos] = 1;
            return;
        }
        int mid = (low + high) / 2;
        build(low, mid, 2 * pos + 1);
        build(mid + 1, high, 2 * pos + 2);
        seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
    }

    void update(int low, int high, int index, int pos) {
        if (low == high) {
            seg[pos] = 0;
            return;
        }
        int mid = (low + high) / 2;
        if (index <= mid) {
            update(low, mid, index, 2 * pos + 1);
        } else {
            update(mid + 1, high, index, 2 * pos + 2);
        }
        seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
    }

    int query(int low, int high, int k, int pos) {
        if (low == high) {
            return low;
        }
        int mid = (low + high) / 2;
        if (seg[2 * pos + 1] >= k) {
            return query(low, mid, k, 2 * pos + 1);
        } else {
            return query(mid + 1, high, k - seg[2 * pos + 1], 2 * pos + 2);
        }
    }
};

void shreyasi(){

    int n;
    cin >> n;
    vector<int> elements(n);
    for (int i = 0; i < n; ++i) {
        cin >> elements[i];
    }
    vector<int> positions(n);
    for (int i = 0; i < n; ++i) {
        cin >> positions[i];
    }

    SGTree segTree(n);
    vector<int> result;
    for (int i = 0; i < n; ++i) {
        int pos = positions[i];
        int actual_index = segTree.query(0, n - 1, pos, 0);
        result.push_back(elements[actual_index]);
        segTree.update(0, n - 1, actual_index, 0);
    }

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
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