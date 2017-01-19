# CryptoMessage
CryptoMessage est une nouvelle application à la mode. Les gens l'utilise pour son aspect sécuritaire. Mais l'est-il vraiment?

En tant que hacker, vous vous donnez comme mission de le découvrir! En reverse engineerant la plateforme, vous decouvrez cette partie de code qui vous intrigue:

`var key = 'S3cur3K3y';`

Avec vos connaissances en cryptography, vous croyez que vous serez capable déchiffrer les ciphers de l'application et d'en obtenir les messages. Vous trouvez donc un vecteur d'attaque "men in the middle" qui vous permet d'obtenir plusieurs ciphers.

Afin de rendre les ciphers lisibles vous les encoders en **base64**.

Votre défi est d'obtenir le message que contient ces ciphers.

## Règles
Puisque c'est un défi de sécurité, il n'y a pas plus d'information que la mise en situation.

Pour ceux qui n'ont aucune expérience en cryptographie, **l'algorithme d'encryption est très simple et ne reflètent en rien les algorithmes utilisés dans la vrai vie.**

## Intéraction avec la plateforme
### Inputs
**Ligne 1**: Le cipher.

### Output
Vous devez outputer dans le stdout le message.

### Exemple
**Input**
```
EFYAHFJ9bFYKJxMzFAETPl1ZHgAQBhNULhI==
```
**Output**
```
Ceci N'est Pas un M3ssage!
```