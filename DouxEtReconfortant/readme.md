# Doux et réconfortant
En un dimanche matin pluvieux, un bon ami vous met au défi de trouver ses nombres secrets à partir des résultats du script suivant.

```
from secrets import secret

p = 31525197391593473
g = 2187
print(pow(g, secret, p))
```

Comme `p-1` n'est pas si grand vous songez d'abord à effectuer une attaque de type [_meet-in-the-middle_](https://en.wikipedia.org/wiki/Meet-in-the-middle_attack). Selon un calcul rapide 288 Go en mémoire vive et le tour joué. Malheureusement, vous vous réveillez en sursaut et réalisez que vous êtes en fait pauvre.

Ne baissant pas les bras, vous poursuivez votre analyse et êtes heureux de constater que l'ordre de ce générateur est `2^52`, soit un nombre doux ([_smooth number_](https://en.wikipedia.org/wiki/Smooth_number)).

## Règles
Il faut ici calculer le logarithme discret demandé, c'est-à-dire trouver la valeur entière `t` dans l'expression `g^t = h`, où t appartient à l'intervalle `[0, 2^52-1]`.

## Interaction avec la plateforme
### Inputs
**Ligne 1**: h le résultat de la mise à la puissance

### Output
t la solution du logarithme discret

### Exemple
**Input**
```
4782969
```
**Output**
```
2
```
