
type ByStart []Interval

///自定义排序规则
func (a ByStart)Len()int {
	return len(a)
}

func (a ByStart)Swap(i,j int)  {
	a[i],a[j] = a[j],a[i]
}
func (a ByStart)Less(i,j int) bool  {
	if a[i].Start!=a[j].Start{
		return a[i].Start<a[j].Start
	}else {
		return a[i].End<a[j].End
	}
}

///@brief 合并两个区间，需要保证a.Start<=b.Start&&a.End>=b.Start
func mergeTwo(a,b Interval) Interval {
	var res Interval
	res.Start = a.Start
	if a.End > b.End {
		res.End = a.End
	}else {
		res.End = b.End
	}
	return res
}

func merge(intervals []Interval) []Interval {
	sort.Sort(ByStart(intervals))
	res:=make([]Interval,0)
	n:=len(intervals)
	pos:=0
	for pos<n {
		tmp:=intervals[pos]
		for pos < n && tmp.Start <= intervals[pos].Start && tmp.End >= intervals[pos].Start {
			tmp = mergeTwo(tmp,intervals[pos])
			//fmt.Printf("%v",tmp)

			pos++
		}
		res = append(res,tmp)
	}
	return res
}