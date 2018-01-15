# Parcours de graphe
## Règles
Vous devez parcourir un [graphe](https://en.wikipedia.org/wiki/Graph_(abstract_data_type)) et trouver le
chemin le plus court entre deux noeuds donnés. Pour un même poids, un **chemin avec moins de noeuds doit être favorisé**.

À la fin, vous devez imprimer chaque noeud visité en ordre. Votre liste doit inclure le noeud initial et le noeud final.
Les noeuds sont indiqués par des chiffres commençant à 0 et terminant au nombre de noeuds moins 1.

Les arcs sont définis par la source, la destination et le prix de déplacement. À noter, **les arcs sont unidirectionnels**.

![Voir le graphe](https://github.com/carapas/CSGamesSelectionPublic/blob/master/Graph/graph.png?raw=true "Graphe")

## Interaction avec la plateforme
### Inputs
**Ligne 1**: Le nombre de noeuds.

**Ligne 2**: Le nombre d'arcs `N`.

**Ligne 3**: Le noeud initial.

**Ligne 4**: Le noeud de destination.

**Ligne N**: Les arcs.

### Output
Vous devez sortir la liste de noeuds parcourus sur la sortie standard (_stdout_).

**Ligne 1**: Le noeud initial.

**Ligne 2 à N**: Les noeuds intermédiaires.

**Ligne N**: Noeud final.

### Exemple
**Input**
```
4
4
0
2
0 1 2
1 2 4
1 3 5
2 3 3
```
**Output**
```
0
1
3
```
