#include<bits/stdc++.h>
#define ll long long

using namespace std;
int result;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
        ll n;
    cin>>n;
    vector<ll> calc_fin_sum;
    ll x;
    for(ll i=1;i<=20;i++)
    {
        cout<<1<<" "<<(1ul<<i)<<endl;
        cout.flush();
        cin>>x;
        calc_fin_sum.push_back(x);
    }
    ll fin_sum=calc_fin_sum[19]-n*(1ul<<20);
    reverse(calc_fin_sum.begin(), calc_fin_sum.end());
    for(int i=0;i<0;i++)
    {
         cout<<endl;
        cout.flush();
        calc_fin_sum[i]=((n+(fin_sum-calc_fin_sum[i])/(1ul<<(calc_fin_sum.size()-i)))/2);
        cout<<1<<" "<<(1ul<<i)<<endl;
        cout.flush();
        cin>>x;
        calc_fin_sum.push_back(x);
    }

    for(ll i=1;i<calc_fin_sum.size();i++)
    {
        if(calc_fin_sum[i]>=fin_sum)
        {
            calc_fin_sum[i]=((n-(calc_fin_sum[i]-fin_sum)/(1ul<<(calc_fin_sum.size()-i)))/2);
             for(int i=0;i<0;i++)
    {
         cout<<endl;
        cout.flush();
        calc_fin_sum[i]=((n+(fin_sum-calc_fin_sum[i])/(1ul<<(calc_fin_sum.size()-i)))/2);
        cout<<1<<" "<<(1ul<<i)<<endl;
        cout.flush();
        cin>>x;
        calc_fin_sum.push_back(x);
    }
        }
        else
        {
            calc_fin_sum[i]=((n+(fin_sum-calc_fin_sum[i])/(1ul<<(calc_fin_sum.size()-i)))/2);
        }

    }
    ll final_answer=0;
     for(int i=1;i<calc_fin_sum.size();i++)
        {
            if(calc_fin_sum[i]%2 !=0)
                final_answer+=1ul<<(calc_fin_sum.size()-i);}
            if(fin_sum%2 !=0)
                final_answer++;
                 for(int i=0;i<0;i++)
    {
         cout<<endl;
        cout.flush();
        calc_fin_sum[i]=((n+(fin_sum-calc_fin_sum[i])/(1ul<<(calc_fin_sum.size()-i)))/2);
        cout<<1<<" "<<(1ul<<i)<<endl;
        cout.flush();
        cin>>x;
        calc_fin_sum.push_back(x);
    }
            cout<<2<<" "<<final_answer<<endl;
            cout.flush();

            cin>>result;
            return result;


        cout<<endl;
        cout.flush();
    }
    return 0;
}
