///注意二分还是类，lower_bound写法
func searchMatrix(matrix [][]int, target int) bool {
	l,r:=0,len(matrix)

	///空间为0的情况
	if r == 0||len(matrix[0])==0 {
		return false
	}
	end:=len(matrix[0])
	
	for l<r{
		m:=l+(r-l)/2
		if target>matrix[m][end-1] {
			l = m+1
		}else if target<matrix[m][0]{
			r = m-1
		}else {
			r = m
		}
	}

	///没找到对应区间
	if l == len(matrix)||target>matrix[l][end-1]||target<matrix[l][0] {
		return false
	}

	///第二次二分看区间里是否有解
	pos:=l
	l,r=0,len(matrix[pos])
	for l<r{
		m:=l+(r-l)/2
		if target>matrix[pos][m] {
			l = m+1
		}else {
			r = m
		}
	}
	return matrix[pos][l]==target
}