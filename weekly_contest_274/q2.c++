#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        int k=0;
        for(int i=0;i<bank.size();i++){
            int s=0;
            for(int j=0;j<bank[i].length();j++){
                if(bank[i][j]=='1') s++;
            }
            
            ans+=k*s;
            
            if(s!=0)
            k=s;
        }
        
        return ans;
    }
};
int main(){

}