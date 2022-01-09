#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans=0;
        map<string,int> m;
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
        
        int extra = 0;      
        vector<int> visans;     //visit ans
        
        for(auto it=m.begin(); it!=m.end(); it++){
            if(it->second == 0) continue;
            if(it->first[0]==it->first[1]){
                if(it->second%2==0){
                    visans.push_back(it->second);
                }
                else{
                    extra=1;
                    visans.push_back(it->second - 1);
                }
            }
            else{
                string cmplmnt = "__";
                cmplmnt[1] = it->first[0];
                cmplmnt[0] = it->first[1];
                
                auto ptr = m.find(cmplmnt);
                if(ptr == m.end()) continue;
                visans.push_back(2*min(it->second, ptr->second));
                ptr->second = 0;
            }
            
        }
        
        
        for(int i=0;i<visans.size();i++){
            ans+=visans[i];
        }
        
        return (ans+extra)*2;
    }
};

int main(){

}