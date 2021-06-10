class Solution {
private:
    //Build subtree recursively
	TreeNode* makeSubtree(vector<int>& preorder, vector<int>& inorder, int ins, int ine, int pres, int pree) 
	{
		if(ins > ine || pres > pree)	return nullptr;

		TreeNode * root = new TreeNode(preorder[pres]);
		
		//Make left and right subtree
		int rootIndexIn;
		for(rootIndexIn=ins; rootIndexIn<=ine && inorder[rootIndexIn] != root->val; rootIndexIn++);


		root->left = makeSubtree(preorder, inorder, ins, rootIndexIn-1, pres+1, pres+(rootIndexIn-ins));
		root->right = makeSubtree(preorder, inorder, rootIndexIn+1, ine, (pres+(rootIndexIn-ins))+1, pree);

		return root;
	}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
	{
		TreeNode * root = makeSubtree(preorder, inorder, 0, preorder.size()-1, 0, preorder.size() ); 
		return root;
    }
};
