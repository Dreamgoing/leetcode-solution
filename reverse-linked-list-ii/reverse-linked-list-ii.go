/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode,m int,n int)  *ListNode{
	vhead:=new(ListNode)
	vhead.Next=head

	prehead:=vhead
	for i := 0; i < m-1; i++ {

		prehead=prehead.Next
	}
	//fmt.Println(prehead.Val)
	tmphead:=prehead.Next
	tmppre:=new(ListNode)
	it:=tmphead
	for i := 0; i < n-m+1; i++ {
		tmpnext:= it.Next
		it.Next=tmppre
		tmppre = it
		it = tmpnext
	}
	//fmt.Println(it.Val,tmppre.Val,tmphead.Val)
	tmphead.Next=it
	prehead.Next=tmppre
	return vhead.Next

}
