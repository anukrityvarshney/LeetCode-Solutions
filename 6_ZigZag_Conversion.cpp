#include<bits/stdc++.h>
using namespace std;

string convert(string s, int numRows) {
    int n= s.length();
    if(numRows==1)return s;
    string res="";
    vector<string> answer(numRows);
    bool isCountON=false;
    int county=0;
    for(int i=0;i!=n;i++){
        if(county==numRows-1)isCountON=true;
        if(isCountON&& county!=0){
            answer[county]+=s[i];
            county--;
            continue;
        }
        if(county==0)isCountON=false;
        answer[county]+=s[i];
        county++;
    }
    for(int i=0;i<numRows;i++){
        res+=answer[i];
    }
    return res;
}

int main(){
    string arr1="anukrity";

    cout<<convert(arr1,3);
    return 0;
}
