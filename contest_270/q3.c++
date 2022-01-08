#include<bits/stdc++.h>
using namespace std;
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    TreeNode* lca(TreeNode* root,int p,int q){
        if(!root||root->val==p||root->val==q) return root;
        TreeNode* left = lca(root->left,p,q);
        TreeNode* right = lca(root->right,p,q);
        
        if(left&&right) return root;
        else if(left) return left;
        else if(right) return right;
        else return NULL;
    }
    
    int path(TreeNode* root, int p,string &s){
        if(!root) return 0;
        if(root->val == p) return 1;
        s.push_back('L');
        int left = path(root->left,p,s);
        if(left) return 1;
        s.pop_back();
        
        s.push_back('R');
        int right = path(root->right,p,s);
        if(right) return 1;
        s.pop_back();
        return 0;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = lca(root,startValue,destValue);
        string result="";
        string dummy = "";
        int pl = path(root, startValue,dummy);
        for(int i=0;i<dummy.length();i++){
            result+="U";
        }
        path(root, destValue,result);
        return result;
    }
};
int main(){

}