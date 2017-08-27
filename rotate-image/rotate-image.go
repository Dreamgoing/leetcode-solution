func rotate(matrix [][]int)  {
	n:=len(matrix)
	if n == 0 {
		return
	}
	l,r:=0,n-1
	for l<r {
		matrix[l],matrix[r] = matrix[r],matrix[l]
		l++
		r--
	}
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			matrix[i][j],matrix[j][i] = matrix[j][i],matrix[i][j]
		}
	}

}