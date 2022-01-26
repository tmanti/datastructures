Name: Thomas Ingram
ID: 200188260
Email: ingr8826@mylaurier.ca
WorkID: cp264-a1
Statement: I claim that the enclosed submission is my individual work.

Fill in the self-evaluation in the following evaluation grid.
Symbols: A - Assignment, Q - Question 
Field format: [self-evaluation/total marks/marker's evaluation]

For example, you put your self-evaluation, say 2, like [2/2/*]. 
If marker gives different evaluation value say 1, it will show 
[2/2/1] in the marking report. 

Evaluation grid: [self-evaluation/total/marker-evaluation]

A1

Q1 Case flip
Q1.1 prompt for input                     [0/3/*]
Q1.2 input upper/lower case               [0/3/*]
Q1.3 input digit characters               [0/2/*]
Q1.4 others, quit                         [0/2/*]

Q2 Computing factorial
Q2.1 command line argument                [0/3/*]
Q2.2 correctness of computing             [0/3/*]
Q2.3 overflow testing                     [0/2/*]
Q2.4 output format                        [0/2/*]

Q3 Solving quadratic equation
Q3.1 correctness of computing             [0/6/*]
Q3.2 robust for invalid input             [0/2/*]
Q3.3 output format                        [0/2/*]

Total:                                   [0/30/*]

Copy and paste the console output of your public test in the following. This will help markers to evaluate your program if it fails the testing.  

Q1 output:

Please enter a character
a
a:97,A
Please enter a character
D
D:68,d
Please enter a character
2
2:50,4
Please enter a character
$
$:invalid
Please enter a character
*
*:quit

Q2 output:

gcc factorial.c -o factorial
./factorial 6
          1          2          6         24
        120        720
6!:720
./factorial 15
          1          2          6         24
        120        720       5040      40320
     362880    3628800   39916800  479001600
overflow:13!
./factorial a
a:invalid argument

Q3 output:

Please enter the coefficients a,b,c
The equation has two equal real roots
x:-1.000000
Please enter the coefficients a,b,c
The equation has two complex roots
real:-1.000000
imaginary:1.000000
Please enter the coefficients a,b,c
The equation has two distinct real roots
x1:-0.177124
x2:-2.822876
Please enter the coefficients a,b,c
input:Invalid input
Please enter the coefficients a,b,c
input:not a quadratic equation
Please enter the coefficients a,b,c
input:quit