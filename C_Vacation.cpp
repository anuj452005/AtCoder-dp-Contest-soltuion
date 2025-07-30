#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ll int long long 
void solve(){
    int n;
    cin>>n;

    vector<vector<int>>arr;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr.push_back({a,b,c});
    }
    vector<vector<int>>dp(n+1,vector<int>(3,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            dp[i][j]=INT_MIN;
            for(int k=0;k<3;k++){
                if(k!=j){
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+arr[i-1][j]);
                }
            }
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<3;i++){
        ans=max(ans,dp[n][i]);
    }
    cout<<ans<<endl;


}

signed  main(){
    fast
{
solve();


}
   return 0;
}