#define _CRT_SECURE_NO_WARNINGS 1
1.���������ǿն����� s �� t������ s ���Ƿ������ t ������ͬ�ṹ�ͽڵ�ֵ��������s ��һ���������� s ��һ���ڵ������ڵ���������s Ҳ���Կ����������һ��������
������Ҫ���õݹ��˼�룺

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
2.����һ�����������ҳ��������ȡ�
�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

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
3.����һ����������������Ƿ��Ǿ���ԳƵġ�


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
}4.����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
�����У�һ�ø߶�ƽ�����������Ϊ��
һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������1��


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

