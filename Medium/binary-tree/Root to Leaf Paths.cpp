//medium
//dfs to traverse all paths (recursion & backtracking)

/*
Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    public:
      void dfs(Node *root, vector<int> &curr, vector<vector<int>> &ans ){
          if(!root) return;
          
          curr.push_back(root->data);
          
          if(!root->left && !root->right){
              ans.push_back(curr);
          }
          else{
              dfs(root->left, curr, ans);
              dfs(root->right, curr, ans);
          }
          
          curr.pop_back();
      }
    
      vector<vector<int>> Paths(Node* root){
          // code here
          
          vector<vector<int>> ans;
          vector<int> curr;
          
          dfs(root,curr,ans);
          return ans;
      }
  };