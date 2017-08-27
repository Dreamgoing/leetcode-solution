
func restoreIpAddresses(s string) []string {
	n:=len(s)
	if n>12 {
		return []string{}
	}
	res:=make([]string,0)
	rs:=[]rune(s)
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n-1; j++ {
			for k := j + 1; k < n-1; k++ {
				if isVaild(rs,0,i)&&isVaild(rs,i+1,j)&&
					isVaild(rs,j+1,k)&&isVaild(rs,k+1,n-1) {
					tmp:=""
					tmp+=string(rs[0:i+1])+"."+string(rs[i+1:j+1])+"."+string(rs[j+1:k+1])+"."+string(rs[k+1:n])
					res = append(res,tmp)
				}
			}
		}
	}
	return res
}

func isVaild(in []rune,l,r int) bool {
	num:=0

	///排除前导零的情况

	if in[l]=='0'&&r>l{
		return false
	}
	for i := l; i <= r; i++ {
		num*=10
		num+=int(in[i])-int('0')
	}
	return num<=255&&num>=0
}