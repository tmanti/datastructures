Name: Thomas Ingram
ID: 200188260
Email: ingr8826@mylaurier.ca
WorkID: CP264-a7
Statement: I claim that the enclosed submission is my individual work.

Fill in the self-evaluation in the following evaluation grid.
Symbols:  A - Assignment, Q - Question, T - Task
Field format: [self-evaluation/total marks/marker's evaluation]

For example, you put your self-evaluation, say 2, like [2/2/*]. 
If markers give different evaluation value, say 1, it will show 
[2/2/1] in the marking report. 

Evaluation grid: [self-evaluation/total/marker-evaluation]

A7

Q1 Basic binary tree and operations
Q1.1 get_props()                          [3/3/*]
Q1.2 display_preorder/inorder/postorder   [3/3/*]
Q1.3 display_bforder                      [3/3/*]
Q1.4 iterative_bfs()                      [3/3/*]
Q1.5 iterative_dfs()                      [3/3/*]

Q2 BST to store record data
Q2.1 search()                             [3/3/*]
Q2.2 insert()                             [3/3/*]
Q2.3 delete()                             [3/3/*]

Q3 BST for record data processing
Q3.1 add_data()                           [3/3/*]
Q3.2 remove_data()                        [3/3/*]

Total:                                    [30/30/*]

Q1 output:
display_tree():
|___:A
    |___R:C
        |___R:G
        |___L:F
    |___L:B
        |___R:E
        |___L:D
get_props().order:7
get_props().height:3
display_preorder():A B D E C F G
display_postorder():D E B F G C A
display_inorder():D B E A F C G
display_bforder(root):A B C D E F G
iterative_bfs(F):F
iterative_bfs(H):NULL
iterative_dfs(F):F
iterative_dfs(H):NULL
clean get_props().order:0
get_props().height:0

Q2 output:

D,1.0
    |___R:F,3.0
        |___R:G,7.0
        |___L:E,6.0
    |___L:B,2.0
        |___R:C,5.0
        |___L:A,4.0

inorder:A B C D E F G
search(A):A,4.0

search(H):NULL
D,1.0
    |___R:F,3.0
        |___R:G,7.0
            |___R:H,8.0
        |___L:E,6.0
    |___L:B,2.0
        |___R:C,5.0
        |___L:A,4.0

inorder:A B C D E F G H
search(H):H,8.0
D,1.0
    |___R:G,7.0
        |___R:H,8.0
        |___L:E,6.0
    |___L:B,2.0
        |___R:C,5.0
        |___L:A,4.0

inorder:A B C D E G H

Q3 output:
---test data import---
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

---test record search---
search(Smith):Smith 60

---test adding data---
search(Moore):Moore 92

---test remove data---
search(Wang):NULL

---test report data---
count:20
mean:77.6
stddev:13.1
median:79.1