---
title: "Graph Algorithms"
author: Julien Roland
date: 2018
---

# Ordonnancement 

## Ordonnancement 

Considérons le problème de l'ordonnancement de tâches parallèles. Ce problème est définit par
un ensemble de tâches, chacune caractérisée par une durée d'exécution, ainsi qu'un ensemble de
contraintes de précédences. L'objectif est de déterminer un ordonnancement des tâches (c-à-d une
instance de début pour chaque tâche) minimisant le temps total d'exécution tout en respectant les
contraintes de précédences.

## Ordonnancement : instance du problème

Considérons un projet composé de 10 tâches.

| tâche | durée | doit être complétée avant |
|-------|-------|---------------------------|
| 0     | 41.0  | 1 7 9                     |
| 1     | 51.0  | 2                         |
| 2     | 50.0  |                           |
| 3     | 36.0  |                           |
| 4     | 38.0  |                           |
| 5     | 45.0  |                           |
| 6     | 21.0  | 3 8                       |
| 7     | 32.0  | 3 8                       |
| 8     | 32.0  | 2                         |
| 9     | 29.0  | 4 6                       |

\scriptsize{(Réf.: Algorithms, 4th edition par R. Sedgewick et K. Wayne)}

## Ordonnancement

\centerline{\includegraphics[scale=0.8]{image/shortest_path/scheduling_solution.pdf}}

* Temps minimal pour réaliser l'ensemble des tâches (achèvement du projet) : 173
* **Chemin critique** : 0, 9, 6, 8, 2
* Tout retard dans l'ordonnancement des tâches appartenant au chemin critique augmente le temps
  nécessaire à l'achèvement du projet.

## Ordonnancement : représentation à l'aide d'un graphe dirigé acyclique

\centerline{\includegraphics[scale=0.8]{image/shortest_path/scheduling_dag.pdf}}

## Ordonnancement : plus long chemin

\centerline{\includegraphics[scale=0.8]{image/shortest_path/scheduling_dag_solution.pdf}}

# Dijkstra's algorithm

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
		if(d < dist[v]) {
			dist[v] = d;
			prec[v] = u;
		}
	}
}
```

## Dijkstra's algorithm

This algorithm solves the single-source shortest-path problem on a weighted graph $G = (V,A)$, where
$w(u, v) \geqslant 0$ for each arc $(u, v) \in A$.

* Runs in $O(n^2)$ if $Q$ is implemented with a *linked list*, $O((m+n)\log n)$ with a
   *binary heap* and $O(n \log n + m)$ with a *fibonacci heap*.

We need an algorithm that is able to solve this problem in graphs that contains arcs with negative weights.

\centerline{\includegraphics[scale=0.4]{image/shortest_path/dijkstra_fail.pdf}}

# Bellman-Ford's algorithm
## Bellman-Ford's algorithm

This algorithm solves the single-source shortest-path problem on a weighted graph $G = (V,A)$.

\centerline{\includegraphics[scale=0.4]{image/shortest_path/neg_cycle.pdf}}

* The weight of a cycle is the sum of the weights of its arcs.
* If there exists a negative weight cycle, this algorithm returns `false`.
* Otherwise, it returns `true`.

## Bellman-Ford's algorithm : observation

Any shortest path contains at most $(n-1)$ arcs:

\centerline{\includegraphics[scale=0.6]{image/shortest_path/bellman_observation.pdf}}

## Bellman-Ford's algorithm : pseudo-code

\small

```C
for each vertex v in V(G)
    d(v) = +infini;
d(s) = 0;

for path_length = 1 to n-1
{
    for each arc (u,v) in A(G) 
    {
        val = d(u) + w(u,v);
        if (val < d(v))
        {
              pred[v] = u;
              d(v) = val;
        }
    }
}
```

## Bellman-Ford's algorithm : pseudo-code

Negative weight cycle detection:

```C
for each arc (u,v) in G(A)
    if (d(u) + w(u,v) < d(v))
        return false;
