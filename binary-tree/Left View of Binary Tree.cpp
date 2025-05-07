// easy
// i am using Bfs -> level order traversal to get the left view of the binary tree

/* A binary tree node

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
      vector<int> leftView(Node *root) {
          // code here
          vector<int> ans;
          
          if(!root) return ans;
          
          queue<Node*> q;
          q.push(root);
          
          while(!q.empty()){
              int n = q.size();
              
              for(int i=0;i<n;i++){  // for loop is to traverse each level of the tree
                  // i is used to get the first element of the queue
                  // and push the left and right child of all the node into the queue
                  Node * k= q.front();
                  if(i==0) ans.push_back(k->data);
                  
                  q.pop();
                  if(k->left) q.push(k->left);
                  if(k->right) q.push(k->right);
              }
          }
          return ans;
      }
  };