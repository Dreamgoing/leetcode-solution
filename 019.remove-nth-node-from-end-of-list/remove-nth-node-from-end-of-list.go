
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	iter := head
	pre := new(ListNode)
	pre.Next = head
	head = pre

	cnt:=1
	for iter.Next!=nil {

		iter = iter.Next
		cnt++
		if cnt>n {
			pre = pre.Next
		}
	}

	pre.Next = pre.Next.Next
	return head.Next

}