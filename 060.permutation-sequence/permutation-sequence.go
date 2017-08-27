///类似于next_permutation
func getPermutation(n int, k int) string {
	a:=make([]uint8,n)
	for i:=range a{
		a[i] = uint8(i)+1
	}
	k--
	for k>0{
		nextPermute1(a,0,n-1)
		k--
	}
	//fmt.Printf("%v\n",a)
	iToS:=[]byte("123456789")
	ret:=make([]byte,n)
	for i := 0; i < len(a); i++{
		ret[i] = iToS[a[i]-1]
	}
	return string(ret)
}

func nextPermute1(nums []uint8,first,last int)bool  {
	if first==last {
		return false
	}
	r:=last
	it:=r

	itt:=r
	it--
	for it>=0{
		if nums[it]<nums[itt] {
			for nums[r]<=nums[it]{
				r--
			}
			nums[it],nums[r] = nums[r],nums[it]
			reverse1(nums,itt,last)
			return true
		}
		it--
		itt--
	}

	reverse1(nums,first,last)
	return false

}
func B2S(bs []int8) string {
	ba := make([]byte,0, len(bs))
	for _, b := range bs {
		ba = append(ba, byte(b))
	}
	return string(ba)
}
func reverse1(nums []uint8,first,last int)  {
	for first<last{
		nums[first],nums[last] = nums[last],nums[first]
		first++
		last--
	}
}