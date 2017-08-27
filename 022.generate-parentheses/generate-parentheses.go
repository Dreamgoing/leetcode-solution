func generateParenthesis(n int) []string {
	res:=[]string{}
	addPath(&res,string(""),n,n)
	return res
}
func addPath(res *[]string,str string,l int,r int)  {
	if l==0&&r==0{
		*res = append(*res,str)
		return 
	}

	if l == r {
		addPath(res,fmt.Sprintf("%s%s",str,"("),l-1,r)
	}else if l < r {
		if l > 0 {
			addPath(res,fmt.Sprintf("%s%s",str,"("),l-1,r)
		}
		addPath(res,fmt.Sprintf("%s%s",str,")"),l,r-1)
	}

}