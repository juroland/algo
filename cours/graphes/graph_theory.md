---
title: "Graph Theory"
subtitle: "Algorithmique Avancée"
author: Julien Roland
---


## The Traveling Salesman Problem (TSP)

\centerline{\includegraphics[scale=0.3]{image/introduction/usa_tsp.png}}

\small

The complete example is available at: [https://developers.google.com/optimization/routing/tsp/tsp](https://developers.google.com/optimization/routing/tsp/tsp)

## The Traveling Salesman Problem (TSP)

\centerline{\includegraphics[scale=0.23]{image/introduction/usa_tsp.png}}
\centerline{\includegraphics[scale=0.28]{image/introduction/usa_tsp_graph.pdf}}

## Applications

* Itineraries (shortest path, traveling salesman problem,...)
* Scheduling
* Games (winning strategies)
* Assignment problems
* Time table
* Networking
* ...

## Graph
A graph $G = (V, E)$ with $n$ ***vertices*** and $m$ ***edges*** consists of:

* $V = V(G)$ : a vertex set; $n = |V|$ is the order of $G$
* $E = E(G)$ : a set of pairs of vertices, called edges; $m = |E|$

\centerline{\includegraphics[scale=0.6]{image/introduction/graph.pdf}}

* $V(G) = \{u, v, w, x\}$
* $E(G) = \{\{u,v\}, \{u,w\}\}$

## Graph (cont'd)
An edge ${u, v} \in E(G)$ (written $uv$ for short) links two vertices $u, v \in V(G)$:

* $u$ and $v$ are said ***adjacent*** (or neighbors)
* the neighborhood of $u$ is the set of all its neighbors (i.e., $N(u) = N_G(u) = \{v,w\}$)

\centerline{\includegraphics[scale=0.6]{image/introduction/graph.pdf}}

## Degree
* $E(u)$ : the set of all the edges in E at a vertex $u$
* $d_G(u) = d(u) = |E(u)|$ : the degree of a vertex $u$
* $\delta(G) := \min\{d(v) : v \in V\}$ : the minimum degree of $G$
* $\Delta(G) := \max\{d(v) : v \in V\}$ : the maximum degree of $G$

\centerline{\includegraphics[scale=0.6]{image/introduction/graph.pdf}}

## Bipartite graph

A graph $G = (V,E)$ is called **bipartite** if $V$ admits a partition into two classes such that every edge has its ends in different classes.

\centerline{\includegraphics[scale=0.4]{image/introduction/bipartite.pdf}}

## Complete bipartite graph

A bipartite graph in which every two vertices from different parition classes are adjacent is called **complete**. If there are $n_1$ and $n_2$ vertices in the two sets, the complete bipartite graph is denoted by $K_{n_1,n_2}$.

\centerline{\includegraphics[scale=0.4]{image/introduction/complete_bipartite.pdf}}

## Subgraph

* Let $G = (V, E)$ and $G' = (V', E')$ be two graphs. If $V' \subseteq V$ and $E' \subseteq E$, then $G'$ is a ***subgraph*** of $G$

\begin{columns}[T] % align columns
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/introduction/subgraph.pdf}}
\end{column}%
\hfill%
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/introduction/subgraph_bis.pdf}}
\end{column}%
\end{columns}

## Contraction

Let $e=\{x,y\}$ be an edge of a graph $G=(V,E)$. The **contraction** $G/e$ is a graph $(V', E')$, where $V' := (V\backslash\{x,y\})\cup\{v\}$ and $E'$ is the union between $\Big\{\{y,z\} \in E : \{y,z\} \cap \{x,y\} = \emptyset\Big\}$ and $\Big\{\{v,w\} : \{x,w\} \in E \backslash \{e\}\ \text{or}\ \{y,w\} \in E \backslash \{e\}\Big\}$.

\begin{columns}[T] % align columns
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/introduction/contraction.pdf}}
\end{column}%
\hfill%
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/introduction/contraction_bis.pdf}}
\end{column}%
\end{columns}

