#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector <vector<ll>> graph;
ll n;



int main(){
 ifstream Topo("os.topo");

 Topo>>n;

graph.assign(n,vector<ll>(n,0));
 for(int i=0;i<n;i++)
   for (int j=0;j<n;j++)
    { Topo>>graph[i][j];
    if(i==j)
      graph[i][j]=0;
      if(graph[i][j]==-1)
      graph[i][j]=(long long)(1e16);
      }
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]); 
        }
    }
}

  for(auto i=0;i<34;i++)
    {for(auto j=0;j<34;j++)
    {
    cout<<graph[i][j]<<" ";
  
    }cout<<endl;
    }

return 0;
}