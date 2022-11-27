package main

import "fmt"
type num uint

func counting_sort(a []num) (b []num) {
	b=make([]num, len(a))
	var max num=0
	for i:=0; i<len(a); i++ {
		if a[i] > max { max = a[i] }
	}
	v := make([]int, max+1) 
	for i:=0; i<len(v); i++ { v[i]=0 }
	for i:=0; i<len(a); i++ { v[a[i]]++ }
	for i:=1; i<len(v); i++ { v[i]+=v[i-1] }
	for i:=len(a)-1; i>=0; i-- {
		b[v[a[i]]-1]=a[i]
		v[a[i]]--
	}
	return
}

func main() {
	var v [20]num
	for i:=0; i<20; i++ {
		v[i]=num(70-i)
	}
	fmt.Println(counting_sort(v[:]))
}
