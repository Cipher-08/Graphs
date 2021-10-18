#include<iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;

class Graph{
    public:
       int n;
       list<int> *adj;
       Graph(int v){
           adj = new list<int> [v];
           n=v;
       }
       void addEdge(int u,int v,bool x){
           adj[u].push_back(v);
           if(x)adj[v].push_back(u);
       }
       bool checkForcycle(int s, vector<int> vis){
            queue<pair<int,int>>q;
            vis[s]=1;
            q.push({s,-1});
            while (!q.empty())
            {
                
                int node = q.front().first;
                int par = q.front().second;
                q.pop();
                for(auto it:adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push({it,node});
                    }
                    else if(par!=it)return true;
                }
            }
            return false;
            
       }

       bool cycle(){
           vector<int> vis(n+1,0);
           for(int i=0;i<n;i++){
               if(!vis[i]){
                  if(checkForcycle(i,vis))return true;
               }
           }
           return false;

       }

       
};
