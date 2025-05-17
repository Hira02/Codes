package main

import "fmt"

type Loop struct{}

func (L Loop) PrintTill(n int) {
	for i := 1; i <= n; i++ {
		fmt.Println(i)
	}
}
