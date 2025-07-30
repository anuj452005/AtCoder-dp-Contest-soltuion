#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ll int long long 
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    // topological sort
    vector<int>indegree(n+1,0);
    for(int i=1;i<=n;i++){
        for(auto j:graph[i]){
            indegree[j]++;
        }
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto j:graph[node]){
            indegree[j]--;
            if(indegree[j]==0){
                q.push(j);
            }
        }
    }
    vector<int>dp(n+1,0);
    for(int i=0;i<topo.size();i++){
        int node=topo[i];
        for(auto j:graph[node]){
            dp[j]=max(dp[j],dp[node]+1);
        }
    }
    cout<<*max_element(dp.begin(), dp.end())<<endl;
}

signed  main(){
    fast
{
solve();


}
   return 0;
}