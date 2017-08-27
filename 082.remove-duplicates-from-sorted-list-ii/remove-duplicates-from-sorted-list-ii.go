
func deleteDuplicates(head *ListNode) *ListNode {
	if head==nil {
		return nil
	}
	h0:=new(ListNode)
	h0.Next=head
	it:=h0.Next
	res:=new(ListNode)
	itres:=res
	for it!=nil{
		next:=it.Next
		if it.Next==nil||it.Val!=it.Next.Val{
			itres.Next=it
			it.Next = nil
			itres=itres.Next
			it = next

		}else {
			for it.Next!=nil&&it.Val==it.Next.Val{
				it = it.Next
			}
			it = it.Next
		}


	}

	return res.Next
}