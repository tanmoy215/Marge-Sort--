#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[]={5,1,8,2,3};
    int n = sizeof(arr)/sizeof(int);
    int count = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
                count++;
            }
        }
    }
    cout<<"Total number of pair : "<<count;
}