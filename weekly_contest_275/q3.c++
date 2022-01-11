#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        vector<int> bitdig;
        vector<int> digcountstart;
        vector<int> digcounttarget;
        for(int i=0;i<startWords.size();i++){
            int num = 0;
            for(int j=0;j<startWords[i].size();j++){
                num|=1<<((startWords[i][j]-'a'));
                
            }
            digcountstart.push_back(startWords[i].size());
            bitdig.push_back(num);
        }
        
        vector<int> bitdige;
        for(int i=0;i<targetWords.size();i++){
            int num = 0;
            for(int j=0;j<targetWords[i].size();j++){
                num|=1<<(targetWords[i][j]-'a');
                
            }
            digcounttarget.push_back(targetWords[i].size());
            bitdige.push_back(num);
        }
        int ans=0;
        vector<int> vis(targetWords.size(),0);
        
        for(int i=0;i<startWords.size();i++){
            for(int j=0;j<targetWords.size();j++){
            
            if(vis[j]!=0) continue;
            
              //  return digcountstart[i];
            if(digcountstart[i]==digcounttarget[j]+1) continue;
             int s=bitdig[i],k=bitdige[j];
             int dec = s^k;
             
            if(dec==0) continue;
            if((dec&(dec-1))==0){
                ans++;
                vis[j] = 1;
            }
            }
        }
        
        return ans;
    }
};
int main(){

}