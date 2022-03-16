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
 
	return a.ff < b.ff;
}

//////////////////////////I SHALL FEAST IN VALHALLA////////////////////////////////
map<ll,int> p,q;
pair<int, int> getRatio(int a, int b) {
    int g = __gcd(a, b);
    a /= g;
    b /= g;
    return {a, b};
}
void solve()
{
  ll l,r,k;
  cin>>l>>r>>k;
  // cout<<"hi"<<endl;
  if(l==r) {
    if(l==1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return;
  }
  ll range=r-l;
  range/=2;
  if(l%2==0&&r%2==0)
  {
     if(k>=range) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
  }
  else
  {
     if(k>=range+1) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
  }
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
}
