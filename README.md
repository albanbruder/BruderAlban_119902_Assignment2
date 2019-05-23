# Assignment 2
## How to Compile
```
./build.sh
```
This will create the build folder and start  the cmake build process.
You will find the executables in the *./build/source* folder.
## How to Use
```sh
cd ./build/source/

# run tests (this is the main function with different inputs)
./tests

# run commandline utility (help)
$ ./example -h
Usage: ./example [-h] [-q] [NUMBER NUMBER ...]

# run commandline utility with arguments
$ ./example -2.3 1.4 3 5.0 11 12.4 -20.5
-20.5 -2.3 1.4 3 5 11 12.4

# run commandline utility with userinput
$ ./example
Please the numbers you want to sort separated with spaces:
3.3 2.2 1.1 # <-- input here
1.1 2.2 3.3

# pipe numbers into commandline utility (use quiet flag)
$ echo "6 5 4" | ./example -q
3 5 6
```