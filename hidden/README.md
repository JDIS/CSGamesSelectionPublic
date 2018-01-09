# Emprunte d'un texte
Ce texte peut paraître ordinaire, mais il ne l'est pas. Il est possible de cacher
des caractères invisibles à l'oeil humain, mais qui seront gardés suite à un 
copier-coller.

Voici un exemple de cractères semblables. Ces chaînes de cractères «je suis une
ch𝚊îne» et «je suis une chaîne» peuvent sembler être les mêmes, mais ce n'est pas
le cas. La première chaîne utilise un petit `a` mathématique monospace plutôt
qu'un `a` traditionnel. Il est possible que votre police de caractères les ait
affichés différement, mais ce n'est pas le cas pour toutes les polices de
caractères. Voici une [liste de caractères problématiques.](http://www.unicode.org/Public/security/latest/confusables.txt).

Il est aussi possible d'utiliser des
[espaces sans chasse](https://fr.wikipedia.org/wiki/Espace_sans_chasse) qui sont
des caractères n'affichant rien. Il devient ainsi impossible de distinguer ces
caractères à l'oeil nu.

## Défi
Il vous est demandé d'écrire un programme qui prend en entrée une chaîne de
caractères et retourne une chaîne ne contenant aucun caractère pouvant porter à
confusion. Pour une raison de simplicité, ce défi utilisera des textes anglais.