## Minor

If a graph $X$ is obtained from another graph $Y$ by repeated deletions (of edges and vertices) and contractions, then it is said that $X$ is a **minor** of Y.

\begin{columns}[T] % align columns
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/introduction/minor.pdf}}
\end{column}%
\hfill%
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/introduction/minor_bis.pdf}}
\end{column}%
\end{columns}

## Complete graph
A complete graph is a graph in which every pair of distinct vertices forms an edge.

\centerline{\includegraphics[scale=0.6]{image/introduction/complete.pdf}}

A complete graph with $n$ vertices is denoted $K_n$. What is the number of edges in a $K_n$?

## Crossing Number

The ***crossing number*** of a graph $G$, denoted $\nu(G)$, is the minimum number of crossings with which the graph can be drawn.

\centerline{\includegraphics[scale=0.5]{image/introduction/crossing_number.pdf}}

$\nu(K_4) =$ ?

## Crossing Number (cont'd)

$\nu(K_5) = 1$

\begin{columns}[T] % align columns
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/introduction/crossing_number_bis.pdf}}
\end{column}%
\hfill%
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/introduction/crossing_number_ter.pdf}}
\end{column}%
\end{columns}

## Planar graph

A graph $G$ for which $\nu(G) = 0$ is called a ***planar graph***.

\begin{columns}[T] % align columns
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/introduction/planar.pdf}}
\end{column}%
\hfill%
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/introduction/planar_not.pdf}}
\end{column}%
\end{columns}

## Kuratowski Theorem

The following assertions are equivalent for a Graph G:

1. $G$ is planar;
1. $G$ contains neither $K_5$ nor $K_{3,3}$ as a minor.

\begin{columns}[T] % align columns
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/introduction/k5.pdf}}
\end{column}%
\hfill%
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/introduction/k33.pdf}}
\end{column}%
\end{columns}

<!--## Kuratowski Theorem

Check the planarity of the following graph:
\centerline{\includegraphics[scale=0.4]{image/introduction/kurato_exo.pdf}}
-->


## Graph coloring
* ***Graph coloring*** consists in assigning a color to each
vertex such that 2 adjacent vertices have a different color

\begin{columns}[T] % align columns
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/introduction/coloring_toomuch.pdf}}
\end{column}%
\hfill%
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/introduction/coloring.pdf}}
\end{column}%
\end{columns}

* The ***chromatic number*** of a graph $G$, denoted $\chi(G)$ is
the minimum number of colors required to solve the
above problem.

* A graph $G$ is said ***$k$-colorable*** when $\chi(G) \leqslant k$

## Graph coloring (cont'd)
* $\chi(K_n) =$ ?
\centerline{\includegraphics[scale=0.6]{image/introduction/complete.pdf}}
* Find an upper bound on $\chi(G)$ with respect to the minimum and/or the maximum degree of $G$.

## Graph coloring (cont'd)
### Theorem
Every planar graph is 4-colorable

### Corollary
Any separation of a plane into contiguous regions can be
colored using at most 4 colors

\centerline{\includegraphics[scale=0.35]{image/introduction/four_color_world_map.png}}
(*Image des Maths, Revue de presse mars 2011*)

## Weighted graph

A ***weighted graph*** is a graph $G = (V, E)$ in which each edge $e \in E(G)$ is given a numerical weight $w(e)$, where $w : E \rightarrow \mathbb{R}$.

\centerline{\includegraphics[scale=0.5]{image/introduction/weighted_graph.pdf}}

## Path

A ***path*** is a non-empty graph $P = (V,E)$ of the form:

* $V = \{v_0, v_1, \ldots, v_k\}$
* $E = \{v_0v_1, v_1v_2, \ldots, x_{k-1}x_k\}$

The number of edges of a path is its ***length***.

In a graph $G$, a path is also defined of as a sequence of adjacent
vertices $P = v_0 v_1 \ldots v_k$.

