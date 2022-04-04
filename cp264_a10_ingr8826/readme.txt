Name: Thomas Ingram (sign by typing your name)
ID: 200188260
Email: ingr8826@mylaurier.ca
WorkID: CP264-a10
Statement: I claim that the enclosed submission is my individual work.

Fill in the self-evaluation in the following evaluation grid.
Symbols:  A - Assignment, Q - Question, T - Task
Field format: [self-evaluation/total marks/marker's evaluation]

For example, you put your self-evaluation, say 2, like [2/2/*]. 
If markers give different evaluation value, say 1, it will show 
[2/2/1] in the marking report. 

Evaluation grid: [self-evaluation/total/marker-evaluation]

A10

Q1 Edge list graph data structure
Q1.1 new_edgelist()                       [3/3/*]
Q1.2 add_edge_start(), add_edge_end()     [3/3/*]
Q1.3 weight_edgelist()                    [3/3/*]

Q2 Adjacency list graph data structure
Q2.1 new_graph()                          [3/3/*]
Q2.2 add_edge()                           [3/3/*]
Q2.3 bf_traverse()                        [3/3/*]
Q2.4 df_traverse()                        [3/3/*]

Q3 Graph algorithms
Q3.1 mst_prim()                           [3/3/*]
Q3.2 spt_dijkstra()                       [3/3/*]
Q3.3 sp_dijkstra()                        [3/3/*]

Total:                                    [30/30/*]

Copy and paste the console output of your public test in the following. This will help markers to evaluate your program if it fails the marking testing.  

Q1 output:
display_edgelist():
size:4
(from to weight):(0 2 3) (2 1 4) (1 3 9) (1 4 11)
weight:27

Q2 output:
display_graph():
order:5
size:12
from:(to weight)
0:(1 7) (2 3)
1:(0 7) (2 4) (3 9) (4 11)
2:(0 3) (1 4) (3 10)
3:(2 10) (1 9)
4:(1 11)
display_bforder():0 1 2 3 4
display_dforder():0 2 3 1 4

Q3 output:
display_graph(g):
order:5
size:12
from:(to weight)
0:(1 7) (2 3)
1:(0 7) (2 4) (3 9) (4 11)
2:(0 3) (1 4) (3 10)
3:(2 10) (1 9)
4:(1 11)

mst_prim(g, 0):
size:4
(from to weight):(0 2 3) (0 1 4) (2 3 9) (1 4 11)
mst weight:27

spt_dijkstra():size:4
(from to weight):(0 2 3) (0 1 7) (2 3 10) (1 4 11)
spt weight:31

sp_dijkstra(g 0 4):
size:2
(from to weight):(0 1 7) (1 4 11)
sp length:18
