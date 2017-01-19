# OSEmulator
Vous êtes ingénieur à l'an 2100 (et oui le temps passe ci vite). L'un de vos collègues vous amène un ancien jeu PC. Vous enlever la poussière du disque et vous vous rendez compte que c'est le CD du jeu Diablo, vous y avez tellement joué dans votre enfance que la nostalgie l'emporte. Vous devez absolumenet rejouer à ce jeu!!!

Malheureusement, il n'existe plus de PC qui roule avec l'architecture de processeur x86 (une vielle antiquitée des années 1900). Vous décider donc d'écrire un émulateur x86 pour pouvoir y jouer!

## Règles
Pour ce faire, votre émulateur devra comprendre les régistres suivants: `a`, `b`, `c`, `d`.

**Ces régistres sont initialisés a 0 au début de l'exécution.**

Voici la liste des instructions à implémenter pour y arriver:
```
MOV **DEST** **SRC|IMM**
Copie le régistre ou la valeur entière dans le registre DEST.
Example: MOV a 3 Équivalent à (a=3)
```

```
ADD **DEST** **SRC|IMM**
Ajoute le régistre ou la valeur entière dans le registre DEST.
Example: ADD a 3 Équivalent à (a+=3)
```

```
SUB **DEST** **SRC|IMM**
Soustrait le régistre ou la valeur entière du registre DEST.
Example: SUB a 3 Équivalent à (a-=3)
```

```
XOR **DEST** **SRC|IMM**
Xor le régistre ou la valeur entière avec le registre DEST.
Example: XOR a 3 Équavlent à (a^=3)
```

À la fin des instructions, vous devrez printer tous les régistres en commençant par le registre `a` et en finissant par `d`.

## Intéraction avec la plateforme
### Inputs
**Ligne 1**: Le nombre d'instructions `N`.
**Ligne N**: Les instructions à exécuter.

### Output
Vous devez outputer dans le stdout les régistres à la fin de l'exécution.
**Ligne 1**: Le régistre a.
**Ligne 2**: Le régistre b.
**Ligne 3**: Le régistre c.
**Ligne 4**: Le régistre d.

### Exemple
**Input**
```
9
MOV a 3
XOR a 1
SUB a 2
MOV b 2
MOV c 3
XOR b c
MOV d 1
ADD d 2
SUB c 1
```
**Output**
```
0
1
2
3
```