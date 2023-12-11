# TPs d'AP3 2023-2024
MM. Fagnon, Lucarelli, Minich
1. Introduction
Les TP porteront sur la représentation d'expressions arithmétiques par des arbres syntaxiques.
 Exemple :
l'expression arithmétique 􏰀􏰁,􏰂 􏰃 peut être décrite / représentée / modélisée par l'arbre syntaxique 􏰄􏰅􏰆 (􏰇 􏰃)
 suivant :
 /
    *
sin
    13.6 x *
2x
   Les objectifs des 12 H de TP sont :
 de vous rappeler ce qu'est un Type Abstrait de Données (indépendance des traitements vis à vis de la structure
de données du TAD),
 de vous faire programmer et débugger,
 de vous faire pratiquer la compilation séparée,
 de vous faire pratiquer l'allocation dynamique de mémoire,
 de vous habituer à utiliser les versions sécurisées des fonctions d'entrées-sorties et de manipulation de chaînes
(printf_s, sprintf_s ...), pour lutter contre le piratage de vos logiciels,
 de faire un projet amusant (de mon point de vue ...). Dans votre cas, cela va consister à réaliser tous les outils
algorithmiques utiles à un traceur de courbes comme il y en a sur les calculettes. Vous n'aurez pas à vous préoccuper de la partie graphique (fenêtres de saisie, boutons, tracés ...). Elle sera fournie mais s'appuiera sur les outils algorithmiques que vous aurez développés et validés par avance.
Dans les expressions arithmétiques à modéliser :
 les fonctions sont représentées par une unique lettre : 's' pour sinus, 'c' pour cosinus, 't' pour tangente, 'r' pour
racine carrée, 'l' pour ln. Il n'y aura pas d'autres fonctions,
 les opérateurs binaires possibles sont : +, -, *, /.
2. La structure de données
Rappel du cours sur les arbres syntaxiques :
Il y a quatre types de noeuds. Nous appellerons ces 4 types Constante, Variable, Binaire, Fonction. Or, au S3, on sait seulement définir des arbres dont les noeuds ont tous le même type. Et pour que tous les nœuds aient même type, il n'y a pas d'autre choix que de conserver toutes les informations potentiellement utiles dans chaque nœud. Cela représente 5 informations :
 une valeur réelle (pour un noeud de type Constante) ;
 un caractère (pour un noeud de type Binaire ou Fonction) ;
 des pointeurs vers les deux fils éventuels (pour un noeud de type Binaire ou Fonction) ;
 une information supplémentaire qui indique quelle est la nature du nœud et, donc, lesquelles des infos
précédentes sont utiles. C'est la seule information qui est utile dans chaque nœud. Notons que pour un noeud de type Variable, aucune information complémentaire n'est utile car la variable est toujours nommée x.
La structure de données est donc (faites des copier/coller quand ce sera le moment de programmer et acceptez la normalisation des fins de lignes si elle vous est demandée) :
// Définition d'un type énuméré pour la nature du noeud
typedef enum {Constante,Variable,Binaire,Fonction} TNature ;
// Définition des types Nœud syntaxique et Arbre syntaxique.
// Le membre « nature » dit si le nœud est une constante, une variable etc etc ...
// Si le nœud est binaire, l'opérateur est dans OperOuFct et les deux fils dans fg et fd.
// Si le nœud est une fonction, le premier caractère du nom de la fonction est dans OperOuFct // et le fils est dans fg.
// Si le nœud est une constante, cette dernière est dans ValConst.
// Si le nœud est une variable, aucune autre info n'est utile.
typedef struct NoeudSynt { TNature double
Nature ;
ValConst ;
OperOuFct ;
*fg,*fd ;
3. Les primitives
char
struct NoeudSynt
}
TNoeudSynt, *TArbreSynt ;
Il s'agit de ce qu'on appellerait setters, getters, constructeurs, destructeurs en programmation objets. Au S3, on les appelle "primitives" de consultation, construction, modification et destruction. Voici la liste de celles qu'on utilise pour les arbres syntaxiques :
 PAS DE CONSTRUCTION D'UN ARBRE VIDE (ConsVide) : c'est inhabituel parce qu'avec tous les autres types
