#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            int n=matrix.size();
            vector<int> dec(n,0);
            for(int j=0;j<matrix.size();j++){
                dec[matrix[i][j]-1] = 1;
            }
            
            for(int j=0;j<matrix.size();j++){
                if(dec[j]==0) return false;
            }
        }
        
        for(int i=0;i<matrix.size();i++){
            int n=matrix.size();
           vector<int> dec(n,0);
            for(int j=0;j<matrix.size();j++){
                dec[matrix[j][i]-1] = 1;
            }
            
            for(int j=0;j<matrix.size();j++){
                if(dec[j]==0) return false;
            }
        }
        
        return true;
    }
};
int main(){

}