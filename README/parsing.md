
# Redirection

`> >> < |`

## `<`
Precede ce qu elle redirectionne (fichier ou commande)

## `>`
Succede ce qu elle redirectionne (fichier ou commande)
Fait pour ecrire dans un fichier
Efface le fichier, puis ecris dedans.

## `>>`
Succede ce qu elle redirectionne (fichier ou commande)
Fait pour ecrire dans un fichier
Ecris a partir du EOF dans le fichier


# character d echapement
`'\'` char d'echapement : ecrit le char qui le suit et disparait. Le char ecrit perd ses propoprietes speciales s'il en avait.
char ayant des proprietes speciales:

```
<
>
>>
"
\
$
;
```


# Les `""`

Ils doivent etre paire dans une ligne
Les `""` ont la priorite sur les pipe

# command not found $?=127

Deux variable dans le meme mot en $0

`..`
`''`
`""`

# Variables d environnement

## vocabulaire

assignation : yolo=3
expend : $yolo --> 3
---

L'assignation se fait uniquement s'il n'y a pas d'executable dans la commande. S'il y a un executable l'assignation est ignoree.

# Etapes de parsing


## 1/ les `''`

les expention se font dans une recursion paire de `''` 
=> `''$HOME''` --> `/home/user42`
En cas de recursion impaire, il faut placer un `\` devant le `$` avant de retirer les `''`
=> `'''$HOME'''` --> `\$HOME`

## 2/ les `""`

constituer les mots entre `""`













