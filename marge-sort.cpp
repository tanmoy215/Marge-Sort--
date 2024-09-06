#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void margesort(vector<int>&a,vector<int>&b,vector<int>&v){
    int i=0,j=0,k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]){
            v[k++]=a[i++];
        }
        else{
            v[k++]=b[j++];
        }
    }
    if(i==a.size()){
        while(j<b.size()){
            v[k++]=b[j++];
        }
    }
    if(j==b.size()){
        while(i<a.size()){
            v[k++]=a[i++];
        }
    }
}
void marge(vector<int>&v){
    int n=v.size();
    if(n==1) return;
    int n1=n/2;
    int n2=n-n/2;
    vector<int>a(n1),b(n2);
    for(int i=0;i<n1;i++){
      a[i]=v[i];  
    }
    for(int j=0;j<n2;j++){
        b[j]=v[j+n1];
    }
    marge(a);
    marge(b);
    margesort(a,b,v);
    a.clear();
    b.clear();
}
int main(){
    int arr[]={5,3,1,5,7,9,1,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
   vector<int>a(arr,arr+n);
   for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
   }
   cout<<endl<<"After margesort"<<endl;
   marge(a);
   for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
   }
}