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
// ll cc[27] = { 0 };
// ll a[100009];
// map<int,int> mp;
void solve()
{ 
    ll m;
    cin>>m;
    vector<int> g[m+1];
    bool v [m+1];
    int p[m+1],d[m+1];
    int nl[m+1]={0};
    fo(i,0,m-1)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    ll s=1;
    queue<int> q;
    q.push(s);
    fo(i,0,m+1)
    p[i]=-1;
    v[s]=true;
    d[s]=0;
    nl[d[s]+1]++;
    while(!q.empty())
    {   int c=q.front();
        q.pop();
        for(int i=0;i<g[c].size();i++)
        {
            if(v[g[c][i]]!=true)
            {
                q.push(g[c][i]);
                p[g[c][i]]=c;
                d[g[c][i]]=d[c]+1;
                nl[d[g[c][i]]+1]++;
                v[g[c][i]]=true;
            }
        }
    }
    ll cx;
    cin>>cx;
    cout<<nl[cx]<<endl;
}
int main()
{
	valhalla
	ll t = 1;
	//   cin >> t;
	while (t--)
	{
		solve();
 
	}
	//clock_t timest = clock();
	//cerr << "[Executes in " << (double)(clock() - timest) / CLOCKS_PER_SEC << "s]" << endl;
}