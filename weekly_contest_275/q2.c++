#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int w_size = 0;
        for(int i=0; i<nums.size(); i++) w_size+=nums[i];
        
        if(w_size == nums.size()) return 0;
        else if( w_size == 0) return 0;
        int w_max = 0;
        int left = 0;
        int right = w_size - 1;
        for(int i=0; i<w_size; i++) w_max+=nums[i];
        int curr = w_max;
        
        right++;
        left++;
        while(right<nums.size()){
            curr = curr + (-nums[left - 1] + nums[right]);    
            if(curr > w_max) w_max = curr;
            left++;
            right++;
        }
        
        //checking begining window sum + end window sum //as array is circuler
        while( (right%nums.size() ) < w_size ){
            curr = curr + (-nums[(left-1)%nums.size()] + nums[right%nums.size()]);
            if(curr > w_max) w_max = curr;
            left++;
            right++;
        }
          
        return w_size - w_max ;
    }
};
int main(){

}