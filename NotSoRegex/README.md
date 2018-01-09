# Not So Regex

## Attention
Ce défi vaut beaucoup de points, mais peut être **très** long à compléter. Il
vous est conseillé de vous assurer de votre compréhension du problème avant de
tenter de le compléter. Par contre, il est possible de rapidement aller chercher
quelques points sans tout compléter. Pour vous simplifier la vie, ce défi ne
demande que des true/false. Alors, il vous est demandé de ne pas simplement
retourner des valeurs stupides en espérant recevoir 50% des points.

Votre collègue aimerait pouvoir télécharger l'Internet et être capable d'y
trouver tous les numéros de cartes de crédits. Pour ce faire, il vous
demande de produire un programme étant capable de trouver des chaines de
caractères selon un patron. Il ne veut pas que vous utilisiez des méthodes
utilisant des REGEX puisque ces dernières sont trop lentes pour pouvoir
interpréter tout l'Internet.

La première valeur sera l'expression et la deuxième sera la chaine de caractères
à tester. Si les deux concordent vous devrez retourner un `true` sinon un
`false`.

Si l'expression contient une erreur, vous devez retourner un `false`.

Le code de ce numéro sera relu par un humain pour être certain qu'aucun REGEX ou
équivalent n'a été utilisé. En cas de doûte, venez nous poser la question.

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
Les modificateurs sont de type préfixe. Ceci veut dire que la modification
s'applique sur le caractère suivant ou le groupe suivant.

Pour simplifier votre tâche, les modificateurs sont de type [possessif]
(https://www.regular-expressions.info/possessive.html). Ceci veut dire que si
vous trouvez une partie de chaine fonctionnelle, vous ne devrez jamais
« redonner » cette partie de chaine. Il est conseillé d'aller lire l'article
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
