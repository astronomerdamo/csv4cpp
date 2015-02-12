#C++ CSV Data File Parser

##Requirements

* C++ compiler, ie: gcc/g++

##Introduction

I wrote this function after becoming frustrated with the level of difficulty required to read in a tabled data file for use in C++ command line programs. This csv parser uses only standard (STL) C++ libraries

##Installation

`
$ git clone https://github.com/astronomerdamo/csv4cpp.git
`

##Usage

Feel free to copy only the csv parser function, or compile and test at will. If you choose to copy only the parser make note of the included libraries.

To compile,

`
$ g++ readcsv.cpp -o readcsv
`

To run using the provided data file example,

`
$ ./readcsv data.csv
`

with output,

    0.2    1.2    0.4
    0.4    1.3    0.3
    0.6    1.8    0.4
    0.8    2.4    0.2


Or more generically,

`
$ ./readcsv path_to/data.csv
`

__Note:__
* CSV parser is not built to support comments in data file (it's on my ToDo).
* The data file must have a constant number of columns.
* Every value in the data file should have a numeric value.
* The column delimiter must a single consistent character, a single space between values is ok.
