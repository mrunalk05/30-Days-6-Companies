/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void rec1(TreeNode* root, vector<int> &v){
     if(root==NULL) return;
        rec1(root->left, v);
        v.push_back(root->val);
        rec1(root->right, v);

    }

    void rec2(TreeNode* root, vector<int> &v1){
     if(root==NULL) return;
        rec2(root->left, v1);
        v1.push_back(root->val);
        rec2(root->right, v1);

    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v;
        vector<int> v1;
        vector<int> ans;
        rec1(root1, v);
        rec2(root2, v1);
        
        for(int i=0; i<v1.size(); i++){
            ans.emplace_back(v1[i]);
        }
        for(int i=0; i<v.size(); i++){
            ans.emplace_back(v[i]);
        }
        sort(ans.begin(), ans.end());
       return ans;
    }
};
