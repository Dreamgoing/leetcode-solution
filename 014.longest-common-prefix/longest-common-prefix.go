func longestCommonPrefix(strs []string) string {

	n:=len(strs)
	if n==0 || len(strs[0])==0{
		return string("")
	}

	s:=[]rune(strs[0])
	for i := 1; i < n; i++ {
		if len(strs[i]) == 0 {
			return string("")
		}
		tmps:=[]rune(strs[i])
		s = []rune(comPrefix(s,tmps))
		
	}
	return string(s)
}

func comPrefix(a, b []rune) string{

	n:=len(a)
	if n > len(b) {
		n=len(b)
	}
	var pos int = 0
	for i := 0; i < n; i++ {
		if a[i]!=b[i]{
			break
		}
		pos++
	}
	if pos == 0 {
		return string("")
	} else {
		return string(a[0:pos])
	}
}