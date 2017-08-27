/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSymmetric(root *TreeNode) bool {
	if root==nil {
		return true
	}else {
		return dfsSymmetric(root.Left,root.Right)
	}
}

func dfsSymmetric(left, right *TreeNode) bool {
	if left==nil&&right==nil {
		return true
	}else if left!=nil&&right!=nil {
		if left.Val!=right.Val {
			return false
		}else {
			return dfsSymmetric(left.Right,right.Left)&&
				dfsSymmetric(left.Left,right.Right)
		}
	}else {
		return false
	}
}