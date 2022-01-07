#include<bits/stdc++.h>
using namespace std;

#define pb push_back

class Graph{
    public:
       list<int> *adj;
       int v;///no. of vertices
       Graph(int n){
           this->v = n;
           this->adj = new list<int>[this->v];

       }
       void addEdge(int u , int v, bool bidir= true){
           adj[u].pb(v);
           if(bidir){
               adj[v].pb(u);
           }
       }
       void dfs_helper(int src, unordered_map<int,bool> &visited){
           visited[src]=true;
           cout<<src<<" ";
           for(auto neighbour: this->adj[src]){
                if(not visited[neighbour]){
                    dfs_helper(neighbour,visited);
                }
           }
       }
       void dfs(int src){
           unordered_map<int , bool> visited;
           dfs_helper(src , visited);

       }

       int connectedComponent(){
           unordered_map<int, bool> visited;
           int result =0;
           for(int i = 0;i<v-1;i++){
               dfs_helper(i,visited);
               result++;
           }
           return result;
       }

};

int main(){

    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(3,2);
    g.addEdge(4,5);
   g.connectedComponent();

}
