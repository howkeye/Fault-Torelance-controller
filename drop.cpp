#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector< vector <int> > controller_list;
vector <vector<ll>> graph;
ll average_case_controller,worse_case_controller;
ll n;

ll minimum(int i,vector <int> & controller){
   ll l=graph[i][controller[0]];
   
    for(auto j: controller)
  {
  
  l=min(l,graph[i][j]);
    // cout<<endl<<"i: "<<i<<" "<<j<<" "<<l<<endl;
  }
 return l;
      
}


pair<long long,long long> check(vector <int> & controller){
  long long ans=0,worsecase=0;
  for(int i=0;i<n;i++)
  {ll t=minimum(i,controller);
    ans+=t/n;
  worsecase=max(worsecase,t);}

  return {ans,worsecase};
} 
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
      graph[i][j]=(long long)(1e12);
      }


  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]); 
        }
      }
    }

ll k;
cout<<"Input K: ";
cin>>k;
cout<<"Enter Controllers";
vector <int> l(k,0);
for(auto i=0;i<k;i++) cin>>l[i];
ll worse_case=0,avg_case;

pair<ll,ll> ans;
ans=check(l);
cout<<"Wihout Drop\n"<<endl;
cout<<ans.first<<" "<<ans.second<<endl<<endl<<"With drop\n";



for(int i=0;i<k;i++){
  vector <int> controller;
  for(int j=0;j<k;j++)
    if(i!=j)
     controller.push_back(l[j]);
    pair<ll,ll> ans;
    ans=check(controller);
    worse_case+=ans.second;
    avg_case+=ans.first;
    cout<<ans.first<<" "<<ans.second<<endl;
}
cout<<"\nAvg Case: "<<avg_case/k<<endl;
cout<<"Worse Case: "<<worse_case/k<<endl;
return 0;
}