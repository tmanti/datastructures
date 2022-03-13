Name: Thomas Ingram
ID: 200188260
Email: ingr8826@mylaurier.ca
WorkID: CP264-a8
Statement: I claim that the enclosed submission is my individual work.

Fill in the self-evaluation in the following evaluation grid.
Symbols:  A - Assignment, Q - Question, T - Task
Field format: [self-evaluation/total marks/marker's evaluation]

For example, you put your self-evaluation, say 2, like [2/2/*]. 
If markers give different evaluation value, say 1, it will show 
[2/2/1] in the marking report. 

Evaluation grid: [self-evaluation/total/marker-evaluation]

A8

Q1 AVL tree
Q1.1 balance_factor(),is_avl()            [4/4/*]
Q1.2 rotate_left()                        [3/3/*]
Q1.3 rotate_right()                       [3/3/*]
Q1.4 insert()                             [5/5/*]
Q1.5 delete()                             [5/5/*]

Q2 AVL tree for record data processing
Q2.1 merge_tree()                         [5/5/*]
Q2.2 merge_data()                         [5/5/*]

Total:                                    [30/30/*]

Copy and paste the console output of your public test in the following. This will help markers to evaluate your program if it fails the marking testing.  

Q1 output:
AVL insertions:       
insert(&root, A, 1.0):
insert(&root, B, 2.0):
insert(&root, C, 3.0):
insert(&root, D, 4.0):
insert(&root, E, 5.0):
insert(&root, F, 6.0):
insert(&root, G, 7.0):
|___:D,4.0,3
    |___R:F,6.0,2     
        |___R:G,7.0,1 
        |___L:E,5.0,1 
    |___L:B,2.0,2     
        |___R:C,3.0,1 
        |___L:A,1.0,1 
is_val(&root):1       
inorder:A B C D E F G
AVL deletions:
delete(&root, A):
delete(&root, C):
delete(&root, E):
delete(&root, G):
|___:D,4.0,2
    |___R:F,6.0,1
    |___L:B,2.0,1
is_val(&root):1
inorder:B D F

Q2 output:
Inport data from marks1.txt:
Bodnar,93.6
Chabot,80.4
Costa,45.1
Dabu,74.4
Giblett,59.1
Hatch,66.5
Myrie,76.7
Smith,60.1
Suglio,85.7
Sun,67.7
count:10
mean:70.9
stddev:13.5
median:71.1

Inport data from marks2.txt:
Ali,88.0
Allison,67.7
Eccles,77.8
He,85.7
Koreck,77.4
Lamont,98.1
Parr,92.5
Pereira,80.3
Peters,82.3
Wang,98.1
count:10
mean:84.8
stddev:9.2
median:84.0

Merge:
Ali,88.0
Allison,67.7
Bodnar,93.6
Chabot,80.4
Costa,45.1
Dabu,74.4
Eccles,77.8
Giblett,59.1
Hatch,66.5
He,85.7
Koreck,77.4
Lamont,98.1
Myrie,76.7
Parr,92.5
Pereira,80.3
Peters,82.3
Smith,60.1
Suglio,85.7
Sun,67.7
Wang,98.1
count:20
mean:77.9
stddev:13.5
median:79.1

Report data:
count:20
mean:77.9
stddev:13.5
median:79.1
