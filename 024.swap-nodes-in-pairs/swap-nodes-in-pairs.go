func swapPairs(head *ListNode) *ListNode {
	it:=head

	if it == nil || it.Next == nil{
		return it
	}
	itt:=it.Next
	res:=head.Next
	pre:=new(ListNode)
	for itt!=nil{
		tmp:=itt.Next
		pre.Next = itt
		itt.Next = it
		it.Next = tmp
		pre = it

		if tmp == nil||tmp.Next==nil {
			break
		}
		it = tmp
		itt = it.Next
	}
	return res
}