---
title: "The shortest path problem : Dijkstra's algorithm"
author: Julien Roland
date: 2016
---

## Dijkstra's algorithm
This algorithm solves the single-source shortest-path problem on a weighted graph $G = (V,A)$, where $w(u,v) \geqslant 0$ for each arc $\{u,v\} \in A$

* $S$ : a set of vertices for which the shortest-path *has been determined*
* $Q$ : a set of vertices for which the shortest-path *has to be determined*

\centerline{\includegraphics[scale=0.5]{image/shortest_path/chem2.pdf}}

## Dijkstra's algorithm
\begin{columns}[T] % align columns
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.5]{image/shortest_path/chem2.pdf}}
\end{column}%
\hfill%
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.5]{{image/shortest_path/chem2.0}.pdf}}
\end{column}%
\end{columns}

* $S = \{\}$
* $Q$ contains all vertices in $V(G) = \{1, 2, 3, 4, 5\}$

--------------------------------------------------------------
                 1        2        3         4        5
--------------   -------- -------- --------  -------- --------
Distance         0        $\infty$ $\infty$  $\infty$ $\infty$

Predecessor      1        null     null      null     null
--------------------------------------------------------------

## Dijkstra's algorithm
\begin{columns}[T] % align columns
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.5]{{image/shortest_path/chem2.1}.pdf}}
\end{column}%
\hfill%
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.5]{{image/shortest_path/chem2.2}.pdf}}
\end{column}%
\end{columns}

* $S = \{1\}$
* $Q$ contains $\{2, 3, 4, 5\}$

----------------------------------------------------------
                 1       2       3       4        5
--------------   ------- ------- ------- -------- --------
Distance         0       2       1       $\infty$ $\infty$

Predecessor      1       1       1       null     null
----------------------------------------------------------

## Dijkstra's algorithm
\begin{columns}[T] % align columns
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.5]{{image/shortest_path/chem2.3}.pdf}}
\end{column}%
\hfill%
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.5]{{image/shortest_path/chem2.4}.pdf}}
\end{column}%
\end{columns}

* $S = \{1, 3\}$
* $Q$ contains $\{2, 4, 5\}$

---------------------------------------------------------
                 1       2       3       4        5
--------------   ------- ------- ------- -------- -------
Distance         0       2       1       $\infty$ 8

Predecessor      1       1       1       null     3
---------------------------------------------------------

## Dijkstra's algorithm
\begin{columns}[T] % align columns
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.5]{{image/shortest_path/chem2.5}.pdf}}
\end{column}%
\hfill%
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.5]{{image/shortest_path/chem2.6}.pdf}}
\end{column}%
\end{columns}

* $S = \{1, 3, 2\}$
* $Q$ contains $\{4, 5\}$

--------------------------------------------------------
                 1       2       3       4       5
--------------   ------- ------- ------- ------- -------
Distance         0       2       1       4       8

Predecessor      1       1       1       2       3
--------------------------------------------------------

## Dijkstra's algorithm
\begin{columns}[T] % align columns
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.5]{{image/shortest_path/chem2.7}.pdf}}
\end{column}%
\hfill%
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.5]{{image/shortest_path/chem2.8}.pdf}}
\end{column}%
\end{columns}

* $S = \{1, 3, 2, 4\}$
* $Q$ contains $\{5\}$

--------------------------------------------------------
                 1       2       3       4       5
--------------   ------- ------- ------- ------- -------
Distance         0       2       1       4       6

Predecessor      1       1       1       2       4
--------------------------------------------------------

## Dijkstra's algorithm

\centerline{\includegraphics[scale=0.5]{{image/shortest_path/chem2.9}.pdf}}

* $S = \{1, 3, 2, 4, 5\}$
* $Q$ is empty

--------------------------------------------------------
                 1       2       3       4       5
--------------   ------- ------- ------- ------- -------
Distance         0       2       1       4       6

Predecessor      1       1       1       2       4
--------------------------------------------------------


