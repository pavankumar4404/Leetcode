/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // vector<int> ans;
    // void solve(Node* root) {
    //     if (!root)
    //         return;

    //     int n = root->children.size();
    //     for(int i=0; i<n; i++){
    //         solve(root->children[i]);
    //     }
    //     ans.push_back(root->val);
    // }
    // vector<int> postorder(Node* root) {
    //     solve(root);
    //     return ans;
    // }

    vector<int> postorder(Node* root) {
        if (root == NULL)
            return {};
        vector<int> res;
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node* temp = stk.top();
            stk.pop();
            for (int i = 0; i < temp->children.size(); i++)
                stk.push(temp->children[i]);
            res.push_back(temp->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};