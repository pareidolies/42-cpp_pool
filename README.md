# 42-cpp_pool

Juste quelques notes et conseils

Makefile cpp : https://www.hiroom2.com/2016/09/03/makefile-header-dependencies/

## Module 00:

**Ex00 :** 
* pas de piège sur cet exercice

**Ex01 :** 
* que se passe-t-il si vous faites ctrl-D dans le prompt (au moment de l'écriture de la commande ADD, SEARCH ou EXIT, et au moment de l'indication de l'index du contact à chercher) ?
* que se passe-t-il si vous rentrez un champ vide ("") quand vous ajoutez un nouveau contact ?

**Ex02 :** 
* le script sh (qui n'est pas à rendre pour l'évaluation) permet de comparer le fichier log avec votre propre rendu en supprimant la colonne des timestamps grâce à awk.
* le fichier visuel.pdf permet de mieux repérer visuellement l'appel des différentes fonctions dans le fichier tests.cpp.

## Module 01:

Sur les pointeurs et les références : https://cpp.developpez.com/cours/cpp/?page=page_6

## Module 02:

**Ex01 :** 

* sur les nombres à virgule fixe : https://msxvillage.fr/wiki/nombre-a-virgule-fixe et https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html
* attention aux casts qui tronquent les valeurs, il faudra penser à utiliser roundf

**Ex02 :** 

* sur la surcharge des opérateurs : http://casteyde.christian.free.fr/cpp/cours/online/x3244.html
* pour la décrémentation et l'incrémentation, la valeur n'est pas 1 mais 1/256 car nous manipulons des nombres à virgule fixe

**Ex03 :** 

* détecter si un point se situe à l'intérieur d'un triangle : https://www.youtube.com/watch?v=kkucCUlyIUE
* pour visualiser les tests sur un graphe : https://www.geogebra.org/?lang=fr

## Module 03:

**Les mots-clés concernant l'héritage :**
- public/private/**protected**
- using
- virtual

**Ex03 :**

Pour eviter que le sous-objet ClapTrap soit cree plusieurs fois : https://www.ljll.math.upmc.fr/courscpp/Sections/Sect08-E3.html

**En plus :** -Wshadow : Warn whenever a local variable or type declaration shadows another variable, parameter, type, class member (in C++), or instance variable (in Objective-C) or whenever a built-in function is shadowed. Note that in C++, the compiler warns if a local variable shadows an explicit typedef, but not if it shadows a struct/class/enum. If this warning is enabled, it includes also all instances of local shadowing. This means that -Wno-shadow=local and -Wno-shadow=compatible-local are ignored when -Wshadow is used. Same as -Wshadow=global.

## Module 04 : 

**Ex01 :** 

Sur la différence entre copie profonde et superficielle : https://fr.wikipedia.org/wiki/Copie_d%27un_objet
http://www-igm.univ-mlv.fr/~dr/CPP/TransparantsC++6.pdf

**Ex02 :**

Sur les classes abstraites et les méthodes virtuelles pures : https://fr.wikipedia.org/wiki/Classe_abstraite

## Module 05 :

Shrubbery ascii art credit : https://ascii.co.uk/art/tree

## Module 06 :

Sur les differents types de cast : https://zestedesavoir.com/tutoriels/553/les-conversions-de-types-en-c/

## Module 08 :

http://tvaira.free.fr/dev/cours/cours-conteneurs-stl.pdf

## Module 09 :

https://en.wikipedia.org/wiki/Reverse_Polish_notation

## General :

https://github.com/hugorclt/PiscineCPP


