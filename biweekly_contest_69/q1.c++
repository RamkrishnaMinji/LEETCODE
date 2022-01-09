#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
public:
    string capitalizeTitle(string title) { 
        for(int i=0;i<title.length();i++){
            if(i>=title.length())
            return title;
            int j=0;
            while(i+j<title.length()&&title[i+j]!=' '){
                j++;
            }
            if(j<=2){
                if(title[i]<='Z'&&title[i]>='A')
                    title[i] += 32;
                if(title[i+1]<='Z'&&title[i+1]>='A')
                    title[i+1] += 32;
            }
            else if(j>2){
                if(title[i]<='z'&&title[i]>='a')
                    title[i] -= 32; 
                for(int k=i+1;k<i+j;k++){
                    if(title[k]<='Z'&&title[k]>='A') title[k]+=32;
                }
            }             
            i+=j;
        }
        return title;
    }
};
int main(){

}