#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
public:
    void eulerian_path(int pos,vector<vector<int> > adj,vector<int> &outdeg,deque<int> &sol){
        if(outdeg[pos]!=0)
        for(auto &it:adj[pos]){          //for all adjacent nodes do traverse one by one
                    if(it!=-1&&outdeg[pos]!=0){   
                     outdeg[pos]--;
                     int k=it;
                     it=-1;
                    eulerian_path(k,adj,outdeg,sol); 
                    }       
         } 
        
        if(outdeg[pos]==0)
        sol.push_front(pos);
    }
    
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        vector<vector<int> > ans;
        set<int> stemp;
        for(int i=0;i<pairs.size();i++){        //o(nlogn)
            stemp.insert(pairs[i][0]);
            stemp.insert(pairs[i][1]);
        }
        
        
        vector<int> lookuptableV;
        unordered_map<int,int> lookuptableHM;
        int pos=0;
        for(auto it=stemp.begin();it!=stemp.end();it++){        //o(n)
            lookuptableV.push_back(*it);
            lookuptableHM[*it] = pos;
            pos++;
        }
        
        vector<vector<int> > dummy;
        
        for(int i=0;i<pairs.size();i++){        //o(n)
            dummy.push_back({lookuptableHM[pairs[i][0]],lookuptableHM[pairs[i][1]]});
        }
        
        
        int limit=lookuptableV.size()+1;

        vector<vector<int> > adj(limit);
       
        vector<int> indeg(limit),outdeg(limit);
        
        for(int i=0;i<dummy.size();i++){    //o(n)
            
            adj[dummy[i][0]].push_back(dummy[i][1]) ;
            indeg[dummy[i][1]]++;
            outdeg[dummy[i][0]]++;
        }
         
        int startpos=INT_MAX;
        for(int i=0;i<indeg.size();i++){
            if(outdeg[i]-indeg[i] == 1)     //it is the source
            {
                startpos = i;   
                break;
            }
        }
        
        deque<int> sol;
        if(startpos== INT_MAX){

            eulerian_path(dummy[0][0],adj,outdeg,sol);
        }
        else{
            eulerian_path(startpos,adj,outdeg,sol);
        }
        
        // int num=sol.size();
        // ans.push_back({num});
        // return ans;
        for(auto it=sol.begin();it!=sol.end()-1;it++){      //o(n)
            ans.push_back({*it,*(it+1)});
        }
        
        for(int i=0;i<ans.size();i++){          //
            ans[i][0] = lookuptableV[ans[i][0]];
            ans[i][1] = lookuptableV[ans[i][1]];
        }
        return ans;
        
    }
};
int main(){

}