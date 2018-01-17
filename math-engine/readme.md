# L'engin de mathématique
## Le but
En tant que super ninja guru full-stack pirate software engineer, vous décidez de faire un API REST qui agit comme une calculatrice. Vous pourrez y envoyer des requêtes avec des objets JSON et l'API devra retourner la réponse de l'opération.

Le format des requêtes a déjà été établi par un collègue qui n'avait vraisemblablement aucune idée comment faire des objets JSON. Malgré votre rage intérieure, vous calculez qu'il prendra moins de temps faire l'API avec un format qui laisse à désirer que de le faire changer dans le front-end.

## Règles
Comme toute calculatrice qui se respecte, votre API devra respecter les règles de mathématiques standard.

`+: additionne des chiffres`

`-: soustrait des chiffres`

`/: divise des chiffres`

`*: multiplie des chiffres`

`(): priorité d'opération`

Voici le format des objets JSON:
```
{
  operators: [
	{
		type: 'string' || 'number',
		content: '+' || '-' || '/' || '*' || '(' || ')' || 12355224637547 (chiffre quelconque)
		position: chiffre représentant la position du chiffre ou de l'opérateur dans l'équation mathématique (débute à 0)
	},
	{
		type: 'string' || 'number',
		content: '+' || '-' || '/' || '*' || '(' || ')' || 12355224637547 (chiffre quelconque)
		position: chiffre représentant la position du chiffre ou de l'opérateur dans l'équation mathématique (débute à 0)
	} ...
  ]
}
```

## Interaction avec la plateforme
### Inputs
**Ligne 1**: Le JSON.

### Output
Vous devez sortir le résultat de l'équation sur la sortie standard (_stdout_).

### Exemple
**Input** (en une ligne; cet exemple est formatté pour vos yeux et les miens)
```
{
  operators: [
	{
		type: 'number',
		content: 1,
		position: 0
	},
	{
		type: 'number',
		content: 2,
		position: 2
	},
	{
		type: 'string',
		content: '+',
		position: 1
	}
  ]
}
```
**Output**
```
3
```
