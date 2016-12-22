class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> money = getMoney(root);
        return max(money[0], money[1]);
    }

    vector<int> getMoney(TreeNode* node)
    {
        vector<int> money(2, 0);
        if(!node)
            return money;
        vector<int> moneyLeft = getMoney(node->left);
        vector<int> moneyRight = getMoney(node->right);
        //do not rob this one
        money[0] = max(moneyLeft[0], moneyLeft[1]) + max(moneyRight[0], moneyRight[1]);
        //rob this one
        money[1] = moneyLeft[0] + moneyRight[0] + node->val;
        return money;
    }

};
