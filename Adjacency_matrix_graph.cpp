 /*By Saksham Awasthi*/
               
#include<bits/stdc++.h>
using namespace std;
               
               
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
               
               
const int N=1e5+2 , MOD =1e9+7;
               
               
signed main()
{
    int n,m;
    cin>>n>>m;
    vvi adjc(n+1,vi(n+1,0));   

    loop(i,0,m)
    {
        int x,y;
        cin>>x>>y;
        adjc[x][y]=1;
        adjc[y][x]=1;
    }

    cout<<"Adjacency mattrix of given graph is -> "<<endl;
    loop(i,1,n+1){
        loop(j,1,n+1){
          cout<<adjc[i][j]<<" ";
        }
        cout<<endl;
    }
               
return 0;
}
