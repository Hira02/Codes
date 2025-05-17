package main

import "fmt"

type SwitchCase struct{}

func (sc SwitchCase) GetDayName(day int) {
	switch day {
	case 1:
		fmt.Println("Monday")
	default:
		fmt.Println("Some Day")
	}
}
