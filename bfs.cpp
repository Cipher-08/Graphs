#include<bits/stdc++.h>
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


class Graph{

   public:

   list<int> *adj;
   int n;

   Graph(int V){
       adj = new list<int> [V];
       n = V;



   }
   void assign(int u,int v,bool x=true){
         adj[u].push_back(v);
         if(x){
             adj[v].push_back(u);
         }
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

   void bfs(){
       vector<int> bfs;
       vector<int> vis(n+1,0);

       loop(i,0,n){
           if(!vis[i]){
               queue<int> q;
               q.push(i);
               vis[i]=1;

               while(!q.empty()){
                   int node = q.front();
                   q.pop();
                   bfs.push_back(node);
                   for(auto it:adj[node]){
                       if(!vis[it]){
                       q.push(it);
                       vis[it]=1;
                   }
                   }
               }
           }
       }
       cout<<bfs.size()<<endl;
       for(int i=0;i<bfs.size();i++){
           cout<<bfs[i]<<" ";
       }
   }

};

int main(int argc, char const *argv[]) {
    Graph g(6);
    g.assign(1,2);
    g.assign(2,3);
    g.assign(3,4);
    g.assign(4,5);
    g.assign(5,1);
    g.assign(5,2);
    // g.print();
    g.bfs();

    return 0;
}
