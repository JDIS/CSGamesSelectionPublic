# Scrabble
## Le but
Au scrabble, chaque joueur pige 7 lettres, puis avec ces 7 lettres le joueur doit tenter de faire un maximum de points en mettant un mot valide sur la grille.
Par exemple, avec les lettres `norjubo` vous pouvez faire les mots suivant : `bon`, `jour`, `bonjour`, `job`, etc.
L’objectif est de trouver le mot qui fait le plus de points.

## Règles
e,a,i,o,n,r,t,l,s,u = 1 points

d,g = 2 points

b,c,m,p = 3 points

f,h,v,w,y = 4 points

k = 5 points

j,x = 8 points

q,z, = 10 points

Donc le mot `jour` vaut 8+1+1+1 = 11 points.

## Intéraction avec la plateforme
### Inputs
**Ligne 1**: Le nombre `N` de mots dans le dictionnaire.

**`N` lignes suivantes**: Les mots du dictionnaire. Un par ligne.

**Dernière ligne**: Les 7 lettres de votre jeux.

### Output
Vous devez outputer dans le stdout le mot qui vaut le plus de points que vous pouvez jouer à partir de votre jeux.
**Si deux mots ont le même score, alors le mot à outputter sera lui qui est en premier dans le dictionnaire.**

### Exemple
**Input**
```
5
because
first
these
could
which
hicquwh
```
**Output**
```
which
```