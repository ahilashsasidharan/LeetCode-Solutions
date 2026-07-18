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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == nullptr) return false;
                
        std::stack<pair<TreeNode*, bool>> nodes;
        bool visited = false;
        
        int sum = 0;

        nodes.emplace(root, false);

        while(!nodes.empty()){
            TreeNode* curr = nodes.top().first;
            visited = nodes.top().second;
            nodes.pop();

            if(visited == true){
                sum -= curr->val;
                continue;
            }

            sum += curr->val;

            if(curr->left == nullptr && curr->right == nullptr){
                if(sum == targetSum) return true;
                sum -= curr->val;
                continue;
            }

            // add back the node you are getting children of as visited
            nodes.emplace(curr, true);

            if(curr->left == nullptr){
                nodes.emplace(curr->right, false);
            }
            else if(curr->right == nullptr){
                nodes.emplace(curr->left, false);
            }
            else{
                nodes.emplace(curr->right, false);
                nodes.emplace(curr->left, false);
            }
        }
        return false;        
    }
};