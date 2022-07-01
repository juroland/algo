# Stuctures de données : ADT Map
1. Implémenter un annuaire téléphonique inversé. Celui-di doit nous permettre de retrouver une personne étant donné un numéro de téléphone sous le format suivant : `[1-9]\d{3}`, où `[1-9]`. C'est-à-dire un chiffre de 1 à 9 suivit de 3 chiffres. Pour simplifier, ces numéros de téléphones sont représentés sous la forme d'un nombre entier. Toutes les opérations (suppression, insertion, et recherche) doivent s'effectuer en $O(1)$. Veillez à y ajouter les constructeurs et autres méthodes nécessaires. Quel espace mémoire est utilisé par la structure de données ?
    ```cpp
    struct Person { std::string first_name, last_name; };

    class ReverseTelephoneDictionary {
    public:
        // Retourne une paire où la première valeur est une
        // copie de l'objet de type Person associé à ce numéro
        // de téléphone. Si cette association n'existe pas,
        // alors retourne une instance de la structure Person
        // construite par défaut. La deuxième valeur est un
        // booléen égal à vrai si ce numéro existe dans le
        // dictionnaire, faux sinon.
        std::pair<Person, bool> find(int number);
        void insert(int number, Person p);
        void erase(int number);
    };
    ```
1. Sur base de la déclaration de la classe suivante, implémenter l'ADT Map à l'aide d'une table de hachage avec résolution de collisions par chaînage. Le nombre d'emplacements dans la table de hachage est le paramètre $size$ du constructeur.
    ```cpp
    template<typename T>
    class Map {
    public:
        Map(int size);
        using key_type = std::string;
        T& operator[](const key_type& key);
        void erase(const key_type);
    };
    ```
Nous considérons pour valeur de clé uniquement des chaîne de caractères. La fonction de hachage
est définie comme suit pour toute chaîne de caractères $S$ sur un alphabet de taille $\alpha$:
$$
H(S) = \sum_{i = 0}^{|S|-1} \alpha^{|S|-(i+1)} \times char(s_i),
$$
où `char(c)` est une fonction qui associe à chaque symbole de l'alphabet un entier unique de $0$
à $\alpha -1$.

1. Sur base de `map_perf.cpp`, évaluer expérimentalement l'influence de la taille de la table de hachage sur la recherche d'éléments pris aléatoirement. Celle-ci doit être remplie aléatoirement en prenant pour modèle l'utilisation du `std::unordered_map` utilisé dans la fonction  `main()`.
