func isBalanced(root *TreeNode) bool {
	res,_:=dfsIsBalanced(root)
	return res

}

func dfsIsBalanced(root *TreeNode)(bool,int){
	if root==nil{
		return true,0
	}

	leftOk,lDepth:= dfsIsBalanced(root.Left)
	rightOk,rDepth:=dfsIsBalanced(root.Right)
	return leftOk&&rightOk&&(myAbs(lDepth,rDepth)<=1),maxInt(lDepth,rDepth)+1
}
func maxInt(a int,b int) int  {
	if a<b {
		return b
	}else {
		return a
	}
}
func myAbs(a,b int)int  {
	if a > b {
		return a-b
	}else {
		return b-a
	}
}