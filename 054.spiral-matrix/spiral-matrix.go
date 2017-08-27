
func spiralOrder(matrix [][]int) []int {
	res := make([]int,0)
	h:=len(matrix)
	if h==0{
		return []int{}
	}
	w:=len(matrix[0])
	x,y:=0,0

	for h>0&&w>0{
		tmpx:=w
		for tmpx>0{
			res = append(res,matrix[y][x])
			x++
			tmpx--
		}
		x--
		y++
		tmpy:=h-1
		if tmpy<=0 {
			break
		}
		for tmpy>0{
			res = append(res,matrix[y][x])
			y++
			tmpy--
		}
		x--
		y--
		tmpx = w-1
		if tmpx <= 0 {
			break
		}
		for tmpx>0{
			res = append(res,matrix[y][x])
			x--
			tmpx--
		}
		x++
		y--
		tmpy = h-2
		if tmpy<=0 {
			break
		}
		for tmpy>0{
			res = append(res,matrix[y][x])
			y--
			tmpy--
		}
		w-=2
		h-=2
		x++
		y++
	}
	return res
}