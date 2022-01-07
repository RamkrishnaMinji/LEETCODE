#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int dc = digits.size();
        vector<int> ans;
        
        int id[10] = {0};   //to stop repetataion of digits
        for(int i=0;i<dc;i++){
            if(digits[i]!=0){
                if(id[digits[i]]==0){
                id[digits[i]]=1;
                    
                 int jd[10] = {0};      //to stop repetation of digits
                 for(int j=0;j<dc;j++){
                    if(j!=i&&jd[digits[j]]==0){
                        jd[digits[j]] = 1;
                        
                        for(int k=0;k<dc;k++){
                            if(k!=i&&k!=j){
                                int num = digits[i]*100+digits[j]*10+digits[k];
                                if(num%2==0)
                                ans.push_back(num);
                            }
                        }
                    }
                }
                
                }

            }
        }
        sort(ans.begin(),ans.end());
        set<int> s(ans.begin(),ans.end());
        vector<int> res(s.begin(),s.end());
        return res;
    }
};
int main(){

}

//normal loops but some modification done by maintainig a array of digis to avoid repitation