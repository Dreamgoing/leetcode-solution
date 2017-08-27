///求数组中元素的和等于target的所有组合数，所有组合不同

///法一：用dfs(i+1,1) 和 dfs(i+1,0) ,即取第i位和不取第i位的思想来做，会导致无法去重

///法二：用类似dp的思想，dfs(i,c) 表示从第i位开始取，背包容量还有c
///初始条件为dfs(0,target),对于每一个符合candidates[pos]<target,进行dfs(pos+1,c-target)递归
///结束条件为target==0,则找到了一个解。target<0,或没有找到则返回上一层
///去重条件，i>start&&candidates[i]==candidate[i-1],则continue



func combinationSum2(candidates []int, target int) [][]int {

	res:= make([][]int, 0)
	sort.Ints(candidates)

	dfsCombination2_method2(&res,candidates,[]int{},0,target)
	return res
}

///法一
func dfsCombination2_method1(res *[][]int,cand []int,now []int,step int,sum int,target int)  {

	if sum==target {
		tmp:=make([]int,len(now))
		copy(tmp,now)
		//sort.Ints(tmp)
		*res = append(*res,tmp)
		return
	}
	if step>=len(cand) || sum>target{
		return
	}

	//fmt.Printf("pre %v %v\n",now ,step)
	now=append(now,cand[step])

	///@note 传参数append也是会直接改变内存
	dfsCombination2_method1(res,cand,now,step+1,sum+cand[step],target)
	///返回原来now

	//fmt.Printf("now %v %v\n",now,step)
	now = now[0:len(now)-1]
	dfsCombination2_method1(res,cand,now,step+1,sum,target)


}
///法二
func dfsCombination2_method2(res *[][]int,cand []int,now []int,start int,target int)  {
	if target==0 {
		tmp:=make([]int,len(now))
		copy(tmp,now)
		*res=append(*res,tmp)
		return
	}
	for i := start; i < len(cand); i++ {
		if i > start && cand[i] == cand[i-1] {
			///去重条件
			continue
		}
		if cand[i]<=target {
			now = append(now,cand[i])
			dfsCombination2_method2(res,cand,now,i+1,target-cand[i])
			now = now[:len(now)-1]
		}else {
			///
			break
		}

	}
}