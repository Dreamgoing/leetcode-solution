func setZeroes(matrix [][]int)  {
	var row,col bool=false,false
	for i:=range matrix{
		for j:=range matrix[i]{
			//fmt.Printf("%v ",matrix[i][j])
			if matrix[i][j]==0{
				matrix[i][0] = 0
				matrix[0][j] = 0
				if i == 0 {
					row = true
				}

				if j == 0 {
					col = true
				}
			}
		}
	}

	///注意边界：避免重复写入
	for i:=1;i<len(matrix);i++{
		for j:=1;j<len(matrix[i]);j++{
			if matrix[i][0]==0||matrix[0][j]==0 {
				matrix[i][j] = 0
			}
		}
	}


	///对0行，0列进行特殊边界处理
	if col {
		for i := 0; i < len(matrix); i++ {
			matrix[i][0] = 0
		}
	}

	if row {
		for j := 0; j < len(matrix[0]); j++ {
			matrix[0][j] = 0
		}
	}


}