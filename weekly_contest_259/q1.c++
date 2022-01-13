#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(int i=0; i<operations.size(); i++)
            if(operations[i][1] == '+') ans++;
            else ans--;
        return ans;
    }
};
int main(){

}