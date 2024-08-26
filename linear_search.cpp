#include<bits/stdc++.h>
using namespace std;

bool search (int arr[] ,int size, int key) {
    for(int i = 0; i<size;i++) {
        if(arr[i]==key)
            return 1;
    }
    return 0 ;
}

int main() {
    int arr[11] = {2,5,18,23,54,7,4,1,9,11,19};
    int key;
    cout<< "Enter the element that you want to find"<<endl; 
    cin>> key;
    

    bool get = search(arr, 11, key);

    if (get) {
        cout<<"The number of key is present "<<endl;
    }
    else {
        cout<<"The key is absent"<<endl;
    }
    return 0;
}