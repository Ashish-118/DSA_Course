// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// void findNode(TreeNode* root,TreeNode* Node,stack<TreeNode *> &p,int &check){
// if(root==NULL){
//     return;
// }
// if(Node==root){
//     check++;
//     p.push(root);
//     return;
// }

// p.push(root);
// findNode(root->left,Node,p, check);
// if(check==0){
// findNode(root->right,Node,p, check);

// }
// if (check == 0) {
//         p.pop();
//     }


// }
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         stack<TreeNode* > p1;
//         stack<TreeNode* > q1;
//         int check=0;
//         findNode(root,p,p1,check);
//         check=0;
//         findNode(root,q,q1,check);
//          stack<TreeNode* > p2;
//          stack<TreeNode* > q2;
//         //check same node
//         TreeNode *ans=NULL;
//        while (!p1.empty()) {
//             p2.push(p1.top());
//             p1.pop();
//         }
//         while (!q1.empty()) {
//             q2.push(q1.top());
//             q1.pop();
//         }
        
//         while (!p2.empty() && !q2.empty() && p2.top() == q2.top()) {
//             ans = p2.top();  
//             p2.pop();
//             q2.pop();
//         }

//         return ans;

//     }
// };


//BAbaray mehtod

// TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//       if(root==NULL) return NULL;
//       if(root==p || root==q) return root;

//      TreeNode* left= lowestCommonAncestor(root->left,p,q);
//      TreeNode* right= lowestCommonAncestor(root->right,p,q);

//       if(left!=NULL && right!=NULL) return root;
//       else if(left!=NULL && right==NULL) return left;
//       else if(left==NULL && right!=NULL) return right;
//       else return NULL;

//     }