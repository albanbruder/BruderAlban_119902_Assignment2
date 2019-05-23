# Assignment 2
## How to Compile
```
./build.sh
```
This will create the build folder and start  the cmake build process.
You will find the executables in the *./build/source* folder.
## How to Use
```sh
# run tests (this is the main function with different inputs)
./build/source/tests

# run commandline utility with arguments
$ ./build/source/example -2.3 1.4 3 5.0 11 12.4 -20.5
-20.5 -2.3 1.4 3 5 11 12.4

# run commandline utility with userinput
$ ./build/source/example
3.3 2.2 1.1 # <-- input here
1.1 2.2 3.3

# pipe numbers into commandline utility
$ echo "6 5 4" | ./build/source/example
3 5 6
```