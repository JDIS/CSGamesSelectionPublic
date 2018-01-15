# Emprunte d'un texte
Ce texte peut sembler ordinaire, mais en réalité il ne l'est pas. Il est possible de cacher
des caractères invisible à l'oeil nu, mais qui sont conservés dans un 
copier-coller, par exemple.

Voici un exemple de caractères semblables. La chaîne de caractères «je suis une
ch𝚊îne» et «je suis une chaîne» peuvent sembler être identiques, mais ce n'est pas
le cas. La première chaîne utilise un petit `a` mathématique de type _monospace_ plutôt
qu'un véritable `a` traditionnel. Il est possible que votre police de caractères ait affiché les caractères différement, mais ce n'est pas le cas pour toutes les polices de
caractères. Consultez cette [liste de caractères problématiques](http://www.unicode.org/Public/security/latest/confusables.txt) pour des exemples supplémentaires.

Il est aussi possible d'utiliser des
[espaces sans chasse](https://fr.wikipedia.org/wiki/Espace_sans_chasse), qui sont
des caractères n'affichant rien. Il devient ainsi impossible de distinguer ces
caractères à l'oeil nu.

## Défi
Il vous est demandé d'écrire un programme qui prend en entrée une chaîne de
caractères et retourne une chaîne ne contenant aucun caractère pouvant porter à
confusion. Pour des raisons de simplicité, ce défi utilisera des textes en anglais.
