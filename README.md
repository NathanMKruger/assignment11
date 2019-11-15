# CSI281 Assignment 11

For this assignment, you will be implementing a binary search tree. The tests will ensure that your binary search tree works correctly and its contains() outperforms the standard library's linear search function std::find(). You will also see an SVG chart generated with this comparison.

You may look at pseudo code such as that provided in the reading or on Wikipedia, but please do yourself a favor and implement these functions yourself without copying someone else's C++. As always, cite your sources.

NOTE: For this assignment you are not allowed to add additional functions to the source files (even utility functions). Please just fill-in the provided function templates.

## Basic Instructions

1. Download the contents of this repository.
2. Create your own private repository and add the contents of this repository to it.
3. Add me (@davecom) as a collaborator on your private repository.
4. Implement the missing parts where it says "YOUR CODE HERE"
5. Test it by following the build directions below.
6. Submit the URL to your private repository on Canvas.

## Standard Library Restrictions

All of the standard library is available to you.

## Directory Structure and Files

- `/` Main directory including this `README.md`, the build scripts, and will have the generated SVG search chart.
- `/lib` Libraries for drawing the charts and testing your work. There's no need to touch this.
- `/src` Source files, some of which you should modify and some of which you should not.

### Specific Files

*indicates do not modify
&indicates you must modify

- `GNUMakefile`* make file for GNU Make on macOS and GNU/Linux
- `Makefile`* make file for nmake/Visual Studio on Windows
- `README.md`* this file
- `LICENSE` MIT License

- `lib/catch.h`* a unit testing library
- `lib/PPlot.cpp`* part of a chart making library
- `lib/PPlot.h`* part of a chart making library
- `lib/SVGPainter.cpp`* part of a chart making library
- `lib/SVGPainter.h`* part of a chart making library

- `src/bst.h`& the BST class you need to finish implementing
- `src/timing.h`* a function to help compare bst.contains() with std::find()
- `src/main.cpp` the main file that runs the tests and makes the charts
- `src/test.cpp`* the unit tests to prove your code works

## Building and Running

### macOS and GNU/Linux

`cd` to the appropriate directory and run `make` and `./assignment11` to run all of the tests. It will also output a  `.svg` file when you are done that shows nicely plotted data. Run `make clean` to remove all objects files, the executable, and the svg files.

### Windows

From the start menu (assuming you have installed Visual Studio 2019) open the "Developer Command Prompt." `cd` to the appropriate directory and run `nmake` and `assignment11` to run all of the tests. It will also output a  `.svg` file when you are done that shows nicely plotted data. Run `nmake clean` to remove all objects files, the executable, and the svg files.

## Checklist for Submission

- [ ] Did you add me (@davecom) as a collaborator on the repository?
- [ ] Did you replace every area that said "YOUR CODE HERE" with your code?
- [ ] Did you ensure you are passing all of the unit tests?
- [ ] Did you cite all sources, especially any place that you copied code from? Put code citations right next to where you inserted it.
- [ ] Did you add sufficient comments?
- [ ] Did you double check your code for good style?
- [ ] Did you remember to free any memory you manually allocated on the heap?
- [ ] Did you put your name below mine at the top of any files you modified and any other appropriate places?
- [ ] Were you sure to not add additional functions to `bst.h`?
- [ ] Did you try cleaning, building, and running once to make sure everything is in working order before submitting?
- [ ] If you were working with an IDE, did you test building on the command line with make or nmake? I will only test your work with make or nmake.
- [ ] Did you check the repository is free of your object files and other garbage and just contains source files?
- [ ] Did you submit the URL to your repository on Canvas?
