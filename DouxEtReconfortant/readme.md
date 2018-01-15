# Doux et réconfortant
En un dimanche matin pluvieux, vous décidez d'étudier par ingénierie inverse le fonctionnement de votre application de messagerie préférée et découverez que son développeur a eu l'_excellente_ idée de créer son propre protocole d'échange de clefs. 

Ce protocole est en fait une variante du protocole Diffie-Hellman sur le corps fini
`GF(2^64) = GF(2)[x]/(x^64 + x^33 + x^30 + x^26 + x^25 + x^24 + x^23 + x^22 + x^21 + x^20 + x^18 + x^13 + x^12 + x^11 + x^10 + x^7 + x^5 + x^4 + x^2 + x + 1)`. De plus, le générateur `x`, ou, `0000000000000000000000000000000000000000000000000000000000000010` sous forme binaire, est utilisé.

Vous songez d'abord à paralléliser le problème sur votre CPU à 500 coeurs avec une attaque de type [_meet-in-the-middle_](https://en.wikipedia.org/wiki/Meet-in-the-middle_attack). Malheureusement, vous vous réveillez en sursaut et réalisez que vous êtes en fait pauvre.

Pas de CPU à 500 coeurs pour vous.

Ne baissant pas les bras, vous poursuivez votre analyse et êtes heureux de constater que l'ordre de ce générateur est `2^64`, soit un nombre doux ([_smooth number_](https://en.wikipedia.org/wiki/Smooth_number)).

## Règles
Il faut ici calculer le logarithme discret demandé, c'est-à-dire trouver la valeur entière `t` dans l'expression `A^t = B`, où `A = x` et `B` appartient à `GF(2^64)`.

## Interaction avec la plateforme
### Inputs
**Ligne 1**: Polynôme (B) sous forme binaire de 64 bits

### Output
Solution du logarithme discret (t) en base 10

### Exemple
**Input**
```
1000000010000000000001000001011000000011100000000001000010000010
```
**Output**
```
1613577258690797637
```
