---
title: "Graph implementation and traversal"
subtitle: "Algorithmique Avancée"
author: Julien Roland
toc-title: Table of contents
---

## Directed graph
A ***directed graph*** or ***digraph*** $G = (V, A)$ with $n$ ***vertices*** and $m$ ***arcs*** consists of:

* $V = V(G)$ : a vertex set; $n = |V|$ is the order of $G$
* $A = A(G)$ : a set of ordered pairs of vertices, called arcs; $m = |A|$

\centerline{\includegraphics[scale=0.6]{image/introduction/digraph.pdf}}

# Adjacency lists
## Adjacency lists

The *adjacency-list* representation of $G = (V,E)$ is an array `Adj` composed of $|V|$ lists.
For each node $u \in V(G)$, the adjacency list `Adj[u]` contains all the successors of $u$.

\centerline{\includegraphics[scale=0.5]{image/implementation/adj_list.pdf}}

# Adjacency matrix
## Adjacency matrix

For a digraph $G$ of order $n$, the **adjacency matrix** $M(G)$ is a $n \times n$ matrix which coefficients verify:

* $M_{ij} = 1$ if there exists an arc ${i,j} \in A(G)$;
* $M_{ij} = 0$ otherwise.

\begin{columns}[c] % align columns
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.35]{image/implementation/graph.pdf}}
\end{column}%
\hfill%
\begin{column}{.48\textwidth}
$M(G) = \begin{pmatrix}
1 & 1 & 0 & 0 & 0 & 0  \\
0 & 0 & 1 & 1 & 0 & 0  \\
1 & 0 & 0 & 0 & 0 & 0  \\
0 & 1 & 0 & 0 & 1 & 1  \\
0 & 1 & 1 & 1 & 0 & 1  \\
0 & 0 & 0 & 0 & 0 & 0  \\
\end{pmatrix} $
\end{column}%
\end{columns}

(If $G$ is undirected, $M_{ij} = M_{ji} = 1$ if $\{i,j\} \in E(G)$ and $M_{ij} = M_{ji} = 0$ otherwise.)

## Adjacency matrix

\begin{columns}[c] % align columns
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.35]{image/implementation/graph.pdf}}
\end{column}%
\hfill%
\begin{column}{.48\textwidth}
$M(G) = \begin{pmatrix}
1 & 1 & 0 & 0 & 0 & 0  \\
0 & 0 & 1 & 1 & 0 & 0  \\
1 & 0 & 0 & 0 & 0 & 0  \\
0 & 1 & 0 & 0 & 1 & 1  \\
0 & 1 & 1 & 1 & 0 & 1  \\
0 & 0 & 0 & 0 & 0 & 0  \\
\end{pmatrix} $
\end{column}%
\end{columns}

* Row $i$ : the arcs that leave from vertex $i$
* Column $j$ : the arcs that enter into vertex $j$

## Adjacency matrix vs Adjacency lists

A digraph with $n$ ***vertices*** and $m$ ***arcs*** :

* Space complexity :
	* matrix : $O(|V|^2) = O(n^2)$
	* list : $O(|V| + |A|) = O(n + m)$

\pause

* A graph is **sparse** when $m$ is much less than $n^2$. In this case the adjacency-list representation provides a compact way to represent a graph.

\pause

* A graph is **dense** when $m$ is close to $n^2$. In this case may prefer the adjacency-matrix representation, because these matrices are simpler and have useful mathematical properties.

## Adjacency matrix: mathematical results

* There is a path of **length 2** between $i, j \in V(G)$ if there exists a $k \in V(G)$ such that $M_{ik} \cdot M_{kj} = 1$.

\pause

* Therefore, there exists a path of length 2 between $i, j \in V(G)$ if and only if $\sum_{k \in V(G)} M_{ik} \cdot M_{kj} = M_{ij}^2\geqslant 1$.

\begin{columns}[c] % align columns
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/implementation/graph_path.pdf}}
\end{column}%
\hfill%
\begin{column}{.48\textwidth}
$M(G) = \begin{pmatrix}
0 & 1 & 0 & 1 & 1 \\
0 & 0 & 0 & 1 & 0 \\
0 & 0 & 0 & 0 & 1 \\
0 & 0 & 0 & 0 & 0 \\
0 & 1 & 0 & 0 & 0 \\
\end{pmatrix} $
\end{column}%
\end{columns}

\pause

* $M_{ij}^k$ is the number of paths of length $k$ starting at $i$ and ending at $j$.

