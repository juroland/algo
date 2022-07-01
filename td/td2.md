# Utilisation de la bibliothèque algorithmique

1. Implémenter la fonction suivante: 
```cpp
template<typename Iter>
typename Iter::value_type
dot(Iter first1, Iter last1, Iter first2); 
```
1. Considérons un ensemble de valeurs entières contenues dans un `std::vector<int>`.
Utiliser les fonctions de la bibliothèque algorithmique^[<http://en.cppreference.com/w/cpp/algorithm>]
afin de résoudre de manière efficace les problèmes suivants
(veillez à minimiser l'utilisation explicite de boucles) :
    a. Déterminer si toutes les valeurs sont positives ou nulles.
    a. Remplacer toutes les valeurs négatives par 0.
    a. Afficher toutes les valeurs positives (utiliser un `std::ostream_iterator`).
    a. Déterminer la position du premier et du dernier élément négatif.
1. À l'aide de la fonction `std::find_if`^[<http://en.cppreference.com/w/cpp/algorithm/find>]
et d'une *lambda*, compléter le code suivant afin de trouver et d'afficher la date
de naissance d'Alan Turing.
    ```cpp
    std::vector<std::pair<std::string, std::string>> birthday;
    birthday.push_back(std::make_pair("Edsger W. Dijkstra", "11 May 1930"));
    birthday.emplace_back("Alan Turing", "23 June 1912");
    birthday.emplace_back("Donald E. Knuth", "10 January 1938");
    ```
1. Considérons un ensemble de valeurs entières dans un `std::vector<int>`. À l'aide de la
fonction `std::stable_partition`^[<http://en.cppreference.com/w/cpp/algorithm/stable_partition>],
écrire une fonction permettant de déplacer l'ensemble des valeurs paires au début de ce conteneur.
L'ordre de ces valeurs doit être conservé.
1. Modifier la fonction précédente afin de déplacer non plus les valeurs paires, mais tout
entiers satisfaisant un prédicat unaire passé en paramètre de cette fonction.
\newpage
1. Considérons un conteneur quelconque.
A l'aide de la fonction `std::rotate`^[<http://en.cppreference.com/w/cpp/algorithm/rotate>],
implémenter une fonction permettant de déplacer un intervalle (décrit par une paire d'itérateurs) en une position
précise de ce conteneur (indiqué par un troisième itérateur).
1. Considérons un conteneur quelconque. A l'aide de la fonction `std::rotate`,
implémenter une fonction permettant de réaliser une rotation d'une position vers la droite.
