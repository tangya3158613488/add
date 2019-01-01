#define _CRT_SECURE_NO_WARNINGS 1
1.给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。
本题主要运用递归的思想：

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool isSametree(struct TreeNode* s, struct TreeNode* t)
{
	if (s == NULL && t == NULL)
	{
		return true;
	}
	else if (s != NULL && t != NULL)
	{
		return s->val == t->val
			&& isSametree(s->left, t->left)
			&& isSametree(s->right, t->right);
	}
	else
	{
		return false;
	}
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if (s == NULL)
		return false;
	if (isSametree(s, t))
		return true;
	else if (isSubtree(s->left, t))
		return true;
	else if (isSubtree(s->right, t))
		return true;
	else
		return false;


}
2.给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明 : 叶子节点是指没有子节点的节点。

	 /**
	 * Definition for a binary tree node.
	 * struct TreeNode {
	 *     int val;
	 *     struct TreeNode *left;
	 *     struct TreeNode *right;
	 * };
	 */
	 int maxDepth(struct TreeNode* root) {
		 if (root == NULL)
			 return 0;
		 int leftDepth = maxDepth(root->left);
		 int rightDepth = maxDepth(root->right);
		 return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;

	 }
3.给定一个二叉树，检查它是否是镜像对称的。


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool _isSymmetric(struct TreeNode* left, struct TreeNode* right)
{
	if (left == NULL && right == NULL)
		return true;
	if (left == NULL || right == NULL)
		return false;
	return left->val == right->val
		&&  _isSymmetric(left->left, right->right)
		&& _isSymmetric(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
		return true;
	return  _isSymmetric(root->left, root->right);
}4.给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool _isBalanced(struct TreeNode* root, int* pdepth)
{
	if (root == NULL)
	{
		*pdepth = 0;
		return true;
	}
	int leftdepth = 0;
	int rightdepth = 0;
	if (_isBalanced(root->left, &leftdepth)
		&& _isBalanced(root->right, &rightdepth)
		&& abs(leftdepth - rightdepth) < 2)
	{
		*pdepth = leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
		return true;
	}
	else
	{
		return false;
	}
}

bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;
	int depth = 0;
	return _isBalanced(root, &depth);

}

