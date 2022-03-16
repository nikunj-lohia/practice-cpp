//>>>>>>>>>>>>>>>>>>>>>>>>>>ODIN IS WITH US<<<<<<<<<<<<<<<<<<<<<//
//>>>>>>>>>>>>>>>>>>>>>>>>>>R_A_G_N_A_R_O_K<<<<<<<<<<<<<<<<<<<<<//
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
#define ll long long
#define str string
#define valhalla ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fo(i,a,n) for(long long i=a;i<n;i++)
#define rfo(i,a,n)for(long long i=n-1;i>=a;i--)
#define cases   long long t;cin>>t;while(t--)
#define eb emplace_back
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define ff first
#define ss second
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
#define endl '\n'
#define sz(x) ((int)(x).size())
const int mod = (int)1000000000 + 7;
const int MOD = (int)998244353;
const int INF = (int)1e18;
#define printall(a) fo(i,0,a.size()) cout<<a[i]<<" "; cout<<endl;
typedef vector<int> vii;
typedef set<long long int> sli;
typedef map<int, int> mii;
typedef map<ll, int> mli;
typedef vector<long long> vl;
typedef pair<ll, ll> pii;
typedef vector<pii> vpi;
typedef vector<vector<int> > vv;
bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
 
	return a.ss - a.ff < b.ss - b.ff;
}

//////////////////////////I SHALL FEAST IN VALHALLA////////////////////////////////


void solve()
{
   ll n,l,r;
   cin>>n>>l>>r;
   ll a[n];
   fo(i,0,n)
   {
	   cin>>a[i];
   }
   sort(a,a+n);
   ll cnt = 0;
    ll i = 0, low = n-1, high =n-1;
    while (i < high) {
         low = max(i, low);
         while (low > i && a[i] + a[low] >= l) --low;
        while (high > low && a[i] + a[high] > r) --high; 
        cnt += (high-low);
        ++i;
    }
   cout<<cnt<<endl;
}
int main()
{
	valhalla
	ll t = 1;
	 cin >> t;
	while (t--)
	{
		solve();
	}
	//clock_t timest = clock();
	//cerr << "[Executes in " << (double)(clock() - timest) / CLOCKS_PER_SEC << "s]" << endl;
}
