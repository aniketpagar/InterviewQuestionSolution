package main

import (
	"fmt"
	"sort"
)

func main() {
	//define slice
	// var arr1 []int
	// arr1 = append(arr1, 11)
	arr := []int{2, 1, 6, 12, 34, 0}

	//sort the slice using sort function
	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})
	fmt.Println(arr)

}
