var id int
type Node struct {
	word int
	next[26] *Node
}

type RuneSlice []rune

func (p RuneSlice)Len() int {
	return len(p)
}
func (p RuneSlice)Less(i,j int)bool  {
	return p[i]<p[j]
}
func (p RuneSlice) Swap(i,j int)  {
	p[i],p[j] = p[j],p[i]
}
func (root *Node)insert(str *[][]string,words []rune) bool{
	n:=len(words)
	tmp:=make([]rune,n)
	copy(tmp,words)
	sort.Sort(RuneSlice(tmp))
	//fmt.Printf("%v\n",string(tmp))
	it:=root
	for i:=0;i<n;i++{
		pos:=tmp[i]-'a'
		if it.next[pos] == nil {
			it.next[pos] = new(Node)
		}
		it = it.next[pos]
	}
	if it.word == 0 {
		id = id+1
		*str = append(*str,[]string{})
		it.word = id

	}
	(*str)[it.word-1] = append((*str)[it.word-1],string(words))
	return true
}
func groupAnagrams(strs []string) [][]string {
	res:=make([][]string,0)
	node:=new(Node)
	id = 0
	for i:=range strs{
		node.insert(&res,[]rune(strs[i]))
	}
	return res
}