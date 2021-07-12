
blanc = `' ' \t`

mot = sequence de charactere (token)

nom (identificateur) = mot ne comportant que des characteres alphanumeriques ou le underscore

meta-charactere = charactere separant deux mots
`| & ; ( ) < > ' ' \t`

operateeur de controle = jeton ayant une fonction de controle
`|| & && ; ;; ( ) | \r`

mots reserves = ont une signification particuliere pour le shell, ils sont interpretes differemments
`! case do done elif else esac fi for function if in select then until while { } time [[ ]]`
# Redirection

Sortie standard : fd = 1 --> `>` permet de la rediriger

Entree standard : fd = 0 --> `<` permet de la rediriger

Sortie d'erreur : fd = -1

pipeline => `commande_1 | commande_2`
Redirige la sortie standard de `commande_1` vers l'entree standard de `command_2`
stdout de `commande_1` remplace stdin de `commande_2`

`>`		-- $1 stdout => $2 stdin (remplace ce qui est ecrit dans le fichier)
`>>`	-- $1 stdout => $2 stdin (ecrit a la suite de ce qui est ecrit dans le fichier)
`<`		-- $2 stdin => stdout $1
`X>`	-- $1 fd = X => $2 stdin (remplace ce qui est ecrit dans le fichier)
`X>>`	-- $1 fd = X => $2 stdin (ecrit a la suite de ce qui est ecrit dans le fichier)
`X>&Y	-- $1 fd = X => $1 fd = Y
`X>>&Y	-- $1 fd = X => $1 fd = Y
# return value

## comande simple


# execution d'une commande

1 / il recherche '/' "/" pour savoir si c est un chemin. Si oui, il verifie avec lstat si c est un executable
	il recherche les redirections et les memorises pour les executer plus tard

2 / il regarde si c est un builtin (fonction interne)

3 / il developpe les mots (pas besoin dans minishell)

4 / 



# Bibliographie

## redirection fd
https://putaindecode.io/articles/maitriser-les-redirections-shell/

## man bash
http://manpagesfr.free.fr/man/man1/bash.1.html
