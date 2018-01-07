# Emprunte d'un texte
Ce texte peut parraître ordinaire, mais il ne l'ai pas. Il est possible de cacher
des caractères invisible à l'oeil humain, mais qui seront garder suite à un 
copier coller.

Voici un exemple de cractères semblables. Cette chaîne de cractères «je suis une
ch𝚊îne» et «je suis une chaîne» peut sembler être les mêmes, mais ce n'est pas
le cas. La première chaîne utilise un petit `a` mathématique monospace plutôt
qu'un `a` traditionnel. Il est possible que votre police de caractères les ait
affiché différement, mais ce n'est pas le cas pour toutes les polices de
caractères. Voici une [liste de caractères problématiques.](http://www.unicode.org/Public/security/latest/confusables.txt).

Il est aussi possible d'utiliser des
[espaces sans chasse](https://fr.wikipedia.org/wiki/Espace_sans_chasse) qui sont
des caractères n'affichant rien. Il devient ainsi impossible de distinguer ces
caractères à l'oeil nue.

## Défi
Il vous est demandé d'écrire un programme qui prend en entré une chaîne de
caractères et retourne une chaîne ne contenant aucun caractère pouvant porter à
confusion. Pour une raison de simplicité, ce défi utilisera des textes anglais.
