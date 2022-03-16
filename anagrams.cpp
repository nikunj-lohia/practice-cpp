#include<bits/stdc++.h>
using namespace std;
vector<vector<string> > Anagrams(vector<string>& s) 
{
    
    vector<unordered_map<char,int>> mp(5);
    
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<s[i].length();i++)
        {
            mp[i][s[i][j]]++;
        }
    }
    int vis[s.size()]={0};
    vector<vector<string>> ans;
    for(int i=0;i<s.size();i++)
    {  
        vector<string> tmp;
        tmp.push_back(s[i]);
        vis[i]==1;
        for(int j=i+1;j<s.size();j++)
        {
            if(vis[j]!=1)
           {
                if(mp[i]==mp[j])
                {
                    tmp.push_back(s[j]);
                    vis[j]=1;
                    // cout<<s[j]<<endl;
                }
           }
        //    cout<<"hi"<<endl;
        }
        ans.push_back(tmp);
    }
    return ans;   
}
int main()
{
    vector<string> s;
     s.push_back("act");
    s.push_back("dog");
    s.push_back("cat");
     s.push_back("god");   
       s.push_back("tac");
    vector<vector<string>> ans=Anagrams(s);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();i++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
       
}