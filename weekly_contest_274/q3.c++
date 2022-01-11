#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long int mas=mass;
        for(int i=0;i<asteroids.size();i++){
            if(mas<asteroids[i])
                return false;
            else
            {
                mas+=asteroids[i];
            }
        }
        return true;
    }
};
int main(){

}