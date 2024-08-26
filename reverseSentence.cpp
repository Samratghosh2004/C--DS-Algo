#include<bits/stdc++.h>
using namespace std;

bool valid (char ch) {
    if (( ch >='a'&& ch <= 'z') ||(ch >='A'&& ch <= 'Z') ||(ch = 32))
        return 1;
    else{
        return 0;
    }
}

char uperLower(char ch) {
    if ( ch >='a'&& ch <= 'z') 
        return ch;
    else{
        char temp = ch-'A'+'a';
        return temp;
    }
}
char revrseSentence(string ch) {
    int x =0;
    int y=ch.length() -1;
    while(x<=y) {
        if(ch[x] = 32) {
            break;
        }
        swap(x,y);
        x++;
        y--;
    }
    return 1;
}


int main() {
    string ch;
    cout<<"Enter the sentence what you want to reverse :"<<endl;
    cin>>ch;
    string temp ="";
    for(int i =0;i<ch.length();i++) {
        if(valid(ch[i])) {
            temp.push_back(ch[i]);
        }
    }
    for(int i =0;i< temp.length();i++) {
        temp[i] = uperLower(temp[i]);
    }
    cout<<"The ans is :"<<temp;
}