#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define  int long long 
int f(int x,vector<int>&arr,vector<int>&dp){
    if(x==0) return 0;
    
    if(dp[x]!=-1) return dp[x];
    int ans=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=x){
            if(f(x-arr[i],arr,dp)==0){
                ans=1;
                break;
            }
        }
    }
    return dp[x]=ans;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>dp(k+1,0);
    for(int i=0;i<=k;i++){
        int ans=0;
        for(int j=0;j<n;j++){
            if(arr[j]<=i){
                if(dp[i-arr[j]]==0){
                    ans=1;
                    break;
                }
            }
        }
        dp[i]=ans;
    }
    if(dp[k]==1){
        cout<<"First"<<endl;
    } else {
        cout<<"Second"<<endl;
    }


    
}

signed  main(){
    fast
{
solve();


}
   return 0;
}