# Depth-first Algorithm
## Depth-first
\centerline{\includegraphics[scale=0.5]{image/traversal/graph.pdf}}

* \[1, 2, 4, 5, 9, 6, 7, 8, 10, 3\]

## Depth-first Algorithm (first version)

```
function DFS(u)
	visit(u);
	visited[u] = true;
	for each v in Adj[u]
		if (!visited[v])
			DFS(v);

DFS(1);
```

1. mark the node $u$ as visited
2. visit (recursively) all the unvisited vertices on $u$'s adjacency list

## Depth-first
\centerline{\includegraphics[scale=0.5]{image/traversal/graph_bis.pdf}}

* \[1, 2, 5, 4, 3, 6\]


## Depth-first Algorithm (second version)

```
function DFS
	for each vertex u in V(G)
		visited[u] = false;

	for each vertex u in V(G)
		if (!visited[u])
			DFS-Visit(u);

function DFS-Visit(u)
	visit(u);
	visited[u] = true;
	for each v in Adj[u]
		if (!visited[v])
			DFS-Visit(v);
```

# Breadth-first Algorithm
## Breadth-first
\centerline{\includegraphics[scale=0.5]{image/traversal/graph.pdf}}

* \[1, 2, 3, 4, 7, 5, 6, 8, 10, 9\]

## Breadth-first Algorithm

```
function BFS(u)
	visited[u] = true;
	enqueue(u);
	while (the queue is not empty) {
		s = dequeue();
		visit(s);
		for each v in Adj[s] {
			if (!visited[v]) {
				visited[v] = true;
				enqueue(v);
			}
		}
	}
```

## Exercises

1. Give the adjacency list representation of the following graphs :
<!-- Cormen p.590 -->

\begin{columns}[T] % align columns
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/implementation/exo1.pdf}}
\end{column}%
\hfill%
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/implementation/exo2.pdf}}
\end{column}%
\end{columns}

## Exercises
2. Given an adjacency-list representation of a directed graph, devise an algorithm to compute the
   out-degree of every vertex, and a second algorithm to compute the in-degrees. What is the
   complexity of these two algorithms?
3. Given a directed graph $G$, devise an algorithm to determine if a given arc $(u, v)$, with $u, v
   \in V(G)$, belongs to this graph. Consider the adjacency matrix and the adjacency list
   representations. What is the complexity of these two algorithms ?
4. Given a directed graph $G$, devise an algorithm to list all vertices adjacent to a given
   vertex $u \in V(G)$. Consider the adjacency matrix and the adjacency list representations. What
   is the complexity of these two algorithms ?

## Exercises (cont'd)

5. Write a function that given a adjacency-list representation, returns the corresponding
   adjacency-matrix representation.
6. Apply the depth-first and breadth-first algorithms on the following graph (star from node $s$):
        \centerline{\includegraphics[scale=0.5]{image/traversal/exo1.pdf}}
7. Write an algorithm that determines if a given undirected graph is connected.
8. What is the complexity of depth-first and breadth-first algorithms ?

## Exercises (cont'd)
9. Based on the depth-first algorithm, write an algorithm that determines if a given directed graph
   contains a cycle. (Hint : use two different flags for each vertex)
        \centerline{\includegraphics[scale=0.5]{image/traversal/cycle.pdf}}

## Solutions to selected exercises

7. Write an algorithm that determines if a given undirected graph is connected.

```
function count_vertices(u, G)
        mark(u)
        count = 1
        for each v in G.Adj(u)
                if (!marked(v))
                        count += count_vertices(v, G)
        return count

function is_connected(G)
        v = G.first_vertex()
        return (count_vertices(v, G) == G.order())
```

## Solutions to selected exercises (cont'd)
9. Based on the depth-first algorithm, write an algorithm that determines if a given directed graph
   contains a cycle. (Hint : use two different flags for each vertex)

```
function has_cycle(G)
        cycle = false
        v = G.first_vertex()
        while (!cycle and v != NULL)
                cycle = exist(v)
                v = v.next_vertex()
        return cycle
```

## Solutions to selected exercises (cont'd)

```
function exist(v)
        cycle = false
        if (!marked_def(v))
                mark_def(v)
                mark(v)
                a = v.first_arc()
                while (a != NULL and !cycle)
                        if (!marked(a.end()))
                                cycle = exist(a.end())
                                a = a.next_arc()
                        else
                                cycle = true
                unmark(v)
        return cycle
```
