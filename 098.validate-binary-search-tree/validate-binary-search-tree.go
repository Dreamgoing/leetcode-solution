/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
	return validRange(root,-math.MaxInt64,math.MaxInt64)
}

func validRange(root *TreeNode,low, high int) bool{
	if root==nil {
		return true
	}
	return root.Val<high&&root.Val>low&& validRange(root.Left,low,root.Val)&&
		validRange(root.Right,root.Val,high)
}