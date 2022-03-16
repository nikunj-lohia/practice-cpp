class Solution {
public:
	int TotalPairs(vector<int>&nums, int x, int y){
	    int n=nums.size();
	    int count=0;
	    int i=0,j=1;
	    unordered_map<int,int> mp;
	    for(int i=0;i<n;i++)
	    mp[nums[i]]++;
	    if(mp.size()!=1)
	    {
    	    for(auto it=mp.begin(),it1=mp.begin();it!= mp.end();it++)
    	    {  it1++;
    	        for(auto it2=it1;it2!= mp.end();it2++)
    	        {   
    	            //cout<<it->first<<" "<<it2->first<<endl;
    	            int a=it->first,b=it2->first;
    	            if(a*b>=x&&a*b<=y)
    	            {   
    	                count+=it->second*it2->second;
    	            }
    	        }
    	    }
    	    return count;
    	}
	else
	{  if(n==1)
	     return 0;
	    else{
	    int c=num[0];
	    if(c*c>=x&&c*c<=y)
	    {
	        return (n*(n-1))/2;
	    }
	    else 
	    return 0;
	  }
	}
};