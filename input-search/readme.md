# Input-Search
## Le but
Votre patron vient vous voir avec une tâche plutôt hors du commun. Il désire cracker la sérialisation d'un vieil exécutable que la compagnie utilise depuis longtemps.
Cependant, vous n'avez pas accès au code du programme. Vous sortez donc votre désassembleur préféré (IDA bien entendu) et vous identifiez la section du code qui sérialise les inputs.

Voici à quoi la fonction ressemble en assembleur intel x64:
```
xor rsi, rsi
mov sil, rax
shl rsi, 0xe
neg esi
add si, rax
bswap esi
shl rsi, 0x9
add sil, 0x10
xor ecx, ecx
mov ecx, rsi
```

Vous avez également remarquer que les inputs se retrouvent dans le régistre rax au début de cet algorithme. Et puisque seulement les 16 bits les plus bas de rax sont utilisé, 2 charactères sont pris en compte dans la sérialisation. Les clés que vous désirez cracker sont dans le régistre ecx. Vous voulez retrouver les inputs (ax) à partir du contenu de ecx.

Cependant, puisque 32 bits sont perdu dans l'opération `mov ecx, rsi`, il est impossible de retrouver avec exactitude le contenu. Vous devrez donc trouver toutes les possibilités de `ax` qui donne le résultat voulu.

## Règles
Voici le format de `rax`:
```
-----------------|chr2|chr1|
0x0000 0000 0000 |71  |32  |
```

La liste des résultats possibles doit **être retourné trié en ordre ascendant de valeur rax**.

## Intéraction avec la plateforme
### Inputs
**Ligne 1**: Valeur de `ecx`

### Output
Les résultats possibles doivent être **retourné sur des lignes séparés en ordre ascendant de valeur de rax**.

Les résultats doivent également être printer en **string**.

La liste des charactères possible est `charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789{}[]-_.:,"`

### Exemple
**Input**
```
0xe5e7fe10
```
**Output**
```
12
32
2r
4r
```