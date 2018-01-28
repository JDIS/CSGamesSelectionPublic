# Not So Regex

## Attention

Ce défi vaut beaucoup de points, mais peut être **très** long à compléter. Il
vous est conseillé de vous assurer que vous comprenez bien le problème avant d'essayer de le compléter. Par contre, il est possible d'aller chercher
quelques points rapidement sans tout compléter.

Votre collègue aimerait pouvoir télécharger l'Internet (oui oui, au complet!) pour être capable d'y
trouver tous les numéros de cartes de crédit. Pour ce faire, il vous
demande de produire un programme étant capable de trouver des chaînes de
caractères suivant un patron donné. Il ne veut pas que vous utilisiez des méthodes
utilisant des expressions régulières (aussi connues sous le nom familier _regex_) puisque ces dernières sont trop lentes pour pouvoir interpréter tout l'Internet.

La première ligne sera l'expression, la deuxième ligne sera le nombre de chaînes (disons n) et les n prochaines lignes seront des chaînes à tester.

En sortie, vous ne devez que retourner les chaînes qui sont valides pour l'expression donnée.

Par exemple,

```
a
2
a
b
```

Et vous devrez alors écrire sur la sortie standard
```
a
```

Note: si l'expression contient une erreur, vous devez retourner `erreur` sur une seule ligne, et ce, peu importe le nombre de chaînes qu'il vous est demandé de tester.

Le code de ce numéro sera vérifié par les organisateurs pour assurer qu'aucune regex ou
technique équivalente n'ont été utilisées. En cas de doute, venez nous voir.

## Niveau 1
- Lettres
- Nombres
- Groupes `( )`

**Exemple**
- `a` !~= `b`
- `aabbcc` ~= `aabbcc`
- `a12bc` ~= `a12bc`
- `123` ~= `123`
- `(1(2))3` ~= `123`
- `(1(2)` erreur

## Niveau 2
Les modificateurs sont de type «préfixe», ce qui veut dire que la modification
s'applique sur le caractère suivant (ou le groupe suivant).

Pour vous simplifier la tâche, les modificateurs sont de type [possessifs]
(https://www.regular-expressions.info/possessive.html), ce qui veut dire que si
vous trouvez une partie de chaîne fonctionnelle, vous ne devrez jamais
«redonner» cette partie de chaîne. Il est conseillé de lire l'article
https://www.regular-expressions.info/possessive.html.

- `*`, 0 ou plus d'occurrences
- `?`, 0 ou 1
- `+`, au moins une occurrence

**Exemple**
- `*a` ~= ` `
- `*a` ~= `a`
- `*a` ~= `aa`
- `?a` ~= ` `
- `?a` ~= `a`
- `+a` ~= `a`
- `+a` ~= `aa`
- `a*(abc)` ~= `aabcabc`
- `+(bc?a*(bb?(dd)b))` ~= `bcbbbbbbbca`
- `+a+` erreur
