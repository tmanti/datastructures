Name: Thomas Ingram (sign by typing your name)
ID: 200188260
Email: ingr8826@mylaurier.ca
WorkID: CP264-a9
Statement: I claim that the enclosed submission is my individual work.

Fill in the self-evaluation in the following evaluation grid.
Symbols:  A - Assignment, Q - Question, T - Task
Field format: [self-evaluation/total marks/marker's evaluation]

For example, you put your self-evaluation, say 2, like [2/2/*]. 
If markers give different evaluation value, say 1, it will show 
[2/2/1] in the marking report. 

Evaluation grid: [self-evaluation/total/marker-evaluation]

A9

Q1 Chained hash table
Q1.1 new_node(), new_hashtable()          [3/3/*]
Q1.2 search()                             [3/3/*]
Q1.3 insert()                             [3/3/*]
Q1.4 delete()                             [3/3/*]

Q2 Symbolic expression evaluation
Q2.1 infix_to_postfix_symbol()            [6/6/*]

Q3 Binary heap
Q3.1 new_heap(),find_index_data()         [3/3/*]
Q3.2 insert()                             [3/3/*]
Q3.3 extract_min()                        [3/3/*]
Q3.4 change_key()                         [3/3/*]

Total:                                    [30/30/*]

Copy and paste the console output of your public test in the following. This will help markers to evaluate your program if it fails the marking testing.  

Q1 output:
hash table after insertions:
size:5
count:20
0:(d,3) (i,8) (n,13) (s,18)
1:(e,4) (j,9) (o,14) (t,19)
2:(a,0) (f,5) (k,10) (p,15)
3:(b,1) (g,6) (l,11) (q,16)
4:(c,2) (h,7) (m,12) (r,17)
search(a):(a,0)
hash table after deletions:
size:5
count:10
0:(n,13) (s,18)
1:(o,14) (t,19)
2:(k,10) (p,15)
3:(l,11) (q,16)
4:(m,12) (r,17)
search(b):NULL

Q2 output:
Symbolic expressions:
a=10
b=8
d=2
c=(a+b)*(a-b)
b=d*c

Symbolic expression evaluation:
d:2
a:10
b:72
c:36

Q3 output:
new heap:
size:0
capacity:4
(index,key,data):

heap after insertions:
size:10
capacity:16
(index,key,data):(0,4,10) (1,5,9) (2,8,6) (3,7,7) (4,6,8) (5,12,2) (6,9,5) (7,13,1) (8,10,4) (9,11,3)

(find_data_index(hp,6),key,data):(2,8,6)
change_key(hp,2,2):0
change_key(hp,2,2):(2,8,6)->(0,2,6)
size:10
capacity:16
(index,key,data):(0,2,6) (1,5,9) (2,4,10) (3,7,7) (4,6,8) (5,12,2) (6,9,5) (7,13,1) (8,10,4) (9,11,3)

(find_data_index(hp,6),key,data):(0,2,6)
change_key(hp,0,8):2
change_key(hp,0,8):(0,2,6)->(2,8,6)
size:10
capacity:16
(index,key,data):(0,4,10) (1,5,9) (2,8,6) (3,7,7) (4,6,8) (5,12,2) (6,9,5) (7,13,1) (8,10,4) (9,11,3)

call extract_min 8 times:(4 10) (5 9) (6 8) (7 7) (8 6) (9 5) (10 4) (11 3)
heap after extract_min operations:
size:2
capacity:4
(index,key,data):(0,12,2) (1,13,1)
