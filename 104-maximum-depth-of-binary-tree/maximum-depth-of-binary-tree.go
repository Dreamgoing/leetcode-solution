/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxInt(a int,b int) int  {
	if a<b {
		return b
	}else {
		return a
	}
}
func maxDepth(root *TreeNode) int {
	if root==nil{
		return 0
	}
	return maxInt(maxDepth(root.Right),maxDepth(root.Left))+1
}