return true;
```

* What is the worst-case complexity of the Bellman-Ford's algorithm ?

## Bellman-Ford's algorithm : example

\centerline{\includegraphics[scale=0.45]{image/shortest_path/bellman_ford_ok.pdf}}

# Minimum Spanning Trees
## Minimum Spanning Trees

* We need to connect a set of computers using the least amount of cables. Each computer is a vertex
  in a weighted graph $G = (V, E)$, where the weight $(v, u)$ is equal to the amount of cables needed
  to connect computers $v$ and $u$.

\centerline{\includegraphics[scale=0.4]{image/shortest_path/spanning_tree.pdf}}

## Minimum Spanning Trees

* We need to connect a set of computers using the least amount of cables. Each computer is a vertex
  in a weighted graph $G = (V, E)$, where the weight $(v, u)$ is equal to the amount of cables needed
  to connect computers $v$ and $u$.

\centerline{\includegraphics[scale=0.4]{image/shortest_path/spanning_tree_sol.pdf}}

## Minimum Spanning Trees

Formal definition:

* Given a weighted graph $G = (V, E)$, the **minimum spanning tree problem** consists of finding a
  subset $T \subseteq E$ so that $G' = (V, T)$ is a tree (*i.e.*, connected and acyclic) whose total
  weight is minimized.

* The total weight of $G'$ is defined as follows,

$$
w(T) = \sum_{\{u,v\} \in T} w(u, v)
$$

## Prim's Algorithm

* This algorithm is greedy. A **greedy** algorithm makes at each step a locally optimal choice
(*i.e.*, it makes the choice that looks the best at this step).

This algorithm is based on the following property.

* Let $V_1, V_2 \in V$ be a partition of $G$ into two disjoint nonempty sets. The minimum spanning
    tree contains an edge $e \in V_1 \times V_2$ such that $w(e) \leqslant w(e')$ for all $e' \in V_1 \times V_2$.


\centerline{\includegraphics[scale=0.4]{image/shortest_path/spanning_tree.pdf}}

## Prim's Algorithm

**Initialization**

```C
for (i = 0; i < n; ++i) {
    // points to an edge {.,i} in the spanning tree
    tree[i] = null;
    // points to an edge {.,i}
    edge[i] = null;
    // the weight of {.,i}
    weight[i] = +infini;
}

u = 0; // start vertex
```

## Prim's Algorithm

\small

```C
do {
   for each vertex v in adj[u] {
      if (tree[v] == null && w(u,v) < weight[v]) {
          weight[v] = w(u,v);
          edge[v] = {u,v};
      }
   }
   min_v = 0;
   for (v = 1; v < n; ++v) {
      if (tree[v] == null && weight[v] < weight[min_v])
          min_v = v;
   }
   if (min_v != 0)
       tree[min_v] = edge[min_v];
   u = min_v;
} while (u != 0);
```

# Exercices

## Exercices

1. Appliquer l'algorithme de *Bellman-Ford* sur les deux graphes suivants :

\begin{columns}[T] % align columns
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.40]{image/shortest_path/dijkstra_fail.pdf}}
\end{column}%
\hfill%
\begin{column}{.48\textwidth}
\centerline{\includegraphics[scale=0.40]{image/shortest_path/bellman_ford_nook.pdf}}
\end{column}%
\end{columns}

## Exercices

2. Quelle est la complexité au *pire-cas* de l'algorithme de Prim ?
3. Modifier l'algorithme de *Prim* afin d'utiliser un tas binaire. Quelle est la complexité de
   l'algorithme obtenu ?
4. Considérons un graphe pondéré $G = (V, E)$ et un arbre couvrant minimum (\textit{minimum spanning
   tree}) $T$ sur ce graphe. Supposons que l'on diminue le poids d'une arête $\{u, v\} \in E$, avec
   $\{u, v\} \notin T$. Présenter, à l'aide d'un pseudo code, un algorithme \emph{efficace} pour
   construire l'arbre couvrant minimum sur ce nouveau graphe (Indice : considérer le chemin $u$
   à $v$ dans $T$ ainsi que la propriété sur laquelle repose l'algorithme de Prim). Donner la
   complexité de cet algorithme (elle doit être inférieure à celle de l'algorithme de Prim).


## Exercices supplémentaires

1. Est-ce que l'algorithme de Dijkstra est similaire à un parcours en profondeur ou un parcours en
   largeur ? Pourquoi ? Justifiez votre réponse.
2. Présenter un algorithme pour déterminer le plus court chemin entre toutes paires de sommets dans
   un graphe digigé $G(V, A)$, où $w(u, v) \geqslant 0$ pour tout $(u, v) \in A$.
3. Afin de pouvoirs appliquer l'algorithme de Dijkstra sur des graphes acyclique comportant des
   poids négatifs, un étudiant nous a proposé de transformer le poids des arcs de la manière suivante
   : $w'(u, v) = w(u, v) + |\min\{w(u, v) : (u, v) \in A\}|$. Montrer à l'aide d'un exemple que cette
   solution est inadéquate.


## Exercices supplémentaires (suite)

4. Sur base des algorithmes vus au cours, comment résoudre, de manière efficace, le problème du plus
   long chemin dans un graphe dirigé acyclique ? Veuillez détailler votre réponse.

5. Appliquer l'algorithme de Bellman-Ford sur le graphe suivant, avec $0$ pour sommet source.
   Présenter son exécution de manière détaillée (contenu des différents tableaux à chaque étape de
   l'algorithme).

\begin{center}
   \includegraphics[scale=0.50]{image/shortest_path/dijkstra_fail.pdf}
\end{center}

