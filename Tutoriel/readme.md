# Tutoriel
## Sélection des CS Games
Bienvenu aux sélections des CS Games. Dans cette compétition, vous aurez à coder des scripts en [python 2.7](https://www.python.org/downloads/release/python-2713/) et [javascript (nodejs v9.3.0)](https://nodejs.org/en/blog/release/v9.3.0/) et à trouver des flags.

## Le but
Votre but est de résoudre le plus de challenges possibles pour obtenir un maximum de force!
Chaque challenge dispose d'un nombre de force différent dépendemment de la difficulté du challenge.

![alt text](https://raw.githubusercontent.com/JDIS/CSGamesSelectionPublic/master/force.png "Force")

## Comment ça marche?
Les défis de programmation sont de type stdin et stdout. C'est à dire que vous lirez les inputs à partir des entrées de la console et que vous envoierez les résultats de vos algorithmes par stdout.

## Tester localement (**Extremement utile**)
Vous avez accès à un script utilitaire qui agit exactement comme le serveur. Le [Validator](https://github.com/JDIS/CSGamesSelectionPublic/tree/master/Validator) vous permet de tester les challenges que vous voulez localement. Pour ce faire, vous devez lui fournir un script et fichier de test comme [celui-ci](https://github.com/JDIS/CSGamesSelectionPublic/blob/master/Tutoriel/tutoriel.json).

Tous les fichiers sont disponible sur le [github publique des sélections](https://github.com/JDIS/CSGamesSelectionPublic).

### stdin
**python**
```
input1 = raw_input()
input2 = raw_input()
```

**javascript**
```
var readline = require(\"./readline.js\");

var input1 = readline();
var input2 = readline();
```

### stdout
**python**
```
print 'Resultat'
```

**javascript**
```
console.log('Resultat');
```

## Tutoriel
Pour finir ce tutoriel, vous n'avez qu'à printer `J'ai compris!`.

# Bonne chance et que la force soit avec vous!
