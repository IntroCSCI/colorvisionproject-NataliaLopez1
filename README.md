# Natalia's Color Vision Project

## Description

Goal: Palette Analyzer
File Type: SVG
For this first deliverable, the program will ask the user for a file name, open that file and display in the console each hexadecimal color value in the file.

### v0.2 Updates

*Coming soon*

### v1.0 Updates

*Coming soon*


## Developer

Natalia Lopez

## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
Please enter the file to be opened:
example.svg 
Hexadecimal color values:
#fff
#fff
#436298
#293c5c
#192538
#fff
#f3e533
#fff
#ff7f00
#fff
#bf0000
#000
```

## C++ Guide

### Variables and Data Types

The data type `string`, which stores text, was used to store the name of the file while the data type `ifstream` allows us to read information from that file. The unsigned integer `position` was assigned the value of the first location of `#` because hexadecimal color values follow this symbol.   

### Console Input and Output

A `cout` statement is used to ask the user to enter the file to be opened. `getline(cin, fileName)` is used to get the user's input. `cout`, alongside the `<<` operator, is also used to output the hexadecimal color values.  

### Decisions

An `if` statement is used to specify the code to be executed if the file is open. If the condition is false, the program terminates. Another `if` statement is used to determine if a hexadecimal color value is a 3-digit one. If the condition is not met, the `else` block of code is executed: the hexadecimal value is a 6-digit one. 

### Iteration

A `while` loop is used to specify the code to be executed while reader is not at the end of the file. When the condition is false, program control passes to the line immediately following the while loop, closing reader. A `for` loop is used to find all the instances in which the specified conditions are true. Another `for` loop is used to print all the the hexadecimal color values. This is achieved by declaring/initializing a counter, setting the condition, `counter < hexValues[counter]`, and incrementing the counter.

### File Input and Output

To access the `fstream` library, I included `#include <fstream>` in my program. Because I only want to read from the file, I use `ifstream`. To read from the file, I use `getline(reader, line)` together with a `while` loop. This block of code loops until reader reaches the end of the file.

### Arrays/Vectors

*Coming in version 0.2*

### Functions

*Coming in version 0.2*

### Classes

*Coming in version 1.0*
