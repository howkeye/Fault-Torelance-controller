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
  cout<<i<<" "<<l<<endl;
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

vector <int> l(k,0);
for(auto i=0;i<k;i++) cin>>l[i];
controller_list.push_back(l);


cout<<"Total combination ckecked: "<<controller_list.size();
long long avg_lat=LONG_LONG_MAX,worse_case=LONG_LONG_MAX;
for(int i=0;i<controller_list.size();i++){
  auto ans=check(controller_list[i]);
  avg_lat=min(avg_lat,ans.first);

  worse_case=min(worse_case,ans.second);
    if(avg_lat==ans.first)
    average_case_controller=( ll)i;

      if(worse_case==ans.second)
    worse_case_controller=( ll)i;
    
}

  cout<<endl<<"Average case latency :"<<avg_lat<<endl;
  cout<<"controllers are: ";

  for(auto i:controller_list[average_case_controller])
    cout<<i<<" ";
  cout<<endl<<"Worse case latency :"<<worse_case<<endl;
  cout<<"Worse Case controller :";
  for(auto i:controller_list[worse_case_controller])
    cout<<i<<" ";
  
 
  //  for(auto i:controller_list)
  //  {
  //    for(auto j:i)
  //     cout<<j<<" ";
  //     cout<<endl; 
  //  }
return 0;
}