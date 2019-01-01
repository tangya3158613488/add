#define _CRT_SECURE_NO_WARNINGS 1
1.给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
s 的一个子树包括 s 的一个节点和这个节点的所有子孙。
s 也可以看做它自身的一棵子树。
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
2.给定两个二叉树，编写一个函数来检验它们是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL)
	{
		return true;
	}
	else if (p != NULL && q != NULL)
	{
		return p->val == q->val
			&& isSameTree(p->left, q->left)
			&& isSameTree(p->right, q->right);
	}
	else
	{
		return false;
	}
}
3.给定一个二叉树，返回它的 前序 遍历。
示例 :
输入 : [1, null, 2, 3]
	1

	2
	/
	3

输出 : [1, 2, 3]

	 /**
	 * Definition for a binary tree node.
	 * struct TreeNode {
	 *     int val;
	 *     struct TreeNode *left;
	 *     struct TreeNode *right;
	 * };
	 */
	 /**
	 * Return an array of size *returnSize.
	 * Note: The returned array must be malloced, assume caller calls free().
	 */
	 int treeSize(struct TreeNode*root)
{
		 if (root == NULL)
		 {
			 return 0;
		 }
		 else
		 {
			 return treeSize(root->left) + treeSize(root->right) + 1;
		 }
	 }
	 void _preorderTraversal(struct TreeNode*root, int* preorder, int* pindex)
	 {
		 if (root == NULL)
			 return;
		 preorder[*pindex] = root->val;
		 ++(*pindex);
		 _preorderTraversal(root->left, preorder, pindex);
		 _preorderTraversal(root->right, preorder, pindex);

	 }


	 int* preorderTraversal(struct TreeNode* root, int* returnSize) {
		 *returnSize = treeSize(root);
		 int* preorder = (int*)malloc(*returnSize*sizeof(int));
		 int index = 0;
		 _preorderTraversal(root, preorder, &index);
		 return preorder;
	 }
	 
4.给定一个二叉树，返回它的中序 遍历。
	 示例 :
 输入 : [1, null, 2, 3]
	 1

	 2
	 /
	 3

 输出 : [1, 3, 2]

	  /**
	  * Definition for a binary tree node.
	  * struct TreeNode {
	  *     int val;
	  *     struct TreeNode *left;
	  *     struct TreeNode *right;
	  * };
	  */
	  /**
	  * Return an array of size *returnSize.
	  * Note: The returned array must be malloced, assume caller calls free().
	  */
	  int treeSize(struct TreeNode*root)
 {
		  if (root == NULL)
		  {
			  return 0;
		  }
		  else
			  return treeSize(root->left) + treeSize(root->right) + 1;
	  }

	  void _inorderTraversal(struct TreeNode* root, int* inorder, int *pindex)
	  {
		  if (root == NULL)
			  return;
		  _inorderTraversal(root->left, inorder, pindex);
		  inorder[*pindex] = root->val;
		  ++(*pindex);
		  _inorderTraversal(root->right, inorder, pindex);

	  }
	  int* inorderTraversal(struct TreeNode* root, int* returnSize) {
		  *returnSize = treeSize(root);
		  int* inorder = (int*)malloc(*returnSize*sizeof(int));
		  int index = 0;

		  _inorderTraversal(root, inorder, &index);
		  return inorder;
	  }
	  
5.给定一个二叉树，返回它的 后序 遍历。
	  示例 :
  输入 : [1, null, 2, 3]
	  1

	  2
	  /
	  3

  输出 : [3, 2, 1]

	   /**
	   * Definition for a binary tree node.
	   * struct TreeNode {
	   *     int val;
	   *     struct TreeNode *left;
	   *     struct TreeNode *right;
	   * };
	   */
	   /**
	   * Return an array of size *returnSize.
	   * Note: The returned array must be malloced, assume caller calls free().
	   */
	   int treeSize(struct TreeNode* root)
  {
		   if (root == NULL)
		   {
			   return 0;
		   }
		   else
			   return treeSize(root->left) + treeSize(root->right) + 1;
	   }

	   void _postorderTraversal(struct TreeNode* root, int* postorder, int* pindex)
	   {
		   if (root == NULL)
			   return;
		   _postorderTraversal(root->left, postorder, pindex);
		   _postorderTraversal(root->right, postorder, pindex);
		   postorder[*pindex] = root->val;
		   ++(*pindex);

	   }
	   int* postorderTraversal(struct TreeNode* root, int* returnSize) {
		   *returnSize = treeSize(root);
		   int* postorder = (int*)malloc(*returnSize*sizeof(int));
		   int index = 0;
		   _postorderTraversal(root, postorder, &index);
		   return postorde;
	   }
	   