#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

TreeNode *build(vector<int> &inorder, vector<int> &preorder, int in_low, int in_high, int pre_low, int pre_high)
{
    if(in_low > in_high || pre_low > pre_high) return NULL;
    if(in_low == in_high || pre_low == pre_high) 
        return new TreeNode(preorder[pre_low]);
    int root_idx = -1;
    for(int i=in_low; i<=in_high; i++) {
        if(inorder[i] == preorder[pre_low]) {
            root_idx = i;
            break;
        }
    }
    if(root_idx == -1) return NULL; // проверка на пустоту
    int left_child_size = root_idx - in_low, right_child_size = in_high - root_idx;
    TreeNode *root = new TreeNode(preorder[pre_low]);
    root->left = build(inorder, preorder, in_low, root_idx-1, pre_low+1, pre_low+left_child_size);
    root->right = build(inorder, preorder, root_idx+1, in_high, pre_high - right_child_size+1, pre_high);
    return root;
}

TreeNode* build_tree_from_inorder_preorder(vector<int> &inorder, vector<int> &preorder) 
{
    if(inorder.empty() || preorder.empty()) return NULL;
    if(inorder.size() != preorder.size()) return NULL;
    int N = inorder.size();
    return build(inorder, preorder, 0, N-1, 0, N-1);
}

void print(TreeNode* r) {
    if(!r) return;
    print(r->left);
    cout << r->val << " ";
    print(r->right);
}

int main() {
    vector<int> inorder = {7,2,1,4,5}; // обход дан прямой
    vector<int> preorder = {1,2,7,5,4}; // обход дан симметричный
    TreeNode *r = build_tree_from_inorder_preorder(inorder, preorder);
    print(r);
  system("pause");
  return 0;
}
