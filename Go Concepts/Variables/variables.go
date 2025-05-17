package main

import "fmt"

func main() {
	// --- Integers ---
	var age int = 30 // Explicit type
	var year = 2025  // Inferred type (int)
	height := 175    // Short declaration

	// --- Floating point ---
	var pi float32 = 3.14 // float32
	var gravity = 9.8     // Inferred as float64
	temperature := -5.5   // float64 via shorthand

	// --- Strings ---
	var firstName string = "Hira"
	var lastName = "Saha"
	fullName := firstName + " " + lastName

	// --- Boolean ---
	var isLearning bool = true
	var hasExperience = false
	wantsToMaster := true

	// --- Constants ---
	const AppName = "GoLang Explorer"
	const Version float64 = 1.0

	// --- Unsigned Integers ---
	var positive uint = 100

	// --- Complex Numbers ---
	var complexNum complex64 = 1 + 2i

	// --- Runes (Unicode characters) ---
	var char rune = 'G'

	// --- Bytes (alias for uint8) ---
	var letter byte = 'A'

	// --- Zero value variables (defaults) ---
	var uninitializedInt int
	var uninitializedString string
	var uninitializedBool bool

	// --- Output ---
	fmt.Println("---------- Integer Types ----------")
	fmt.Println("Age:", age)
	fmt.Println("Year:", year)
	fmt.Println("Height:", height)

	fmt.Println("---------- Float Types ----------")
	fmt.Println("Pi:", pi)
	fmt.Println("Gravity:", gravity)
	fmt.Println("Temperature:", temperature)

	fmt.Println("---------- Strings ----------")
	fmt.Println("First Name:", firstName)
	fmt.Println("Last Name:", lastName)
	fmt.Println("Full Name:", fullName)

	fmt.Println("---------- Booleans ----------")
	fmt.Println("Is Learning:", isLearning)
	fmt.Println("Has Experience:", hasExperience)
	fmt.Println("Wants To Master:", wantsToMaster)

	fmt.Println("---------- Constants ----------")
	fmt.Println("App Name:", AppName)
	fmt.Println("Version:", Version)

	fmt.Println("---------- Unsigned & Complex ----------")
	fmt.Println("Positive:", positive)
	fmt.Println("Complex Number:", complexNum)

	fmt.Println("---------- Rune & Byte ----------")
	fmt.Printf("Rune (char): %c\n", char)
	fmt.Printf("Byte (letter): %c\n", letter)

	fmt.Println("---------- Zero Values ----------")
	fmt.Println("Uninitialized Int:", uninitializedInt)
	fmt.Println("Uninitialized String:", uninitializedString)
	fmt.Println("Uninitialized Bool:", uninitializedBool)
}