\centerline{\includegraphics[scale=0.45]{image/introduction/path.pdf}}

## Cycles

If $P = v_0 \ldots v_{k-1}$ is a path and $k \geqslant 3$, then $C := v_0 \ldots v_{k-1}v_0$ is called a ***cycle***.

\centerline{\includegraphics[scale=0.45]{image/introduction/cycle.pdf}}

A graph that does not contain any cycle is called an ***acyclic*** graph.

## Cycles (cont'd)

An ***Eulerian cycle*** is a graph cycle which uses each graph edge exactly once.

\begin{columns}[T] % align columns
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/introduction/euler_graph.pdf}}
\end{column}%
\hfill%
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.4]{image/introduction/euler_graph_cycle.pdf}}
\end{column}%
\end{columns}

A graph that contains an Eulerian cycle is said to be a Eulerian graph.

## Cycles (cont'd)

An ***Hamiltonian cycle*** is a graph cycle which visits each vertex exactly once.

\centerline{\includegraphics[scale=0.4]{image/introduction/hamiltonian_cycle.pdf}}

A graph that contains a Hamiltonian cycle is said to be a Hamiltonian graph.

## Connectivity

A graph $G$ is ***connected*** if there exists a path between any two of its vertices.

\centerline{\includegraphics[scale=0.4]{image/introduction/connected.pdf}}

## Trees and forests

* A ***forest*** is an acyclic graph.
* A ***tree*** is a connected forest and the vertices of degree 1 are its ***leaves***.

\centerline{\includegraphics[scale=0.4]{image/introduction/tree.pdf}}

## Rooted tree

\centerline{\includegraphics[scale=0.5]{image/introduction/rooted_tree.pdf}}

## Directed graph

A ***directed graph*** or ***digraph*** $G = (V, A)$ with $n$ ***vertices*** (or ***nodes***) and $m$ ***arcs*** consists of:

* $V = V(G)$ : a vertex set; $n = |V|$ is the order of $G$
* $A = A(G)$ : a set of ordered pairs of vertices, called arcs; $m = |A|$

\centerline{\includegraphics[scale=0.5]{image/introduction/digraph.pdf}}

* $V(G) = \{u, v, w, x\}$
* $A(G) = \{(u,v), (u,w), (w,x), (x,w)\}$

## Directed Graph (cont'd)
An arc ${u, v} \in A(G)$ (written $uv$ for short) links two vertices $u, v \in V(G)$:

* $u$ and $v$ are said ***adjacent***
* $u$ is a ***predecessor*** of $v$
* $v$ is a ***successor*** of $u$

\centerline{\includegraphics[scale=0.5]{image/introduction/digraph.pdf}}

## Exercices

1. Donner une définition formelle du graphe $G/e$

\centerline{\includegraphics[scale=0.4]{image/introduction/contraction_exo.pdf}}

2. Donnez un exemple de graphe non dirigé connexe d'ordre 6 et 2-colorable.
   Détailler le graphe ainsi que la coloration.

3. Donnez un exemple de graphe $G$ d'ordre 6 dont le nombre chromatique est égal
   à 6. Donner une définition formelle de ce graphe.

## Exercices

4. Est-ce que le graphe suivant est planaire ? Veuillez justifier votre
   réponse.

\centerline{\includegraphics[scale=0.35]{image/introduction/kurato_exo.pdf}}

## Exercices

5. Est-ce que tout graphe bi-parti est acyclique ? Justifier votre réponse.

6. Donner une définition formelle du graphe dirigé suivant. En quoi cette
   définition est différente de la définition d'un graphe non dirigé ?

\centerline{\includegraphics[scale=0.5]{image/introduction/digraph_exo.pdf}}

## Exercices

5. Donner une définition formelle du plus court chemin entre les sommets $1$ et $6$ pour graphe
   suivant.

\centerline{\includegraphics[scale=0.4]{image/introduction/path_exo.pdf}}
