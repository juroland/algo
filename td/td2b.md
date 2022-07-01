# Utilisation de la bibliothèque algorithmique

1. Considérons le tri bulle dont le pseudo-code vous est présenté ci-dessous.
    ```cpp
    function bubblesort (A : list[1...n])
        var int i, j
        for i from n to 1
            for j from 1 to i − 1
                if (A[j] > A[j + 1])
                    swap the values of A[j] and A[j + 1]
    ```
    Implémenter cet algorithme sous la forme d'une fonction C++ à l'aide de la bibliothèque
    algorithmique. Les opérations de tri telles que `std::sort` sont bien entendu proscrites.
    Veillez à réduire au mieux l'utilisation explicite de boucles. Cette fonction doit respecter
    la signature suivante.
    ```cpp
    template< class RandomIt >
    void bubble_sort( RandomIt first, RandomIt last );
    ```
1. Modifier cette fonction afin d'implémenter la fonction suivante:
    ```
    template< class RandomIt, class Compare >
    void bubble_sort( RandomIt first, RandomIt last, Compare comp );
    ```
    Montrer comment utiliser cette fonction pour trier un tableau d'entiers de manière croissante
    et décroissante. Pour ce faire, veillez à utiliser les foncteurs (objet fonction) définis
    dans la librairie `functional` (`#include<functional>`).
1. Considérons l'application de cette fonction `bubble_sort` sur un `std::vector<double>`.
Définissez la structure (foncteur) `LessIntegralPart` dans le but de créer un objet qui compare
des paires de `double` sur base de la partie entière.
1. Même question avec l'utilisation d'une lambda à la place de la définition d'une structure.