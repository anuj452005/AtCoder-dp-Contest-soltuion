#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define  int long long 
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        dp[i][i]=arr[i];
    }
    for(int len=2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j=i+len-1;
            dp[i][j]=max(arr[i]-dp[i+1][j], arr[j]-dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;
}

signed  main(){
    fast
{
solve();
}
   return 0;
}