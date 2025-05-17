package main

func main() {
	age := 32
	day := 3

	ifElse := IfElse{}
	loop := Loop{}
	switchCase := SwitchCase{}

	ifElse.CheckAge(age)
	loop.PrintTill(10)
	switchCase.GetDayName(day)
}
