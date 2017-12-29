# Not So Regex
Votre collègue aimerait pouvoir télécharger l'Internet et être capable d'y trouer
toutes les numéros de cartes de crédits contenus. Pour se faire il vous demande
de produire un programme étant capable de trouver des chaines de caractères selon
un patron. Il ne veut pas que vous utilisiez des méthodes utilisant des REGEX
puisque ces derniers sont trop lent pour pouvoir interpréter tout l'Internet.

La première valeur sera l'expression et la deuxième sera la chaine de caractères
à tester. Si les deux concordent vous devrez retourner un `true` sinon un
`false`.

Si le l'expression contient une erreur, vous devez retourner un `false`.

Ce code de ce numéro sera relut par un humain pour être certain qu'aucun REGEX ou
équivalent n'a été utilisé. En cas de doûte, vennez nous poser la question.

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

Pour s'implifier votre tâche, les modificateurs sont de type [possessif]
(https://www.regular-expressions.info/possessive.html). Ceci veut dire que si
vous trouvez une partie de chaine fonctionnelle, vous ne devrez jamais "redonner"
cette partie de chaine. Il est conseillé d'aller lire l'article 
https://www.regular-expressions.info/possessive.html.

- `*`, n'importe combien d'occurence
- `?`, 0 ou 1
- `+`, plus de zero occurence

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
