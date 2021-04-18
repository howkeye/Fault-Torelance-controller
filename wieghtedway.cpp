#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector< vector <int> > controller_list;
vector <vector<ll>> graph;
ll average_case_controller,worse_case_controller;
ll n;ll k;
float weight[]={1,1,1,0,0,0,0,0,0};
void generate_combination(int i,int k,vector <int> l){
if(k==0){
    controller_list.push_back(l);
    return ;
}
if(i>=n) return;
generate_combination(i+1,k,l);
l.push_back(i);
generate_combination(i+1,k-1,l);
}
ll minimum(int i,vector <int> & controller){
  set <ll> st;
   ll l=graph[i][controller[0]];
   
    for(auto j: controller)
  {
  st.insert(graph[i][j]);
  }

  ll ans=0;
  auto w=0;
  double weight_total=0;
  for (auto j:st)
   { ans+=j*weight[w];
   weight_total+=weight[w];
   w++;
   }
   // cout<<weight_total<<endl;
 return (ll)(ans);
      
}


pair<long long,long long> check(vector <int> & controller){
 // for(auto i:controller) cout<<i<<" ";

  long long ans=0,worsecase=0;
  for(int i=0;i<n;i++)
  {
    ll t=minimum(i,controller);
    ans+=t/n;
    worsecase=max(worsecase,t);
  }


  // cout<<"Average Case :"<<ans;
  // cout<<" and worse Case :"<<worsecase<<endl;

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
      graph[i][j]=(long long)(1e16);
      }


  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]); 
        }
      }
    }
// for(int i=0;i<graph.size();i++)
//  { for(int j=0;j<graph.size();j++)
//   { cout<<graph[i][j]<<" ";
    
//   }
//   cout<<endl;
//  }

cout<<"Input K: ";
cin>>k;

vector <int> l;
generate_combination(0,k,l);
cout<<"Total combination ckecked: "<<controller_list.size();
long long avg_lat=LONG_LONG_MAX,worse_case=LONG_LONG_MAX;
ll temp=-1;
for(int i=0;i<controller_list.size();i++){
  if(temp!=controller_list[i][0])
  {
    cout<<controller_list[i][0]<<endl;
    temp=controller_list[i][0];
  }
  auto ans=check(controller_list[i]);
 //if(worse_case>ans.second)
 if(avg_lat>ans.first)
  {
  avg_lat=ans.first;
  worse_case=ans.second;
  average_case_controller=( ll)i;
  worse_case_controller=( ll)i;
  }  
}

  cout<<endl<<"Average case latency :"<<avg_lat<<endl;
  cout<<"controllers are: ";

  for(auto i:controller_list[average_case_controller])
    cout<<i<<" ";
  cout<<endl<<"Worse case latency :"<<worse_case<<endl;
  cout<<"Worse Case controller :";
  for(auto i:controller_list[worse_case_controller])
    cout<<i<<" ";
  
 

return 0;
}