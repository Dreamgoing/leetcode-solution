func rotateRight(head *ListNode, k int) *ListNode {
	if head==nil {
		return nil
	}
	end:=head
	num:=1
	for end.Next!=nil{
		num++
		end = end.Next
	}
	pos:=k%num

	///如果移动位数正好等于链表长度
	if pos == 0 {
		return head
	}

	it:=head

	///头节点为倒数第pos个，即顺数第num+1-pos
	
	pos = num-pos
	
	///找到头节点的前一位
	for pos>1{
		it = it.Next
		pos--
	}

	end.Next = head
	head = it.Next
	it.Next = nil
	return head

}