package main

import ( 
	"fmt" 
	"math/rand"
)

const SIZE=16
var v [SIZE]uint = [SIZE]uint{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

func count_digit(a []uint) uint {
	max:=uint(1)
	for i:=0; i<len(a); i++ {
		fmt.Println(a[i])
		for a[i]/max>0 { max*=SIZE }
	}
	return max
}

func clear() {
	for i:=0; i<SIZE; i++ { v[i]=0 }
}

func digit(a []uint, i uint, d uint) uint {
	return a[i]/d%16
}

func counting_sort(a []uint, d uint) (b []uint) {
	b=make([]uint, len(a))
	for i:=0; i<len(a); i++ { v[digit(a, uint(i), d)]++ }
	for i:=1; i<SIZE; i++ { v[i]+=v[i-1] }
	for i:=len(a)-1; i>=0; i-- {
		b[v[digit(a, uint(i), d)]-1]=a[i]
		v[digit(a, uint(i), d)]--
	}
	clear()
	return
}

func radix_sort(a []uint) []uint {
	d:=count_digit(a)
	for i:=uint(1); i<d+1; i*=16 {
		a = counting_sort(a, i)
	}
	return a
}

func main() {
	var a [20]uint
	for i:=uint(0); i<20; i++ {
		a[i]=uint(rand.Intn(4294967295))
	}
	fmt.Println(radix_sort(a[:]))
}
