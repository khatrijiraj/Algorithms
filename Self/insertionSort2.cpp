#include<iostream>
using namespace std;

void insertionSort(int array[20], int n){
    int i, j, key;
    for(j=1;j<n;j++){
        key=array[j];
        i=j-1;
        while(i>=0 && array[i]>key){
            array[i+1]=array[i];
            i=i-1;
        }
        array[i+1]=key;
    }
    cout<<"Array: ";
    for(int i = 0; i < n; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int array[20],n;
    cout<<"Enter the size of array: ";
    cin>>n;
    for(int z =0; z<n; z++){
        cout<<"Enter element "<<z+1<<": ";
        cin>>array[z];
    }
    insertionSort(array,n);
    return 0;
}