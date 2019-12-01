# Seat Change

A simple utility of seat-changing - for DL24 where the number of female students is far less than that of male students.

# Get Started

Clone the repository and compile the source code with `g++` or `clang`:

```bash
git clone https://github.com/Robertspot/seat-change
cd seat-change
g++ main.cpp -o seat-change
```

# Usage

```plain
seat-change [options]
```

Options:

|option|usage|
|-|-|
|`-i, --input<file>`|Input from `<file>`. The program will input from `stdin` without this option.|
|`-o, --output<file>`|Output to `<file>`. The program will output to `stdout` without this option.|

# Input and output format

Data will be input and output in `.csv` format. 

## Input file

Input file has 1 colomns on the first row. In the cell is an integer: width of classroom.

Input file has 2 colomus on following rows:

1. sex - 0: female, 1: male(allowed to sit beside female students), 2: male(not allowed to sit beside female students)

2. name of student

Sample input:

```csv
4
0,ff1
0,ff2
0,ff3
1,ma1
1,ma2
1,ma3
1,ma4
1,ma5
2,mb1
2,mb2
```

## Output file

Output file is a readable csv file. It's suggested to open it with an office software like Microsoft Excel, LibreOffice Calc or WPS Office.

For more about input & output file, see [test input](./test/in.csv) and [test output](./test/out.csv).

## Copyright

Copyright (c) Robertspot.

## Open source projects

- clibs/commander:

    (The MIT License)

    Copyright (c) 2012 TJ Holowaychuk <tj@vision-media.ca>

    Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the 'Software'), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

