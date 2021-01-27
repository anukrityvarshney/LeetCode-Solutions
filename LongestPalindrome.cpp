#include<bits/stdc++.h>
using namespace std;

int evenPalin(string s, int i, int n){
    int county = 2;
    int j=i+2;
    for(int k=i-1;k>=0&&j<n;k--){
        if(s[k]==s[j]){
            county+=2;
            j++;
            }
        else break;
    }
    return county;
}

int oddPalin(string s, int i, int n){
    int county = 3;
    for(int k=i-1,j=i+3;k>=0 && j<n;k--){
        if(s[j]==s[k]){
            county+=2;
            j++;
            }
        else break;
    }
    return county;
}

string longestPalindrome(string s) {

    int n = s.length();
    string ans= "";
    ans+=s[0];
    int county = 1;
    int aux;
    if(n==1)return s;
    for(int i= 0;i<n-1;i++){
        if(s[i]==s[i+1]){
            aux= evenPalin(s,i,n);
            if(county < aux){
                county = aux;
                ans = s.substr(i+1-county/2, county);
            }
        }
        if(i<(n-2) && s[i]==s[i+2]){
           aux= oddPalin(s,i,n);
           if(county < aux){
               county = aux;
               ans = s.substr(i+1-county/2, county);
            }
        }
    }
    return ans;
}

int main(){
    string s="aaabadabcbada";
    cout<<longestPalindrome(s);
    return 0;
}
