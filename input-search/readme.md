# Input-Search
## Le but
Votre patron vient vous voir avec une tâche qui sort de l'ordinaire : il désire cracker la sérialisation d'un vieil exécutable utilisé par votre compagnie depuis longtemps. Cependant, vous n'avez pas accès au code du programme. Vous sortez donc votre désassembleur préféré (IDA, bien entendu) et vous identifiez la section du code qui sérialise les inputs.

Voici à quoi la fonction ressemble en assembleur Intel x64:
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

Vous avez également remarqué que les inputs se retrouvent dans le registre `rax` au début de cet algorithme. De plus, puisque seulement les 16 bits inférieurs de `rax` sont utilisés, 2 caractères sont pris en compte dans la sérialisation. Les clés que vous désirez cracker sont dans le registre `ecx`. Vous voulez retrouver les inputs (`ax`) à partir du contenu de `ecx`.

Cependant, puisque 32 bits sont perdus dans l'opération `mov ecx, rsi`, il est impossible de retrouver le contenu exact. Vous devrez donc trouver toutes les possibilités de `ax` qui donnent le résultat voulu.

## Règles
Voici le format de `rax`:
```
-----------------|chr2|chr1|
0x0000 0000 0000 |71  |32  |
```

La liste des résultats possibles doit être retournée **triée en ordre ascendant de valeur `rax`**.

## Interaction avec la plateforme
### Inputs
**Ligne 1**: Valeur de `ecx`

### Output
Les résultats possibles doivent être **retournés sur des lignes séparées en ordre ascendant de valeur de `rax`**.

Les résultats doivent également être imprimés en **string**.

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
