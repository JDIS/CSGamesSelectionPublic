# CryptoMessage
CryptoMessage est une nouvelle application à la mode. Les gens l'utilisent pour son aspect sécuritaire. Mais l'est-elle vraiment?

En tant que hacker, vous vous donnez comme mission de le découvrir! Par ingénierie inverse (_reverse engineering_), vous découvrez dans la plateforme cette partie de code qui vous intrigue:

`var key = 'S3cur3K3y';`

Avec vos connaissances en cryptographie, vous croyez que vous êtes capable de déchiffrer les ciphers de l'application afin d'en obtenir les messages. Vous trouvez donc un vecteur d'attaque de type _man in the middle_ qui vous permet d'obtenir plusieurs ciphers.

Afin de rendre les ciphers lisibles, vous les encodez en **base64**.

Votre défi est d'obtenir le message que contient ces ciphers.

## Règles
Puisque c'est un défi de sécurité, il n'y a pas plus d'information que ce qui est décrit dans la mise en situation.

Pour ceux qui n'ont aucune expérience en cryptographie, sachez que **l'algorithme d'encryption est très simple** et ne reflète en rien les algorithmes utilisés en contexte réel.**

## Interaction avec la plateforme
### Inputs
**Ligne 1**: Le cipher.

### Output
Vous devez afficher le message sur la sortie standard (_stdout_).

### Exemple
**Input**
```
EFYAHFJ9bFYKJxMzFAETPl1ZHgAQBhNULhI==
```
**Output**
```
Ceci N'est Pas un M3ssage!
```