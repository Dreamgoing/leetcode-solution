# Definition for single-linked list.
class ListNode(object):
    def __init__(self,x):
        self.val = x
        self.next = None
class Solution(object):
    def mergeKLists(self,lists):
        """

        :param lists: List[ListNode]
        :return: ListNode
        """
        if len(lists)==0:
            return None
        if len(lists)==1:
            return lists[0]
        l1 = self.mergeKLists(lists[:len(lists)/2])
        l2 = self.mergeKLists(lists[len(lists)/2:])
        head = self.merge2Lists(l1,l2)
        return head

    def merge2Lists(self,la,lb):
        """

        :param la: ListNode
        :param lb: ListNode
        :return: ListNode
        """
        if la is None:
            return lb
        elif lb is None:
            return la
        else:
            p = ListNode(0)
            dummyhead = p
            while la is not None and lb is not None:
                if la.val < lb.val:
                    p.next = la
                    la = la.next
                else:
                    p.next = lb
                    lb = lb.next
                p = p.next

            if la is not None:
                p.next = la
            else:
                p.next = lb
        return dummyhead.next

