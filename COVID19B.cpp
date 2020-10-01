#include<bits/stdc++.h>
#define ll long long;

using namespace std;
#define MAX 6

// Adjacency list representation of tree
vector<int> adj[MAX];

// Visited array to keep track visited
// nodes on tour
int vis[MAX];

// Array to store Euler Tour


// Function to add edges to tree
void add_edge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Function to store Euler Tour of tree
void eulerTree(int u)
{
    vis[u] = 1;

    for (auto it : adj[u]) {
        if (!vis[it]) {
            eulerTree(it);

        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {


        int n;
        cin>>n;
        int arr[n+1];
        for(int j=1;j<=n;j++)
        {
            adj[j].clear();
        }
        for(int i=1;i<=n;i++)cin>>arr[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(arr[i]>arr[j])
                    add_edge(i,j);
            }
        }
        vector<int> ans;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                vis[j]=0;
            }
            eulerTree(i);
            int cnt=0;
            for(int j=1;j<=n;j++)
            {
                if(vis[j]==1)
                    cnt++;
            }
            ans.push_back(cnt);

        }
        int minel = *min_element(ans.begin(),ans.end());
        int maxel= *max_element(ans.begin(),ans.end());
        cout<<minel<<" "<<maxel<<"\n";

    }

}
