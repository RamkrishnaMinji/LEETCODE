#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class DetectSquares {
public:
    
    // unordered_map<int, unordered_map<int,int> > rcc;    //row column count
    // unordered_map<int, unordered_map<int,int> > colrow;      //column row
    map<pair<int,int> , int > p;
    DetectSquares() {  
    }
    
    void add(vector<int> point) {
        p[{point[0],point[1]}]++;
    
    }
    int count(vector<int> point) {
        int ans = 0;
        for(auto it = p.begin(); it!=p.end() ; it++){
           
        if(  it->first.first!=point[0] && it->first.second!= point[1]  && (abs(it->first.first - point[0]) == abs(it->first.second - point[1]))  )
        {       int a=0,b=0;
                auto it1 = p.find({it->first.first,point[1]});
                if(it1!=p.end()){
                    a = it1->second;
                }
                auto it2 = p.find({point[0],it->first.second});
                if(it2!=p.end()){
                    b = it2->second;
                }
                ans+=(a*b*it->second);  
            }
        }
        return ans;
    }
    
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
int main(){

}