d'arbres, il y a une primitive de construction d'un arbre vide. Ce n'est pas le cas des arbres syntaxiques parce qu'une expression arithmétique ne peut pas être vide
 on n'a jamais besoin de tester si un arbre est vide. En effet : 1) la racine n'est jamais vide ; 2) si un noeud est une variable ou une constante, on sait qu'il n'a aucun fils ; 3) si un noeud est binaire, on sait qu'il a 2 fils non vides ; 4) si un noeud est une fonction, on sait qu'il n'a qu'un fils non vide et, par convention, c'est le gauche. Il n'y a donc pas de primitive "EstVide"
 il y a une construction par type de noeud, à la fois pour améliorer la lisibilité et pour réduire le nombre de paramètres (si on n'avait qu'un seul constructeur, il devrait avoir autant de paramètres qu'il y a de membres dans un noeud). On a donc :
TArbreSynt ConsVariable () ;

TArbreSynt TArbreSynt TArbreSynt
ConsConstante (double V) ;
ConsBinaire (char Op, TArbreSynt FG, TArbreSynt FD) ; ConsFonction (char Fct, TArbreSynt F) ;
Pour construire l'arbre correspondant à sin (ln (x + 12)), on écrirait : TArbreSynt A = ConsFonction ( 's',
ConsFonction ( 'l',
ConsBinaire ( '+',
 pour les consultations et la libération : // Primitives de consultation
TNature
double
char
TArbreSynt
TArbreSynt
char
TArbreSynt
Nature (TArbreSynt A)
ValeurConstante (TArbreSynt A)
Operateur (TArbreSynt A)
FG (TArbreSynt A)
FD (TArbreSynt A)
NomFonction (TArbreSynt A)
Argument (TArbreSynt A)
// Primitive de libération
void Liberer (TArbreSynt A)
La primitive Argument est la même que la primitive FG. On conserve quand même deux primitives pour le cas où la structure de données évoluerait. Par exemple, on pourrait choisir que l'argument d'un noeud de type Fonction doit désormais être le fils droit.
 les primitives de modification sont inutiles dans ce projet.
4. Vos tâches
Vous allez construire votre projet en partant de 0. Il contiendra 4 unités :
 ArbresSyntaxiques : type et primitives de création et consultation
 main
 divers (l'unité fourre-tout, dont une procédure d'affichage d'un message avec interruption éventuelle de
l'exécution)
 TraitementsArbresSyntaxiques : évaluation d'un arbre (d'une expression) en un x donné, dérivation d'une
expression, échantillonnage d'une courbe, transformation d'une expression sous forme d'une chaîne de caractères en un arbre syntaxique ...
Chaque unité est constituée d'un ".cpp" et d'un ".h" sauf "main.cpp", qui n'a pas de ".h". Laissez le suffixe ".cpp" sur les implémentations, bien que vous ne ferez que du C.
SI VOUS N'AVEZ JAMAIS PROGRAMME DE LA SORTE (c'est la compilation séparée), PARLEZ EN AU CHARGE DE TP.
Les tâches
 créer un projet vide en C++ (vous ne ferez que du C) dans le dossier "O:\L2\AP3\TP"
 dans ce dossier, créer un sous-dossier nommé "Les3Executables". Placez-y l'exécutable "TraceurCourbes.exe",
qui est dispo sur Arche.
ConsVariable (), ConsConstante (12)))) ;

 créer l'unité Divers (.cpp et .h). Pour cela :
- clic droit sur "Fichiers d'en-tête" / Ajouter/Nouvel élément/Fichier d'en-tête (.h), nommez le fichier
"Divers.h" et choisissez le dossier du projet ("O:\L2\AP3\TP"). Validez.
- clic droit sur "Fichiers sources" / Ajouter/Nouvel élément/Fichier source (.cpp), nommez le fichier
"Divers.cpp" et choisissez le dossier du projet ("O:\L2\AP3\TP"). Validez.
- Dans cette unité, placer une procédure dont les entrées sont un message et un booléen disant s'il faut
interrompre l'exécution après affichage du message :
void AfficherMessage(const char msg[], bool InterrompreExec)
Cette procédure affiche le message, fait une pause pour que l'utilisateur ait le temps de voir le message et, si le booléen le demande, interrompt l'exécution.
 mettre
"Projet/Propriétés/Propriétés de configuration/C-C++" puis, dans la fenêtre de droite : "Niveau d'avertissement - -> Niveau 4")
un niveau d'avertissements élevé (sous Visual Studio : choisir le niveau 4avec le menu
 compiler l'unité (<CTRL F7> sous VS) et retoucher jusqu'à la disparition de toute erreur et tout warning. Ne pas faire d'édition des liens (Build/construire la solution) puisqu'il n'y a pas encore de fonction main ;
 télécharger "main.cpp" depuis Arche ; ce fichier contient la fonction "main" dans laquelle il faudra retirer/ajouter des commentaires au fur et à mesure de votre progression.
Décommenter les appels à AfficherMessage , comprenez les.
Faites une génération de l'exécutable (<CTRL B>, B comme "Build") et, s'il n'y a ni warning ni erreur, tester ("Déboguer/Démarrer le débogage ou F5).
 créer et programmer l'unité ArbresSyntaxiques (.cpp et .h). Elle déclare le type TArbreSyntaxique, les primitives et rend tout cela accessible au reste du programme. Compiler et retoucher jusqu'à la disparition de toute erreur et tout warning ;
