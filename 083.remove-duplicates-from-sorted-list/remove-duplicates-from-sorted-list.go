func deleteDuplicates(head *ListNode) *ListNode {
	if head==nil {
		return nil
	}
	it:=head
	for it.Next!=nil{
		if it.Val == it.Next.Val {
			it.Next=it.Next.Next
		}else {
			it=it.Next
		}
	}
	return head

}