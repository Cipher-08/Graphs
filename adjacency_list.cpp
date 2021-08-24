#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[] ,int V){
    for(int i=0;i<V;i++){
        cout<<i;
        for(auto x:adj[i]){
            cout<<"->"<<x;
        }
        cout<<endl;
    }
}

int main(){
   int n,m;
   cin>>n>>m;
   vector<int>adjc[n];
   for(int i=0;i<m;i++){
       int x,y;
       cin>>x>>y;
       addEdge(adjc,x,y);
   }
   for(int i=0;i<n;i++){
       cout<<i;
       for(auto x: adjc[i]){
           cout<<"->"<<x;
       }
       cout<<endl;
   }

}
