#include<iostream>
#include<list>
#include<vector>
#include <queue>
using namespace std;

########Graph to be commmitted

class Graph{
    public:
    list<int> *adj;
    int n;
    Graph(int V){
        adj=new list<int> [V];
        n=V;
    }
    void assign(int u,int v,bool x){
        adj[u].push_back(v);
        if(x)
        adj[v].push_back(u);
    }
    void print(){
        for(int i=0;i<n;i++){
            cout<<i<<"->";
            for(auto it:adj[i]){
                cout<<it<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    void solution(){
        vector<int> bfs;////bfs 
        vector<int> vis(n+1,0);/////visited list

        for(int i=0;i<n;i++){////// we have to traverse through each vertice of the graph 
            if(!vis[i]){//////checking that the node is visited or not
                queue<int> q;////creating queue for storing the 
                q.push(i);/////push that element in the queue and it would be at font 
                vis[i]=1;/////mark that as visited
                   
                   while(!q.empty()){/////now we have to clean the queue to move to the next node 
                       int node = q.front();////creating a node justt to delte the front one in a queue
                       q.pop();///popping out
                       bfs.push_back(node);/////pushing that element to the bfs 
                       
                       for(auto it:adj[node]){////now we traverse to eah adjacent element in the node 
                           if(!vis[it]){/////if those are not visited then we can simply arks visited 
                               q.push(it);///and push them to queue
                               vis[it]=1;///////marks that it also 
                           }
                       }
                                          }


            }

        }
        for(int i=0;i<bfs.size();i++){
            cout<<bfs[i]<<" ";
        }
    }
};

int main(){
  
    Graph g(6);
    g.assign(1, 2, true);
    g.assign(2, 3, true);
    g.assign(3, 4, true);
    g.assign(4, 5, true);
    g.assign(5, 1, true);
    g.assign(5, 2, true);
    g.print();
    g.solution();
}
