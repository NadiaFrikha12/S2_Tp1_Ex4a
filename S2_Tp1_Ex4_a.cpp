//Ecrire un programme qui �limine les r�p�titions d�espaces dans un fichier texte.
//Dans des traitements ind�pendants les uns des autres, le r�sultat sera :
//a- Affich� sur l��cran

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	
	//verifier si le pointeur du fichier est valide
	FILE *fp;
	char nom[10]; //le nom du fichier � ouvrir
	char ligne[100]; //pour d�signer chaque ligne du fichier
	int i=0, j=0; //compteurs
	
	//lire le nom du fichier
	printf("donner le nom du fichier a ouvrir: ");
	gets(nom);
	
	//ouvrir le fichier en mode read
	fp=fopen(nom,"r");
	
	if (fp == NULL){
		printf("le fichier n'a pas put etre ouvert");
		return 0;
	}
	
	//lecture et affichage du contenu du fichier ligne par ligne 
	while(fgets(ligne,sizeof(ligne),fp) != NULL){
		for(i=0; ligne[i] != '\0'; i++){
			if (!isspace(ligne[i]) || (i > 0 && !isspace(ligne[i - 1]))){
				ligne[j] = ligne[i];
				j++;	
			}	
		}
		ligne[j] = '\0'; // Ajouter le caract�re de fin de cha�ne � la nouvelle ligne
		
		// Afficher la ligne sur l'ecran sans exces d'espace
        printf("%s", ligne);
	}
	
	// Fermer le fichier
    fclose(fp);
	
	return 0;
}
