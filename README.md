# Natalia's Color Vision Project

## Description

Goal: Palette Analyzer
File Type: SVG
For this final deliverable, the program will ask the user for a file name, open that file, display in the console each unique hexadecimal color value in the file, and identify and display the hexadecimal color values which are difficult to distinguish from one another. 

### v0.2 Updates

v.02 identifies all the unique hexadecimal color values in the file and displays them in the console. Furthermore, it determines which hexadecimal color values are hard to distinguish from one another and displays them in the console. v.02 now uses a `cin` instead of a `getline` to store the file name in the corresponding variable because the user will only be inputting one word for the file name.
v0.2 makes use of functions to determine if a hexadecimal color value is unique and to identify which hexadecimal colors are hard to distinguish from one another.

### v1.0 Updates

In case the user has bad input, v1.0 now makes use of a `do while` loop which keeps asking the user for a file to be opened until the file is successfully opened. Additionally, v1.0 makes use of member functions to determine if a string is a hexadecimal color value and to determine if a hexadecimal color value is unique. v1.0 uses `getline` to store the file name in the corresponding variable because using `cin` would repeat `Please enter the file to be opened:` for each whitespace the user has in their input.


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
bad input
Please enter the file to be opened:
example.svg 
There are 8 unique Hexadecimal colors in example.svg:
#fff
#436298
#293c5c
#192538
#f3e533
#ff7f00
#bf0000
#000
The following Hexadecimal colors are difficult to distinguish from one another:
#436298
#293c5c
#192538
#000000
```

## C++ Guide

### Variables and Data Types

The data type `string`, which stores text, was used to store the name of the file while the data type `ifstream` allows us to read information from that file. The integer `position` was assigned the value of the first location of `#` because hexadecimal color values follow this symbol. The string `hexString` is initialized to `line.substr(position)`. `hexString` is the argument of the member function `isHexColor`.   

### Console Input and Output

A `cout` statement is used to ask the user to enter the file to be opened. `getline` is used to get the user's input. `cout`, alongside the `<<` operator, is also used to output the hexadecimal color values.

### Decisions

An `if` statement is used to specify the code to be executed if the file is open. Another `if` statement is used to determine if the string `hexColor` is unique from the strings of the vector `compareColors`. If `hexColor` is unique, `hexColor` is returned. If `hexColor` is not unique, then an empty string is returned. An additional `if` statement is used to determine if the hexadecimal color values will be added to the vector `hexValues`. Within the function `distinguishColors`, an `if` and an `else if` statement are used to convert white (`#fff`) and black (`#000`) to their 6-digit equivalents: `#ffffff` and `#000000` respectively. 

### Iteration

A `while` loop is used to specify the code to be executed while reader is not at the end of the file. When the condition is false, program control passes to the line immediately following the while loop, closing reader. A `for` loop is used to find all the instances in which the specified conditions are true. Another `for` loop is used to print all the the hexadecimal color values. This is achieved by declaring/initializing a counter, setting the condition, `counter < hexValues.size()`, and incrementing the counter. A `do while` loop asks the user to enter the file to be opened while `!reader.is_open()`. 

### File Input and Output

To access the `fstream` library, I included `#include <fstream>` in my program. Because I only want to read from the file, I use `ifstream`. To read from the file, I use `getline(reader, line)` together with a `while` loop. This block of code loops until reader reaches the end of the file.

### Arrays/Vectors

In order to access the `vector` library, I included `#include <vector>` in my program. The program uses a vector of strings instead of an array because of a vector's dynamic size. The vector `hexValues` stores all of the unique hexadecimal color values from the file the user inputs. We do not know how many unique hexadecimal color values there will be in the file; therefore, an array is not ideal. v.02 makes use of `.push_back()` to insert a unique hexadecimal color value at the end of the vector increasing the size of the vector by one. I also use `.size()` to know how many hexadecimal color values there are in `hexValues` and to set the condition for the `for` loop that iterates through `hexValues`.

### Functions

The member function, `uniqueHex`, returns a `string` and its argument is `hexValues`. `uniqueHex` takes in a `vector<string>`. The `vector<string>` is passed by `const` reference because the `vector<string>` could potentially be very large but I used `const` because I do not want to permanently change the `vector<string>`. `uniqueHex` compares the member variable `hexColor` to all of the strings in the vector. If the string is equal to any string in the vector, `uniqueHex` returns a blank string, but if it is unique, `uniqueHex` returns `hexColor`. The function is called within an `if` statement, if `uniqueHex` is not a blank string, then the string is inserted at the end of `hexValues` using `.push_back()`. 

The function `distinguishColors` has a return type of `void` because it does not return anything; it just displays to the console. `vector<string>` is passed by reference because the `vector<string>` could potentially be very large and because I changed the 3-digit hexadecimal color values to their 6-digit equivalent forms so I could be working with a sole string size. `distinguishColors` separates the hexadecimal color strings into their red, green, and blue parts. Then it converts those substrings to hexadecimal integers. It then identifies which colors would be difficult to distinguish from one another and displays them to the console. The argument of the function is `hexValues`.

### Classes

The class `color` has member functions which identify if a string is a hexadecimal color value and whether a hexadecimal color value is unique. Both member functions are public while the member variables are private so that they can only be accessed/changed through the member functions `uniqueHex` and `isHexColor`. This decision was based on the principle of Information Hiding. `color` is reuseable as it is abstract(generic), everything that is a member of  the class is something that belongs to `color`(Encapsulation), member variables are private so that they are used properly(Information Hiding), and `color` has its own `.h` and `.cpp` files so that if one wishes to reuse `color`, one can just copy and paste the files.
