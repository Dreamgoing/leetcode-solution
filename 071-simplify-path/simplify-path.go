func simplifyPath(path string) string {

	res:=""
	///Split 函数用来分隔字符串
	pathByte:=bytes.Split([]byte(path),[]byte("/"))



	pathStack:=make([]string,0)
	for i:=range pathByte{
		tmp:=string(pathByte[i])
		//fmt.Printf("%v\n",tmp)
		if tmp == ".." {
			if len(pathStack) > 0 {
				pathStack = pathStack[:len(pathStack)-1]
			}
		}else{
			if tmp!="."&&tmp!=""{
				pathStack = append(pathStack,tmp)
			}
		}
	}
	for i:=range pathStack{
		res+="/"
		res+=pathStack[i]
	}
	if res=="" {
		res="/"
	}
	return res
}