Attention : vous allez copier les types et les entêtes des primitives depuis ce fichier (un fichier "pdf") vers votre projet. Quand ce sera fait, il se peut que les codages des fins de ligne et de divers caractères spéciaux du fichier "pdf" ne soient pas compatibles avec le codage sous votre environnement. Il est conseillé, une fois les copier/coller faits, de quitter et redémarrer votre EDI. On devrait vous proposer d'adapter les codages : acceptez.
 dans la fonction "main", libérer et comprendre les instructions pour créer l'arbre syntaxique de l'expression : "1 + sin (ln (10*x))". Cet arbre sera utilisé plus tard, une fois que l'étape suivante aura été réalisée ;
 créer l'unité TraitementsArbresSyntaxiques (.cpp et .h) et y rédiger la fonction d'évaluation d'un AS en un x donné. Compiler et retoucher jusqu'à la disparition de toute erreur et tout warning ;
 supprimer les appels à AfficherMessage dans main ;
 dans la fonction "main", libérer les instructions pour évaluer l'arbre en plusieurs x différents. Compilation jusqu'à disparition des avertissements et erreurs, édition des liens (idem), exécution, le tout jusqu'au bon fonctionnement.

 Ajouter à l'unité "TraitementsArbresSyntaxiques" la fonction qui convertit l'expression décrite par un arbre syntaxique en une chaîne de caractères. Par exemple, pour l'arbre créé au début de la fonction main, on doit obtenir :
"1.000+s(l(10.000*x))"
(le nombre de décimales pour les constantes réelles est sans importance, laissez le nombre par défaut).
Les conventions pour construire la chaîne sont les suivantes :
 toute lettre autre que x est un nom de fonction ;
 pour un noeud de type variable, la chaîne est "x" ;
 pour un noeud de type constante, la chaîne est obtenue en transformant la valeur de la constante en
une chaîne (utiliser sprintf_s) ;
 pour un noeud de type fonction, la chaîne est obtenue en concaténant le nom de la fonction (une seule
lettre), une parenthèse ouvrante, la chaîne obtenue à partir de l'argument et une parenthèse fermante ;
 pour une opération binaire, la chaîne de caractères est obtenue en concaténant la chaîne obtenue à
partir du fils gauche, l'opérateur situé dans la racine et la chaîne obtenue à partir du fils droit.
Exception : quand un fils est lui même un noeud binaire, la chaîne qui lui correspond doit être entourée
de parenthèses avant d'être concaténée ;
Exemples :
 (x+22)*(3+x)
 s(x+3)
 s((x+22)*(3+x))  s(c(x+1))
 dans la fonction "main", pour vérifier le bon fonctionnement de ArbreEnChaine, décommenter la première partie de la "cinquième version du main". Compilation jusque disparition des avertissements et erreurs, édition des liens (idem), exécution, le tout jusqu'au bon fonctionnement.
 réaliser un module de calcul de la dérivée d'une fonction de x. Vous devriez constater le besoin de programmer un autre module.
 dans le main, ajouter les tests de la deuxième partie de la "cinquième version du main". Comprenez bien les libérations qui sont réalisées.
 Travail personnel (nécessaire pour finir le TP) : réalisez une fonction de création aléatoire d'un arbre syntaxique d'une hauteur donnée H (la hauteur est le nombre de noeuds de la racine à la feuille la plus éloignée). On suppose que la hauteur fournie est ≥ 1. Choisissez judicieusement l'unité dans laquelle vous placerez cette fonction.
Ce type de module est utile pour produire de très nombreux arbres et, ainsi, faire des tests sérieux portant sur des millions d'arbres.
Indications :
o quand H = 1, donc quand l'arbre est réduit à une feuille, choisissez aléatoirement entre une constante et une variable
o pour les constantes, choisissez aléatoirement un entier dans [0, 19].
o quand H > 1, choisissez aléatoirement la racine parmi Binaire et Fonction.
o pour une fonction, choisir son nom dans {'s', 'c', 't', 'r', 'l'} et construisez récursivement son fils d'une
hauteur H-1

