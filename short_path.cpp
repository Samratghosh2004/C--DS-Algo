#include<bits/stdc++.h>
using namespace std;
int main() {
    int line;   //No of line
    vector<int> m[100];  //NO of nodes
    int x,y;
    cin>>x>>y;
    m[x].push_back(y);  //adjacency list here
    m[y].push_back(x);
    int arr[line] = {0};

    int min[line] ;     // defined for short distance

    int source = 1;      // defined for source
    arr[source]=1;
    min[source]=1;

    queue<int> set;     // declearing queue
    set.push(source);
    do{
        int a= set.front();     //Starting from the top
        set.pop();              
        for(int b : m[a]) {
            if(!arr[b]) {
                arr[b] =1;
                set.push(b);

                arr[b] = arr[a]+1;
                arr[b] =a;
            }
        }
    }
    // while (set.full())
    while(!set.empty());

    for(int i=0; i<line;i++) {
        cout<<arr[i]<<endl;
    }
    
}