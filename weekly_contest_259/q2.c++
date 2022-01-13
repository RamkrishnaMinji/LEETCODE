#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 1 3 5 6 4 6 7 9 8  10 12 nums[]
    //   1 3 5 6 6 6 7 9  9     prev_max
    //   4 4 4 6 7 8 8 10 12    next_min
    int sumOfBeauties(vector<int>& nums) {
        int ans = 0;
        int prev_max = nums[0];
        int next_min = nums[nums.size()-1];
        vector<pair<int,int> > comp(nums.size() , pair<int,int> (0,0));
       
        for(int i=1;i<nums.size()-1;i++){
            comp[i].first = prev_max;
            if(nums[i] > prev_max) prev_max = nums[i];
        }
         
        for(int i = nums.size() - 1; i>=1; i--){
            comp[i].second = next_min;
            if(nums[i] < next_min) next_min = nums[i];  
            
        }

        for(int i = 1; i < nums.size()-1; i ++){
            if(nums[i]>comp[i].first && nums[i] < comp[i].second) ans += 2;
            else if(nums[i]>nums[i-1] && nums[i]<nums[i+1] ) ans += 1;
        }
        return ans;
    }
};
int main(){

}