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
    vector<int> seg;
    SGTree(int n){
        seg.resize(4*n+1,0);
        
    }
    void build(int low , int high , int ind , vector<int> &arr){
        if(low==high){
            seg[ind] = arr[low]; 
            return;
        }
        int mid = (low+high)/2;
        //debug(mid);
        build(low , mid , 2*ind+1 ,arr);
        build(mid+1 , high , 2*ind+2 ,arr);
        seg[ind] = seg[2*ind+1]^seg[2*ind+2];
        
    }
    
    int query( int low , int high , int l , int r , int ind){
        if(l<=low&&r>=high){
            return seg[ind];
        }
        if(r<low||high<l) return 0;
        
        int mid = (low+high)/2;
        int left = query(low,mid,l,r,2*ind+1);
        int right = query(mid+1,high,l,r,2*ind+2);
        return left^right;
    }
    
    void update(int low , int high , int ind , int i , int val){
        if(low==high){
            seg[ind]=val;
            return;
        }
        int mid = (low+high)/2;
        if(i<=mid) update(low , mid , 2*ind+1 , i ,val);
        else update(mid+1 , high , 2*ind+2 , i ,val);
        seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
        
    }
    
    void dis(){
        debug(seg);
    }
};
 
 
void shreyasi() {
	int n,q;
	cin>>n>>q;
	vector<ll>v(n,0);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	SGTree sgmt(n);
	sgmt.build(0,n-1,0,v);
	for(int i=0;i<q;i++){
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			cout<<sgmt.query(0,n-1,a,b,0)<<endl;
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