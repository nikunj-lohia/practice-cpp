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
map<ll,int> p,q;
void primeFactorsp(ll n,map<ll,int> &p)
{
    while (n % 2 == 0)
    {
        p[2]++;
        n = n/2;
    }
    for (ll i = 3; i*i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            p[i]++;
            n = n/i;
        }
    }
	if(n>2)
	p[n]++;
}
void solve()
{
   int n,m,flag=1;
   cin>>n>>m;
   char f[n][m],fl='$';
   fo(i,0,n)
   {
       fo(j,0,m) 
       {
           cin>>f[i][j];
            if((f[i][j]=='R'||f[i][j]=='W')&&flag==1)
            {
                if((i+j)%2==0)
                {
                    fl=f[i][j];
                }
                else
                {
                    if(f[i][j]=='R') fl='W';
                    else fl='R';
                }
                flag=0;
            }
        }
   }
   int f1=0,f2=0;
   if(f[0][0]!='.')
   {
       if(f[0][0]=='R'||f[0][0]=='W')
       {
           fo(j,1,m)
           {
               if(f[0][j]=='.')
               {
                   if(f[0][j-1]=='R') f[0][j]='W';
                   else f[0][j]='R';
               }
               else if(f[0][j]==f[0][j-1])
               {
                   cout<<"NO"<<endl;
               }
           }
           fo(j,0,m)
           {
               fo(i,1,n)
               {
                   if(f[i][j]=='.')
                   {
                       if(f[i-1][j]=='R') f[i][j]='W';
                       else f[i][j]='R';
                   }
                   else if(f[i][j]==f[i-1][j]) 
                   {
                       cout<<"NO"<<endl;
                       return;
                   }
               }

           }
       }

   }
   else if(f[0][0]=='.')
   {
       if(flag==1)
       {  f[0][0]='R';
           fo(j,1,m)
           {
               if(f[0][j-1]=='R') f[0][j]='W';
               else f[0][j]='R';
           }
           fo(j,0,m)
           {
               fo(i,1,n)
               {
                   if(f[i-1][j]=='R') f[i][j]=='W';
                   else f[i][j]=='R';
               }
           }
           cout<<"YES"<<endl;
           fo(i,0,n)
           {
               fo(j,0,m) 
               {
                   cout<<f[i][j]<<" ";
               }
               cout<<endl;
           }
       }
       else if(flag ==0)
       {
          f[0][0]=fl;
           fo(j,1,m)
           {   
               if(f[0][j]=='.')
               {
               if(f[0][j-1]=='R') f[0][j]='W';
               else f[0][j]='R';
               }
               else if(f[0][j]==f[0][j-1])
               {
                   cout<<"NO"<<endl;
                   return;
               }

           }
           fo(j,0,m)
           {
               fo(i,1,n)
               {
                   if(f[i][j]=='.')
                   {
                        if(f[i-1][j]=='R') f[i][j]=='W';
                        else f[i][j]=='R';
                   }
                   else if(f[i][j]==f[i-1][j])
                   {
                       cout<<"NO"<<endl;
                       return;
                   }
                
               }
           }
          
       }
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
	//clock_t timest = clock();
	//cerr << "[Executes in " << (double)(clock() - timest) / CLOCKS_PER_SEC << "s]" << endl;
}
