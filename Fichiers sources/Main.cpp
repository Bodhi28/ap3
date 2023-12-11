#include <stdio.h>					// Pour sprintf_s
#include <stdlib.h>					// Pour system ()
#include <math.h>					// Pour sin, cos ...
#include "Divers.h"					// Pour AfficherMessage
//#include "ArbresSyntaxiques.h"
//#include "TraitementsArbresSyntaxiques.h"
#include <iostream>

int main(/*int NbTermesLigneDeCommande, char *TabTermes[]*/)
{
	/*
	// PREMIERE VERSION DU MAIN
	// Essais de la fonction AfficherMessage. A retirer avant de commencer l'unité "ArbresSyntaxiques"
	AfficherMessage("Voici un premier message", false);

	char MSG[100];
	sprintf_s(MSG, 100, "Saviez vous que %d + %d font %d ?", 3, 7, 3 + 7);
	AfficherMessage(MSG, false);

	AfficherMessage("Troisieme et dernier message", true);

	AfficherMessage("Quatrieme message, jamais affiché", false);
	*/

	/*
	// DEUXIEME VERSION DU MAIN
	// Ce qui suit doit être fait une fois que l'unité "ArbresSyntaxiques" a été réalisée et compilée avec succès.
	// Supprimer les tests de AfficherMessage
	// Construction de l'arbre syntaxique de l'expression : 1 + sin (ln (10*x))
	TArbreSynt  A = ConsBinaire (	'+', 
									ConsConstante(1),
									ConsFonction(	's', 
													ConsFonction (	'l', 
																	ConsBinaire (	'*', 
																					ConsConstante(10),
																					ConsVariable()))));
	*/

	/*
	// TROISIEME VERSION DU MAIN
	// Ce qui suit ne doit être fait qu'une fois l'unité "TraitementsArbresSyntaxiques" réalisée.
	// Affichage de la valeur de l'expression en plusieurs x
	double x;

	x = 1;
	printf_s ("En %lf, l'expression devrait valoir %lf et vaut %lf\n", x, 1 + sin(log(10 * x)), Evaluation(A, x));

	x = 10;
	printf_s("En %lf, l'expression devrait valoir %lf et vaut %lf\n", x, 1 + sin(log(10 * x)), Evaluation(A, x));

	x = 100;
	printf_s("En %lf, l'expression devrait valoir %lf et vaut %lf\n", x, 1 + sin(log(10 * x)), Evaluation(A, x));
	*/

	/*
	// QUATRIEME VERSION DU MAIN
	// Ce qui suit ne doit être fait qu'une fois la conversion arbre en chaîne réalisée.

	char* Ch = ArbreEnChaine(A);

	printf_s("La conversion de l'arbre en chaine devrait donner 1 + s(l(10*x)) et donne %s\n", Ch);
	free(Ch);
	*/

	/*
	// CINQUIEME VERSION DU MAIN
	TArbreSynt DerivA = Derivation(A);
	Ch = ArbreEnChaine(DerivA);

	printf_s("La derivee de 1 + s(l(10*x)) est %s\n", Ch);
	free(Ch); LibererArbreSynt(DerivA);
	*/

	/*
	// SIXIEME VERSION DU MAIN : TEST DE ChaineEnArbre
	int HauteurMaxDesArbres = 10,
		NbEchecs = 0;

	for (int NbTests = 1; NbTests <= 1000000; NbTests++) {
		// Création d'un arbre aléatoire
		int HauteurArbreCourant = 1 + rand() % HauteurMaxDesArbres;
		TArbreSynt A1 = CreerArbreAleatoire(HauteurArbreCourant);

		// Conversion de l'arbre courant en chaîne
		char* Chaine = ArbreEnChaine(A1);
		//printf("L'arbre aleatoire de hauteur %d est %s\n", HauteurArbreCourant, Chaine);

		// Conversion de la chaîne en un arbre
		TArbreSynt A2;
		int Fin;
		ChaineEnArbre(Chaine, 0, &A2, &Fin);

		// Comparaison des 2 arbres : ils doivent être égaux si tout marche bien.
		if (!ArbresSyntEgaux(A1, A2)) {
			printf_s("Tout va mal pour ChaineEnArbre sur cet arbre :\n%s\n", Chaine);
			free(Chaine);
			NbEchecs++;
		}

		//else {
		//	printf_s("Tout va bien pour ChaineEnArbre sur cet arbre : \n%s\n", Chaine);
		//	free(Chaine);
		//}

		LibererArbreSynt(A1);
		LibererArbreSynt(A2);
	}
	if (NbEchecs > 0)
		printf_s("Le long test a echoue %d fois\n", NbEchecs);
	else
		printf_s("Le long test a bien fonctionne\n");
	*/


	/*
	// SEPTIEME VERSION DU MAIN : Corps pour le premier exécutable à produire : échantillonage d'une courbe
	if (NbTermesLigneDeCommande != 6) {
		char MSG[1000];

		sprintf_s(MSG, "La ligne de commande de l'echantillonneur est fausse\nIl y a %d termes au lieu de 6 :", NbTermesLigneDeCommande);
		AfficherMessage(MSG, true);
	}
	else {
		double xmin, xmax;
		int NbPoints;

		xmin = atof(TabTermes[2]);
		xmax = atof(TabTermes[3]);
		NbPoints = atoi(TabTermes[4]);
		Echantillonner(TabTermes [1], xmin, xmax, NbPoints, TabTermes [5]);
	}
	*/

	/*
	// HUITIEME VERSION DU MAIN : corps pour le deuxième exécutable à produire : calcul de l'ordonnée en un X donné et de l'ordonnée
	// d'un vecteur tangent d'abscisse 1

	if (NbTermesLigneDeCommande != 4) {
		char MSG[1000];

		sprintf_s(MSG, "La ligne de commande du calculeur de tangente est fausse\nIl y a %d termes au lieu de 4 :", NbTermesLigneDeCommande);
		AfficherMessage(MSG, true);
	}
	else {
		double x = atof(TabTermes[2]);

		TArbreSynt A;
		int i;
		ChaineEnArbre(TabTermes[1], 0, &A, &i);
		double y = Evaluation(A, x);
		TArbreSynt DA = Derivation(A);
		LibererArbreSynt(A);
		double ytgt = Evaluation(DA, x);
		LibererArbreSynt(DA);

		FILE* Fichier;

		if ((0 == fopen_s(&Fichier, TabTermes[3], "wt")) && (Fichier != NULL)) {
			fprintf_s(Fichier, "%lf %lf", y, ytgt);
			fclose(Fichier);
		}
	}
	*/
}