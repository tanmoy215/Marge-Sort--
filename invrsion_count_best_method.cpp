#include<iostream>
#include<vector>
using namespace std;
int c=0;
int inversion(vector<int>&a,vector<int>&b){
    int i=0,j=0;
    int count=0;
    while(i<a.size() && j<b.size()){
        if(a[i]>b[j]){
            count+=(a.size()-i);
            j++;
        }
        else{
            i++;
        }
    }
    return count;
}
void marge(vector<int>&a,vector<int>&b,vector<int>&v){
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
void margesort(vector<int>&v){
    int n=v.size();
    if(n==1) return;
    int n1=n/2,n2=n-n/2;
    vector<int>a(n1),b(n2);
    for(int i=0;i<n1;i++){
        a[i]=v[i];
    }
    for(int i=0;i<n2;i++){
        b[i]=v[n1+i];
    }
    margesort(a);
    margesort(b);
    c+=inversion(a,b);
    marge(a,b,v);
    a.clear();
    b.clear();
}
int main(){
    int arr[]={5,1,8,2,3};
    int n=sizeof(arr)/sizeof(int);
    vector<int> v(arr,arr+n);
    margesort(v);
    cout<<"Total no. of inversion count : "<<c;
}