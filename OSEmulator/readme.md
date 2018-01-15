# OSEmulator
Nous sommes en l'an 2100 (oui, le temps passe vite). Vous êtes ingénieur informatique. Un de vos collègues vous amène un ancien jeu PC. Vous enlevez la poussière sur le disque et vous rendez compte que c'est un CD du jeu Diablo; vous y avez tellement joué quand vous étiez plus jeune que la nostalgie l'emporte : vous devez absolument rejouer à ce jeu!

Malheureusement, il n'existe plus de PC qui fonctionne sur l'architecture de processeur x86 (une antiquité datant de plus d'un siècle). Vous décidez donc d'écrire un émulateur x86 pour pouvoir jouer à Diablo.

## Règles
Votre émulateur devra contenir les registres suivants : `a`, `b`, `c`, `d`.

**Ces registres sont initialisés à 0 au début de l'exécution.**

Voici la liste des instructions à implémenter pour y arriver:
```
Terminologie
IMM: Valeur entière. e.g: 1,2,3,4,5,6
SRC: Registre utilisé dans une opération. e.g: a,b,c,d
DEST: Registre utilisé dans une opération et registre de stockage du résultat. e.g: a,b,c,d
```

```
MOV **DEST** **SRC|IMM**
Copie le registre ou la valeur entière dans le registre DEST.
Exemple: MOV a 3 Équivalent à (a=3)
```

```
ADD **DEST** **SRC|IMM**
Ajoute le registre ou la valeur entière dans le registre DEST.
Exemple: ADD a 3 Équivalent à (a+=3)
```

```
SUB **DEST** **SRC|IMM**
Soustrait le registre ou la valeur entière du registre DEST.
Exemple: SUB a 3 Équivalent à (a-=3)
```

```
XOR **DEST** **SRC|IMM**
Xor le registre ou la valeur entière avec le registre DEST.
Exemple: XOR a 3 Équivalent à (a^=3)
```

À la fin des instructions, vous devrez imprimer (_print_) tous les registres en commençant par le registre `a` et en finissant par `d`.

À l'aide de ces instructions vous pourrez compléter la première partie du défi et donc obtenir 4 points. Implémentez les instructions de la 2e partie du défi pour obtenir les 4 autres points :

```
Terminologie
REG: registre utilisé dans une opération. e.g: a,b,c,d
IMM: Valeur entière. e.g: 1,2,3,4,5,6
SRC: registre utilisé dans une opération. e.g: a,b,c,d
```

```
CMP **REG** **SRC|IMM**
Compare le registre REG avec SRC|IMM, si les deux sont égaux l'opération assigne la valeur 1 au flag ZF, sinon elle assigne la valeur 0 au flag ZF.
Exemple (a=1): CMP a 1 assigne la valeur 1 à ZF (ZF=1)

JE **SRC|IMM***
Si le flag ZF=1, cette instruction assigne la valeur SRC|IMM au registre d'instruction (EIP), donc si ZF=1 la prochaine instruction est à l'indexe SRC|IMM, si ZF=0 la prochaine instruction reste la même.
Exemple (ZF=1): JE 3 la prochaine instruction devient l'index 3.

JNE **SRC|IMM***
Si le flag ZF=0, cette instruction assigne la valeur SRC|IMM au registre d'instruction (EIP), donc si ZF=0 la prochaine instruction est à l'indexe SRC|IMM, si ZF=1 la prochaine instruction reste la même.
Exemple (ZF=1): JNE 3 la prochaine instruction reste la même.
```

La première instruction est à l'index 0 et la dernière est à l'index N-1. Comme précédemment, vous devez output les 4 registres.

## Interaction avec la plateforme
### Inputs
**Ligne 1**: Le nombre d'instructions `N`.
**Ligne N**: Les instructions à exécuter.

### Output
Vous devez sortir les registres à la fin de l'exécution sur la sortie standard (_stdout_)
**Ligne 1**: Le registre a.
**Ligne 2**: Le registre b.
**Ligne 3**: Le registre c.
**Ligne 4**: Le registre d.

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
```
