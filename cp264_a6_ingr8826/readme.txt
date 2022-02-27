Name: Thomas Ingram
ID: 200188260
Email: ingr8826@mylaurier.ca
WorkID: CP264-a6
Statement: I claim that the enclosed submission is my individual work.

Fill in the self-evaluation in the following evaluation grid.
Symbols:  A - Assignment, Q - Question, T - Task
Field format: [self-evaluation/total marks/marker's evaluation]

For example, you put your self-evaluation, say 2, like [2/2/*]. 
If markers give different evaluation value, say 1, it will show 
[2/2/1] in the marking report. 

Evaluation grid: [self-evaluation/total/marker-evaluation]

A6

Q1 Queue data structure
Q1.1 enqueue()                            [3/3/*]
Q1.2 dequeue()                            [3/3/*]
Q1.3 clean_queue()                        [2/2/*]

Q2 Stack data structure
Q2.1 push()                               [3/3/*]
Q2.2 pop()                                [3/3/*]
Q2.3 clean_stack()                        [2/2/*]

Q3 Postfix and infix expression evaluation
Q3.1 infix_to_postfix()                   [6/6/*]
Q3.2 evaluate_postfix()                   [5/5/*]
Q3.3 evaluate_prefix()                    [3/3/*]

Total:                                    [30/30/*]

Copy and paste the console output of your public test in the following. This will help markers to evaluate your program if it fails the marking testing.  

Q1 output:
enqueue:10-((3*4)+8)/4
display queue:10 - ( ( 3 * 4 ) + 8 ) / 4
queue length:13
dequeue:10 - ( ( 3 * 4 ) + 8 ) / 4
queue-length:0

Q2 output:
str:12 34 56 78 90 + - * /
display stack:/ * + 90 78 56 34 12
stack height:8
pop:/ * + 90 78 56 34 12
stack-height:0

Q3 output:
tmanti@DESKTOP-6IFLUCP:/mnt/d/dev/school/cp264/cp264_a6_ingr8826$ ./q3
infix expression:10-((3*4)+8)/4
postfix expression:10 3 4 * 8 + 4 / -
postfix evaluation:5
infix evaluation:5
tmanti@DESKTOP-6IFLUCP:/mnt/d/dev/school/cp264/cp264_a6_ingr8826$ ./q3 "12 + 24*3"
infix expression:12 + 24*3
postfix expression:12 24 3 * +
postfix evaluation:84
infix evaluation:84