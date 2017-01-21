# OSEmulator
Vous êtes ingénieur à l'an 2100 (et oui le temps passe ci vite). L'un de vos collègues vous amène un ancien jeu PC. Vous enlever la poussière du disque et vous vous rendez compte que c'est le CD du jeu Diablo, vous y avez tellement joué dans votre enfance que la nostalgie l'emporte. Vous devez absolumenet rejouer à ce jeu!!!

Malheureusement, il n'existe plus de PC qui roule avec l'architecture de processeur x86 (une vielle antiquitée des années 1900). Vous décider donc d'écrire un émulateur x86 pour pouvoir y jouer!

## Règles
Pour ce faire, votre émulateur devra comprendre les régistres suivants: `a`, `b`, `c`, `d`.

**Ces régistres sont initialisés a 0 au début de l'exécution.**

Voici la liste des instructions à implémenter pour y arriver:
```
Terminologie
IMM: Valeur entière. e.g: 1,2,3,4,5,6
SRC: Régistre utilisé dans une opération. e.g: a,b,c,d
DEST: Régistre utilisé dans une opération et régistre de stockage du résultat. e.g: a,b,c,d
```

```
MOV **DEST** **SRC|IMM**
Copie le régistre ou la valeur entière dans le registre DEST.
Exemple: MOV a 3 Équivalent à (a=3)
```

```
ADD **DEST** **SRC|IMM**
Ajoute le régistre ou la valeur entière dans le registre DEST.
Exemple: ADD a 3 Équivalent à (a+=3)
```

```
SUB **DEST** **SRC|IMM**
Soustrait le régistre ou la valeur entière du registre DEST.
Exemple: SUB a 3 Équivalent à (a-=3)
```

```
XOR **DEST** **SRC|IMM**
Xor le régistre ou la valeur entière avec le registre DEST.
Exemple: XOR a 3 Équivalent à (a^=3)
```

À la fin des instructions, vous devrez printer tous les régistres en commençant par le registre `a` et en finissant par `d`.

À l'aide de ces instructions vous pourrez compléter la première partie du défi et donc obtenir 4 points. Implémenter les instructions de la 2ieme partie pour avoir les 4 points finaux:
```
Terminologie
REG: Régistre utilisé dans une opération. e.g: a,b,c,d
IMM: Valeur entière. e.g: 1,2,3,4,5,6
SRC: Régistre utilisé dans une opération. e.g: a,b,c,d
```

```
CMP **REG** **SRC|IMM**
Compare le régistre REG avec SRC|IMM, si les deux sont égaux l'opération assigne la valeur 1 au flag ZF, sinon elle assigne la valeur 0 au flag ZF.
Exemple (a=1): CMP a 1 assigne la valeur 1 à ZF (ZF=1)

JE **SRC|IMM***
Si le flag ZF=1, cette instruction assigne la valeur SRC|IMM au régistre d'instruction (EIP), donc si ZF=1 la prochaine instruction est à l'indexe SRC|IMM, si ZF=0 la prochaine instruction reste la même.
Exemple (ZF=1): JE 3 la prochaine instruction devient l'index 3.

JNE **SRC|IMM***
Si le flag ZF=0, cette instruction assigne la valeur SRC|IMM au régistre d'instruction (EIP), donc si ZF=0 la prochaine instruction est à l'indexe SRC|IMM, si ZF=1 la prochaine instruction reste la même.
Exemple (ZF=1): JNE 3 la prochaine instruction reste la même.
```

La première instruction est à l'index 0 et la dernière est à l'index N-1. Comme précédemment, vous devez outputter les 4 régistres.

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

**Input**
```
7
MOV c 40
MOV a 10
ADD b 1
SUB c 2
CMP a b
JNE 2
XOR a a
```
**Output**
```
0
10
20
0
