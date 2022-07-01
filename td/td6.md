# Graphes : théorie et implémentation

1. Donner un exemple pour chacun des graphes suivants :
    * Graphe bi-parti cyclique.
    * Graphe complet planaire d'ordre 4.
    * Un graphe planaire $K_{m, n}$ avec $m \geqslant 2$ et $n \geqslant 3$
    * Un graphe biparti avec un nombre d'arêtes maximal, où l'ordre du graphe est égal à $2n$.
    * Un graphe d'ordre $n$ dont le nombre chromatique est égal à 1.
1. Pour le graphe présenté à la Figure \ref{GrapheD}:
    * Présenter la liste d'adjacence.
    * Présenter la matrices d'adjacence.
    * L'ensemble des prédécesseurs du sommet $c$.
1. Le graphe $G$ présenté à la Figure \ref{GrapheG} est-il connexe ? Pourquoi ?
1. Quel est le degré du sommet $d$ dans le graphe G ?
1. Considérons le graphe $G/x$, où $x = \{c, e\}$. Quel est le nombre d'arêtes dans ce graphe ?
1. Le carré d'un graphe dirigé $V = (V, A)$ est le graphe $G^2 = (V, A^2)$ tel que $(u, w) \in A^2$ si et seulement si il existe un $v \in V$ tel que $(u, v) \in A$ et $(v, w) \in A$ (c'est-à-dire qu'il existe un chemin composé de deux arcs de $u$ à $w$). Présenter à l'aide de pseudo-codes des algorithmes pour des graphes implémentés à l'aide de listes d'adjacences et de matrices d'adjacences.

\newpage

\begin{figure}
\centering
\includegraphics[scale=0.5]{figures/graph2.pdf}
\caption{Graphe D.}
\label{GrapheD}
\end{figure}

\begin{figure}
\centering
\includegraphics[scale=0.5]{figures/graph1.pdf}
\caption{Graphe G.}
\label{GrapheG}
\end{figure}