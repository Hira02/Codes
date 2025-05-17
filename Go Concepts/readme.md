## All "Go Lang" concept
```
package main
```
tells that “Hey, this code should be compiled into a binary, and it should look for a main() function to start with.” This is a standalone executable program, not shared library.
```
import "fmt"
```
import "fmt"
Imports the formatted I/O package from the Go standard library.
Gives you access to print, format, and input functions.
```
fmt.Println()           Prints with a newline                       fmt.Println("Hello") → Hello\n
fmt.Print()             Prints without a newline                    fmt.Print("Hello") → Hello
fmt.Printf()            Formatted print (like C’s printf)           fmt.Printf("Hi %s", "Hira")
fmt.Sprint()            Returns a formatted string (doesn’t print)  s := fmt.Sprint("Hi")
```
Because without it, Go won’t know how to handle functions like Println() or Printf()—they’re not built-in keywords, but functions inside the fmt package.
