package main

import "fmt"

type IfElse struct{}

func (i IfElse) CheckAge(age int) {
	if age < 13 {
		fmt.Println("You are child")
	} else if age < 18 {
		fmt.Println("You are teenage")
	} else {
		fmt.Println("You are adult")
	}
}
