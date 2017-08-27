
func partition(head *ListNode,x int)*ListNode {

	///h0为自定义添加的一个头部
	h0:=new(ListNode)
	h0.Next = head
	l:=h0
	///l为第一个大于等于x的节点的前一个节点，即从开始位置连续小于x的最后一个的节点
	for l.Next!=nil&&l.Next.Val<x{
		l = l.Next
	}
	///r为第一个大于等于x的节点
	r:=l.Next
	if r==nil{
		return head
	}
	it:=r.Next
	for it!=nil{
		tmp:=it.Next
		//tmpnext:=it.Next.Next
		if it.Val < x {
			lnext:=l.Next
			l.Next = it
			it.Next = lnext
			r.Next = tmp
			l = it
		}else {
			r = it
		}
		it = tmp

	}

	return h0.Next
}