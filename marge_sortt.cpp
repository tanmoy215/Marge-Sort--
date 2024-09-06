#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void marge(vector<int>&a,vector<int>&b,vector<int>&v){
    int i=0,k=0,j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]){
           v[k++]=a[i++];
        }
        else {
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
void margesort(vector<int>&v){
    int n = v.size();
    if(n==1) return;
    int n1 = n/2,n2=n-n/2;
    vector<int>a(n1),b(n2);
    for(int i=0;i<n1;i++){
        a[i]=v[i];
    }
    for(int i=0;i<n2;i++){
        b[i]=v[n1+i];
    }
    margesort(a);
    margesort(b);
    marge(a,b,v);
    a.clear();
    b.clear();
}
int main(){
int arr[]={1,2,4,0,1,3,5,6,8,3,2,6};
int n = sizeof(arr)/sizeof(arr[0]);
vector<int> a(arr,arr+n);
cout<<"After sorting"<<endl;
margesort(a);
for(int i=0;i<a.size();i++){
    cout<<a[i]<<" ";
}
}