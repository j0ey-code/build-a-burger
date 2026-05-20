"j0ey-code
C Programming [Fundamentals]
Build-a-Burger Project
November 2023

Build-a-Burger Project README.txt
---------------------------------
Statement of Completion

This project was definitely a step up from the last one (Galaxy Operations Console) and I feel like it put my knowledge of C more to the test. 
The function calls, variable definitions, returns, syntax, semantics, etc. is clearly reaching another level, one that I am more familiar with in terms of OOP (Java / Python). Pure procedural programming, a la C, is new to me.
After initially writing methods to generate the random order and for the user to input their burger in main(), I began writing the easiest of the functions first [ClearScreen(), RandomDecider(), PrintBurger(), RoundUp()].
After, I moved onto the CalculateTotals() function, which I struggled with for a bit before realizing a switch statement would be the best way to implement it. The conditions for special burgers found right after the switch statement, but before the final cost / points adjustment for correctness (flat rate two dollars or round up), were saved for last.
Afterwards, the real tricky part for me seemed to be organizing the functions properly. Though the burger generator and build burger methods I wrote worked in main(), I had to move them outside of it to structure the program correctly and more "C-like". That took me a while, to sort out all the returns and get all the functions insofar calling and returning to the right place.
Once that was done though, I still had no CompareBurger() function to use for checking correctness. A simple for loop and array comparison took care of that, and the function returns a binary / boolean value to call for in PlayRound() and then feed to CalculateTotals().
I hope the project / memory game is what you were looking for Professor. Really got frustrated at times, but happy that it turned out not too shabby.

- j0ey-code"

My original "Statement of Completion" for this assignment, almost 3 years ago now. 
The second ever actual academic programming project I ever completed during my first semester at community college, in a class about the fundamentals / elementary aspects of programming, taught using C.

GNU/Linux g++ command to compile into an executable...
=========================================
g++ buildaburger.c -o [filename_whatever]
=========================================
Then, run it from the PWD as simply...
=========================================
./filename_whatever

Or, use whatever C/C++ compiler you are already comfortable with (gcc, clang, etc.) ~ !!
Really just a simple memory game that runs through the console / terminal. Nothing terribly impressive in retrospect. 

