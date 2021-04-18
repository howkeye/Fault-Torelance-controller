#include<bits/stdc++.h>
using namespace std;
int value (string s){
    if(s=="Inf")
    return -1;
    return int(floor(stold(s)));
}
int main(){
    long double g[34][34];
    string s;
    for(int i=0;i<34;i++)
      {  for(int j=0;j<34;j++)
        {
            cin>>s;
            cout<<value(s)<<" ";
          
        }
        cout<<endl;
      }
        

}