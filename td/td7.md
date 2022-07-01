# Graphes : implémentation en C++

```C++
struct Arc {
    int v; // Extrémité
    int weight;
};

struct DirectedGraph {
    std::vector<std::vector<Arc>> adj;
};

// Lecture en entrée standard d'un graphe au format suivant :
//     Première ligne   : le nombre de sommets suivi du nombre d'arcs
//     Lignes suivantes : chaque arc est décrit par une paire d'entiers
//                        source destination suivi d'une valeur de poids
// Par exemple pour un graphe dirigé complet sur 3 sommets,
// où chaque arc a un poids de 1:
// 3 6
// 0 1 1
// 0 2 1
// 1 0 1
// 1 2 1
// 2 0 1
// 2 1 1
DirectedGraph read_graph(std::istream& input);

// Ajout d'un arc entre du sommet u au sommet v
void insert_arc(DirectedGraph& g, int u, int v, int w);

// Affiche les sommets successeurs de chaque sommet
// Par exemple, pour un graphe complet sur 3 sommets
// où chaque arc a un poids de 1:
// 0 : 1(1) 2(1)
// 1 : 0(1) 2(1)
// 2 : 0(1) 1(1)
void print_graph(const DirectedGraph& g, std::ostream& output);

// Implémente l'algorithme de parcours en largeur à partir du sommet start dans le graphe g
// la fonction visit est appelée pour chaque sommet en respectant l'ordre du parcours
void bfs(const DirectedGraph& g, int start, std::function<void(int)> visit);

// Implémente l'algorithme de parcours en profondeur à partir du sommet start dans le graphe g
// la fonction visit est appelée pour chaque sommet en respectant l'ordre du parcours
void dfs(const DirectedGraph& g, int start, std::function<void(int)> visit);

struct DijkstraResults {
    std::vector<int> dist;
    std::vector<int> prec;
};

// Applique l'algorithme de Dijkstra sur le graphe g
DijkstraResults dijkstra(const DirectedGraph& g, int source);

// Retourne pour chaque somme la composante à laquelle il appartient
std::vector<int> strongly_connected_components(const DirectedGraph& g);

std::vector<int> find_path(const DirectedGraph& g, int start, int end);

std::tuple<bool, int, int> find_first_cycle(const DirectedGraph& g);
```
