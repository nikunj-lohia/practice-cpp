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
int adj[1000000];
int vis[1000000];
void dfs(int s,int p)
{   
    vis[s]=-1;
    if(s==p)
    return;
    else
    {
        dfs(adj[s],p);
    }
}
void solve()
{
    int n;
    cin>>n;
    int a[n],b[n];
    memset(adj,-1,sizeof(adj));
    memset(vis,0,sizeof(vis));
    fo(i,0,n) cin>>a[i];
    fo(i,0,n) cin>>b[i];
    fo(i,0,n)
    {
        adj[a[i]]=b[i];
    }
    int ct=0;
    fo(i,0,n)
    {
      if(vis[a[i]]==0)
      {
          dfs(adj[a[i]],a[i]);
          ct++;
      }
    }
    // cout<<ct<<endl;
    ll ans=1;
    for(int i=1;i<=ct;i++)
    {
        ans=(ans<<1)%mod;
    }
    cout<<ans<<endl;
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