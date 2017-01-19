# Tutoriel
## Sélection des CS Games
Bienvenu aux sélections des CS Games. Dans cette compétition, vous aurez à coder des scripts en [python 2.7](https://www.python.org/downloads/release/python-2713/) et [javascript (nodejs v4.2.0)](https://nodejs.org/en/blog/release/v4.2.0/) et à trouver des flags.

## Le but
Votre but est de résoudre le plus de challenges possibles pour obtenir un maximum de force!
Chaque challenge dispose d'un nombre de force différent dépendemment de la difficulté du challenge.

![alt text](https://raw.githubusercontent.com/carapas/CSGamesSelectionPublic/master/force.png?token=AEjGqx5J_Qeapc7dPXs_OE9rb82BrLaMks5Yfi7hwA "Force")

## Comment ça marche?
Les défis de programmation sont de type stdin et stdout. C'est à dire que vous lirez les inputs à partir des entrées de la console et que vous envoierez les résultats de vos algorithmes par stdout.

### stdin
**python**
```
input1 = raw_input()
input2 = raw_input()
```

**javascript**
```
var fs = require('fs');
var response = fs.readSync(process.stdin.fd, 10000, 0, "utf8");
var lines__ = response[0].split('\r\n');
var idx__ = 0;

var readline = () => {
    idx__++;
    return lines__[idx__-1];
};

var input1 = readline();
var input2 = readline();
```

### stdout
**python**
```
print 'Résultat'
```

**javascript**
```
console.log('Résultat');
```

## Tutoriel
Pour finir ce tutoriel, vous n'avez qu'à printer `J'ai compris!`.
#Bonne chance et que la force soit avec vous!