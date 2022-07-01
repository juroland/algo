# Structures de données : structures liées et contiguës, file à priorité et tas binaire.

1. Avec l'aide de la fonction `std::iter_swap`, implémenter une procédure non-récursive qui inverse un conteneur (une liste, un vecteur,...) composé de $n$ éléments. Cette procédure doit s'exécuter en $O(n)$ et utiliser un espace constant. Elle doit être implémentée sans l'utilisation de la fonction `std::reverse`. 
1. Comparez les performances de cette fonction lorsque le conteneur est un `std::vector` ou un `std::list`. Veillez à considérer des conteneurs d'objets ainsi que de pointeurs d'objets. Vous pouvez utiliser la fonction suivante pour estimer le temps d'exécution d'une fonction:
```cpp
    template <typename Function>
    double measure_execution(Function f, unsigned int n) {
        using namespace std::chrono;
        using clock = steady_clock;
        clock::time_point start = clock::now();
        repeat(f, n);
        clock::time_point end = clock::now();
        return (double)duration_cast<milliseconds>(end - start).count() / n;
    }
```
1. Comparez les performances de cette fonction avec `std::list::reverse`.
1. Sur base du tri par sélection, présenter, à l'aide d'un pseudo-code, un algorithme permettant de trier un ensemble de valeurs à l'aide d'une file à priorité. Quelle est la complexité en terme de temps et d'espace de cet algorithme si la file à priorité est implémentée à l'aide d'un tas binaire ? 
    ```
    SelectionSort(A)
        For i = 1 to n do
            Sort[i] = Find-Minimum from A
            Delete-Minimum from A
        Return(Sort)
    ```
1. Est-il possible de tester efficacement l'existence d'une valeur donnée dans un tas binaire ? Comparer la complexité de cet algorithme avec celle de [std::binary_search](http://en.cppreference.com/w/cpp/algorithm/binary_search).