## Dijkstra's algorithm : pseudo-code
**Initialization**

```
S = empty set;
Q contains V(G);

for (i = 1; i <= n; ++i)
{
	dist[i] = infinity;
	prec[i] = null;
}

dist[1] = 0;
prec[1] = 1;

```
## Dijkstra's algorithm : pseudo-code

```
while (Q is not empty)
{
    extract a vertex u from Q with the minimum dist[u];
	add u to S;

	for each vertex v in adj[u]
    {
		d = dist[u] + w(u,v);
		if(d < dist[v])
		{
			dist[v] = d;
			prec[v] = u;
		}
	}
}
```

## Exercises

1. Apply the Dijkstra's algorithm on the following graph to find the shortest path between vertices 1 and 7.

\centerline{\includegraphics[scale=0.5]{{image/shortest_path/exo1}.pdf}}

## Exercises

2. Give an example of a weighted graph for which the Dijkstra's algorithms does not find the shortest path.
3. What is the complexity of Dijkstra's algorithm with the use of a linked list to store the set $Q$ ?
4. What is the complexity of Dijkstra's algorithm with the use of a binary heap to store the set $Q$ ?
5. How to update the priority of an element in a binary heap with a worst-case complexity in $O(\log n)$ ?
6. How would you implement this algorithm, with the use of a binary heap, but without updating the
   priority ?

<!--
3. Write a function `dijkstra` that computes the shortest path from the node `startID` to the node `goalID` in a directed graph. The function returns a $2 \times k$ matrix such that :
    * $k$ is the number of nodes included in the shortest path
	* each column describes a step in the path
	* the first line contains the node id
	* the second line contains the cumulative cost

## The binary heap

A *binary heap* is a complete *binary-tree* :

* Every level, except possibly the last, is completely filled
* The last level is filled from left to right

\centerline{\includegraphics[scale=0.5]{{image/shortest_path/bin_tree}.pdf}}

## The binary heap

A *binary heap* is a complete *binary-tree* which satisfies the following property:

\centerline{\includegraphics[scale=0.5]{{image/shortest_path/heap_property}.pdf}}

* $x \leqslant y$
* $x \leqslant z$

## The binary heap

Example:

\centerline{\includegraphics[scale=0.5]{{image/shortest_path/binary_heap}.pdf}}

## The binary heap

Insertion:

\centerline{\includegraphics[scale=0.5]{{image/shortest_path/binary_heap_insert}.pdf}}

## The binary heap

Insertion:

\centerline{\includegraphics[scale=0.5]{{image/shortest_path/binary_heap_insert2}.pdf}}

## The binary heap

Insertion:

\centerline{\includegraphics[scale=0.5]{{image/shortest_path/binary_heap_insert3}.pdf}}

## The binary heap

Remove the minimum:

\centerline{\includegraphics[scale=0.5]{{image/shortest_path/binary_heap_remove}.pdf}}

## The binary heap

Remove the minimum:

\centerline{\includegraphics[scale=0.5]{{image/shortest_path/binary_heap_remove1}.pdf}}

## The binary heap

Remove the minimum:

\centerline{\includegraphics[scale=0.5]{{image/shortest_path/binary_heap_remove2}.pdf}}

## The binary heap

Remove the minimum:

\centerline{\includegraphics[scale=0.5]{{image/shortest_path/binary_heap_remove3}.pdf}}


## The binary heap : Array implementation

\centerline{\includegraphics[scale=0.5]{{image/shortest_path/binary_heap}.pdf}}
\centerline{\includegraphics[scale=0.5]{{image/shortest_path/binary_heap_array}.pdf}}

## Exercises

1. Draw the binary heap that results from inserting 10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7 in that order into an initially empty binary heap
1. Draw the binary heap after three `deleteMin` on the binary heap you obtained in the previous exercise
1. Implement the abstract data type `Heap` based on `heap.h`
1. Modify the function `dijkstra` in order to use this abstract data type

-->
