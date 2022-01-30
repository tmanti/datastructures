Name: ???
ID: ???
Email: ???
WorkID: cp264-a2
Statement: I claim that the enclosed submission is my individual work.

Fill in the self-evaluation in the following evaluation grid.
Symbols: A - Assignment, T - Task, Q - question 
Field format: [self-evaluation/total marks/marker's evaluation]

For example, you put your self-evaluation, say 2, like [2/2/*]. 
If marker gives different evaluation value say 1, it will show 
[2/2/1] in the marking report. 

Evaluation grid: [self-evaluation/total/marker-evaluation]

A2

Q1 Computing Fibonacci numbers
Q1.1 recursive_fibonacci()                [3/3/*]
Q1.2 iterative_fibonacci()                [5/5/*]

Q2 Array & polynomial
Q2.1 display_polynomial()                 [2/2/*]
Q2.2 horner()                             [5/5/*]
Q2.3 bisection()                          [5/5/*]

Q3 Vector, Matrix
Q3.1 vsum(), msum()                       [2/2/*]
Q3.2 transpose_matrix()                   [2/2/*]
Q3.3 multiply_matrix()                    [3/3/*]
Q3.4 multiply_vector()                    [3/3/*]

Total:                                    [30/30/*]

Copy and paste the console output of your public test in the following. This will help markers to evaluate your program if it fails the marking testing.  

Q1 output:
**Iterative algorithm measurement**
iterative_fibonacci(40):102334155
high address:140731726189024
low address:140731726188988
iterative_fibonacci(40) memory span:36
time_span(iterative_fibonacci(40) for 500000 times):46994.0 (ms)

**Recursive algorithm measurement**
recursive_fibonacci(40):102334155
high address:140731726189024
low address:140731726187164
recursive_fibonacci(40) memory span:1860
time_span(recursive_fibonacci(40) for 10 times) in (ms):5667673.0

**Comparison of recursive and iterative algorithms**
memory_span(recursive_fibonacci(40))/memory_span(iterative_fibonacci(40)):51.7
time_span(recursive_fibonacci(40))/time_span(iterative_fibonacci(40)):6030209.2

Q2 output:
P(0.00)=1.00*0.00^3+2.00*0.00^2+3.00*0.00^1+4.00*0.00^0=4.00
P(1.00)=1.00*1.00^3+2.00*1.00^2+3.00*1.00^1+4.00*1.00^0=10.00
P(10.00)=1.00*10.00^3+2.00*10.00^2+3.00*10.00^1+4.00*10.00^0=1234.00
P(-2.00)=-2.00
P(2.00)=26.00
root=-1.65
P(-1.65)=0.00

Q3 output:
m1:
   8   1   6
   3   5   7
   4   9   2
msum(m1):45

m2=m1':
   8   3   4
   1   5   9
   6   7   2
msum(m2):45

m3=m1*m2':
 101  71  53
  71  83  71
  53  71 101
msum(m3):675

v1:
1   1   1
vsum(v1):3

v2=m1*v1':
15  15  15
vsum(v2):45
