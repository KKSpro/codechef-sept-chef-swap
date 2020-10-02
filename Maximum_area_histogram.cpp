#include <iostream>
#include<stack>
#include<vector>
#include<algorithm>

typedef long long int ll;
using namespace std;

int MAH(vector<int>arr,int N)
{
	  	stack<pair<int,int>>s1;
	    vector<int>v1;
		  
		stack<pair<int,int>>s2;
	    vector<int>v2;
		  
	   	
	        
//	    cout<<"hello1\n";    
		for(ll i=0;i<N;i++)
	   	{
	       int new1,index;
		   new1 = arr[i];
		   index = i;
	       if(s1.empty())
	       {
	          v1.push_back(-1);
	          s1.push(make_pair(new1,index));
	       }
	       
	       else
	       {
				auto topp = s1.top();
	           if(new1>topp.first)
	           {
	               v1.push_back(topp.second);
	               s1.push(make_pair(new1,index));
	           }
	           else
	           {
	               while(new1<=topp.first)
	               {
	                   s1.pop();
	                   if(s1.empty())
	                   break;
	                   topp = s1.top();
	               }
	               
	               if(s1.empty())
	               {
	                   v1.push_back(-1);
	                   s1.push(make_pair(new1,index));
	               }
	               else
	               {
	               		topp = s1.top();
	                   v1.push_back(topp.second);
	                   s1.push(make_pair(new1,index));
	               }
	           }
	       }
	   }
	   
//	   cout<<"hello2\n";
	   for(ll i=N-1;i>=0;i--)
	   	{
	       int new1,index;
		   new1 = arr[i];
		   index = i;
	       if(s2.empty())
	       {
	          v2.push_back(N);
	          s2.push(make_pair(new1,index));
	       }
	       
	       else
	       {
				auto topp = s2.top();
	           if(new1>topp.first)
	           {
	               v2.push_back(topp.second);
	               s2.push(make_pair(new1,index));
	           }
	           else
	           {
	               while(new1<=topp.first)
	               {
	                   s2.pop();
	                   if(s2.empty())
	                   break;
	                   topp = s2.top();
	               }
	               
	               if(s2.empty())
	               {
	                   v2.push_back(N);
	                   s2.push(make_pair(new1,index));
	               }
	               else
	               {
	               		topp = s2.top();
	                   v2.push_back(topp.second);
	                   s2.push(make_pair(new1,index));
	               }
	           }
	       }
	   }
	   reverse(v2.begin(),v2.end());
	   
		vector<int>width;
		for(ll i=0;i<N;i++)
		{
			width.push_back(v2[i]-v1[i]-1);
		}
		
		vector<int>area;
	    for(ll i=0;i<N;i++)
	    {
	    	area.push_back(width[i]*arr[i]);
		}

		sort(area.begin(), area.end(), greater<int>());
		
		auto it= area.begin(); 
//		 cout<<*it<<"\n";
		return *it;
}


int main() {
	//code
	int queries;
	cin>>queries;
	while(queries--)
	{
	    ll N;
		int temp,max1=-1,res;
	    cin>>N;
	    vector<int> arr;
	    for(int i=0;i<N;i++)
	    
		{
			cin>>temp;
			arr.push_back(temp);
		}
	    
	    res = MAH(arr,N);
	    cout<<res<<"\n";
	}
	return 0;
}
