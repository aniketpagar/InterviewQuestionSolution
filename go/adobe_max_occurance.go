//Find k numbers with most occurrences in the given array
//arr[] = {3, 1, 4, 4, 5, 2, 6, 1},
//k = 2
//Output: 4 1

package main

import (
	"fmt"
	"sort"
)

func main() {
	arr := []int{3, 1, 4, 4, 5, 2, 6, 1, 5}
	arr = append(arr, 5)

	var freqMap map[int]int
	if freqMap == nil {
		freqMap = make(map[int]int)
	}

	//put the data in freMap
	for _, v := range arr {
		freqMap[v] += 1
	}
	//display
	// for k, v := range freqMap {
	// 	fmt.Println(k, " : ", v)
	// }
	//add it in slice & sort the slice

	var sliceA [][2]int
	for k, v := range freqMap {
		sliceA = append(sliceA, [2]int{k, v})
	}
	// fmt.Println(sliceA)

	//sort the sliceA
	sort.Slice(sliceA, func(i, j int) bool {
		return sliceA[i][1] > sliceA[j][1]
	})

	// fmt.Println(sliceA)
	k := 2
	for i := 0; i != k; i++ {
		fmt.Println(sliceA[i][0])
	}

}
