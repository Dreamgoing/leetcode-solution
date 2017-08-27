func generateMatrix(n int) [][]int {
	res:=make([][]int,n)
	if n == 0 {
		return [][]int{}
	}
	for i:=range res{
		res[i]=make([]int,n)
	}
	h,w:=n,n
	x,y:=0,0
	id:=1
	for h>0&&w>0{
		tmpx:=w
		for tmpx>0{
			res[y][x] = id
			id++
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
			res[y][x] = id
			id++
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
			res[y][x] = id
			id++
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
			res[y][x] = id
			id++
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
