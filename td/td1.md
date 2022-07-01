# Analyse des algorithmes
1. Considérons le problème du produit matriciel :
    * Entrée : Deux matrices $A$ (de dimension $x \times y$) et $B$ (de dimension $y \times z$).
    * Sortie : Une matrice $C$ de dimension $x \times z$, où $C_{ij}$ est le produit scalaire entre la i-ème ligne de $A$ et la j-ème colonne de $B$.

    Présenter un algorithme sous la forme d'un pseudo-code permettant de résoudre ce problème. Évaluer de manière exacte le nombre de multiplications $M(x, y, z)$ et en déduire la complexité au pire cas de cet algorithme.
1. Quelles valeurs sont retournées par les fonctions C++ suivantes ? Exprimer votre réponse sous la forme d'une fonction de paramètre $n$. Donner les complexités au pire cas de chaque fonction en utilisant la notation en grand $O$.
    ```C
    int mystery(int n) {
        r = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                for (int k = 1; k <= j; ++k)
                    ++r;
            }
        }
        return r;
    }

    int pesky(int n) {
        int r = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                for (int k = j; k <= i+j; ++k)
                    ++r;
            }
        }
        return r;
    }
    ```
\newpage
1. Donner les complexités au pire cas des fonctions suivantes en utilisant la notation en grand $O$.
    ```C
    int fct1(int n) {
        int i = 2;
        while (i < n*n) {
            i = i*i;
        }
        return i;
    }
    int fct2(int n) {
        while (n > 1) {
            n = n/2;
        }
        return n;
    }
    ```
1. Pour chaque paire de fonctions $f(n)$ et $g(n)$, déterminer si $f(n) = O(g(n))$, $g(n) = O(f(n))$, ou les deux.
    * $f(n) = (n^2 - n)/2$,  $g(n) =6n$
    * $f(n) = n +2 \sqrt n$, $g(n) = n^2$
    * $f(n) = n \log n$, $g(n) = n \sqrt n /2$
    * $f(n) = n + \log n$, $g(n) = \sqrt n$
1. Démontrez que $n^2 = O(2^n)$