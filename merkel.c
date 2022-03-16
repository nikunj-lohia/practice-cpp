#include<bits/stdc++.h>
using namespace std;
long long mod=10e12;

string hashed(string s) //my hash function interates through the string and finds for a character by taking the mod by 26, then appends it to the end of the hash string
{
	long long z=1; string h="";
	for(auto x:s) {z*=x; z+=x; h+=char(97+(z%26)); z%=mod;}
	return h;
}

class merkle
{
private:
  vector<vector<string>> hash; //hashes
  vector<string> tr; //transictions
public:
  void insert()
  {
  	cout<<"Enter String to insert: "; 
	string s; cin>>s;
  	int i,z,n=hash.size();
  	tr.push_back(s);
  	if(n==0) {vector<string> v; v.push_back(hashed(s)); hash.push_back(v); return;}
  	hash[0].push_back(hashed(s));
  	for(i=1;i<n;i++)
  	{
  	  z=(hash[i-1].size()/2)+(hash[i-1].size()%2);
	  if(hash[i].size()<z) hash[i].push_back(hashed(s));
	  else
	  {
	  	z=hash[i].size()-1;
	  	if((z<<1|1)<hash[i-1].size()) hash[i][z]=hashed(hash[i-1][z<<1]+hash[i-1][z<<1|1]);
	    else hash[i][z]=hash[i-1][z<<1];
	  }
	}
	if(hash[n-1].size()==2)
	{
		vector<string> v;
		v.push_back(hashed(hash[n-1][0]+hash[n-1][1]));
		hash.push_back(v);
	}
  }
  
  void print_merkle_tree()
  {
  	if(tr.size()==0) {cout<<"Tree is currently empty\n"; return;}
  	cout<<"\nCurrent Merkle tree is: \n";
  	int i,sz=hash.size();
  	for(i=sz-1;i>=0;i--)
  	{
  	  for(auto y:hash[i]) cout<<y<<' ';
	  cout<<'\n';	
	}
  }
  
  void print_root()
  {
  	int z=hash.size();
  	if(z==0) cout<<"Tree is currently empty\n";
  	else cout<<"\nCurrent root is: "<<hash[z-1][0]<<'\n';
  }
  
  void print_transictions()
  {
  	if(tr.size()==0) {cout<<"Tree is currently empty\n"; return;}
  	cout<<"Current transiction array is: \n";
  	for(auto x:tr) cout<<x<<' ';
  	cout<<'\n';
  }
  
};

int instructions()
{
	cout<<"--------------------------------\n";
	cout<<"1 to insert a new transiction\n";
	cout<<"2 to show the hashed root\n";
	cout<<"3 to show the transiscions array\n";
	cout<<"4 to show the entire merkle tree\n";
	cout<<"5 to exit\n";
	cout<<"Enter: ";
	int x; cin>>x;
	while(x<0 or x>5) {cout<<"Invalid Input! Enter again: "; cin>>x;}
	return x;
}

int32_t main()
{
	merkle abc; int x;
	while(1)
	{
		x=instructions();
		if(x==1) abc.insert();
		else if(x==2) abc.print_root();
		else if(x==3) abc.print_transictions();
		else if(x==4) abc.print_merkle_tree();
		else if(x==5) exit(0);
	}
}