o pour un arbre binaire, c'est semblable ; les deux fils n'ont cependant pas l'obligation d'avoir tous les deux une hauteur de H-1.
 Travail personnel (nécessaire pour finir le TP) : réalisez ensuite une fonction de comparaison de deux arbres syntaxiques. Son résultat est vrai si et seulement si les arbres sont strictement égaux (même noeuds aux mêmes endroits et avec les mêmes paramètres (valeur de la constante, caractère de la fonction ...).
Testez plusieurs fois votre fonction dans le main, en créant deux fois le même arbre et en comparant les deux arbres ; ou bien en construisant manuellement (avec des ConsVariable, ConsBinaire ...) la dérivée de l'arbre de la fonction main et en le comparant à la dérivée obtenue avec la fonction de dérivation.
 réalisez ensuite une fonction de conversion d'une chaîne de caractères respectant les conventions énoncées plus haut en l'arbre syntaxique qui la décrit.
Cette fonction est compliquée parce que certaines opérations binaires ne sont pas parenthésées. Ecoutez bien les explications de l'enseignant.
 décommentez dans main la boucle qui fonctionne un million de fois (seulement 5 fois au premier essai). Une itération consiste :
o en la création aléatoire d'un arbre syntaxique dont la hauteur est tirée aléatoirement entre 1 et 10, o en sa transformation en chaîne,
o en la conversion de cette chaîne en arbre et
o en la comparaison des deux arbres (ils doivent être égaux).
Après la boucle, une phrase fait le bilan de ces essais ("Le test sur 1 000 000 d'arbres s'est bien passé" ou bien "Le test sur 1 000 000 d'arbres a échoué ... fois").
 Créer un module dont les entrées sont une chaîne de caractères Ch décrivant une fonction respectant les conventions données plus haut, deux réels min et max (min < max), un entier NbPoints et un nom de fichier NF. Cette fonction doit calculer NbPoints points sur la courbe. Le premier et le dernier points sont ceux d'abscisses min et max et les NbPoints - 2 autres points sont à des abscisses régulièrement espacées de min à max.
Les points doivent être déposés dans un fichier texte nommé NF ; la syntaxe du fichier est la suivante :
 la première ligne contient le nombre de points
 la deuxième ligne contient les x et les y des points, séparés par des espaces.
Vous avez un exemple de ce fichier sur Arche (PointsDeLaCourbe.txt).
5. Dernière étape
Cette dernière étape consiste à adapter votre programme pour produire deux exécutables nécessaires au programme graphique. Le premier exécutable, qui doit se nommer " Echantillonneur.exe " doit permettre de taper une commande système ayant l'aspect suivant :
Echantillonneur.exe x*s(2*x) -7,0 7,8 200 PointsDeLaCourbe.txt
Ce qui signifie : exécuter le programme " Echantillonneur.exe " sur la fonction " x*s(2*x)" de manière à calculer 200 points sur la courbe, régulièrement répartis de x = -7.0 à x = 7.8 et déposer ces points dans le fichier
" PointsDeLaCourbe.txt ".

Le deuxième exécutable, qui doit se nommer " CalculVecteurTangent.exe " doit permettre de taper une commande ayant l'aspect suivant :
CalculVecteurTangent.exe x*s(2*x) 2.8 OrdonneeVecteurTangent.txt
Ce qui signifie : exécuter le programme " CalculVecteurTangent.exe " sur la fonction " x*s(2*x)" de manière à calculer l'ordonnée d'un vecteur d'abscisse 1 tangent à la courbe en x = 2.8 et déposer l'ordonnée calculée dans le fichier " OrdonneeVecteurTangent.txt".
 mettre la totalité du corps de votre fonction main en commentaire. Retirer les commentaires dans les paramètres de la fonction main. Les deux paramètres sont le nombre de termes sur la ligne de commande et un tableau de chaînes de caractères qui représentent les termes de la ligne de commande :
int main (int NbTermesLigneDeCommande, char *TabTermes[]) ...
 libérer la septième version du main :
// Corps pour le premier exécutable à produire : échantillonnage d'une courbe if ()
...
Echantillonner(TabTermes [1], xmin, xmax, NbPoints, TabTermes [5]);
// A la place de "Echantillonner", utilisez le nom de votre procédure d'échantillonnage. }
 compilez, liez
 trouvez l'exécutable, dupliquez-le, renommez la copie " Echantillonneur.exe" et placez la dans le dossier nommé
"Les3Executables".
 mettez en commentaire le corps de votre fonction "main" et libérez la huitième version du main.
Générez, trouvez l'exécutable, dupliquez-le, renommez la copie " CalculVecteurTangent.exe" et placez la dans "Les3Executables".
 Dans le dossier "Les3Executables", démarrez "TraceurCourbes.exe" et notez bien que :
 lorsque vous saisissez des nombres avec partie décimale dans les fenêtres de saisie, il faut utiliser la virgule ;
 quand vous saisissez une fonction qui contient des constantes réelles à virgule, il faut utiliser le point.
 Familiarisez-vous avec l'interface et demandez à tracer les courbes des fonctions de votre choix et des vecteurs tangents. Attention : les vecteurs tangents apparaissent sous la forme de segments verts assez peu visibles.