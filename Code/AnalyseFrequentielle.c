#include "../Headers/AnalyseFrequentielle.h"


ANALYSE AnalyseFreq(ANALYSE a,gchar* T,int kasiski){
	gchar alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	int i,j,k;
	float compteur;
	for (k = 0; k < kasiski; k++)
	{
		for(i=0;i<ALPHABET;i++)
		{
			
			compteur=0;
			for(j=k;j<a.nb;j=j+kasiski)
			{
				if(alphabet[i]==T[j])
				compteur++;
			}
			a.occ[k][i]=compteur/(a.nb/kasiski);
		}
	}
	return a;
}

ANALYSE AnalyseFrequentielle(gchar* Texte){
	gchar chaine[strlen(Texte)];
	int taille;
	ConvertisseurTableau(chaine,&taille,Texte);
	ANALYSE a;	
//compte le nb de caracteres du texte et remplir "ANALYSE.nb":        
	a.nb=strlen(chaine);

//compte le nb d'occurences de chaque lettre et remplir "ANALYSE.occ":        
	gchar alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	int i,j,compteur;
	for(i=0;i<26;i++)
	{
		compteur=0;
			for(j=0;j<a.nb;j++)
			{
				if(alphabet[i]==chaine[j])
				compteur++;
			}
			a.occ[0][i]=compteur;
	}

int taille_tab_di = a.nb-1;
gchar tmp1[2];
gchar tmp2[2];
gchar tmp3[2];
int k = 0;

	for(i=0; i<taille_tab_di; i++)
	{
		tmp1[0] = chaine[i];
		tmp1[1] = '\0';
		tmp2[0] = chaine[i+1];
		tmp2[1] = '\0';
		strcat(tmp1, tmp2);
		int ok = 1;
		for (j = 0; j < k ; j++)
		{
			if ( strcmp(a.di[j].nom,tmp1) == 0)
			{
				ok =0;
				a.di[j].frequence +=1;
			}
		}
		
		if (ok == 1)
		{
			strcpy(a.di[k].nom, tmp1);
			a.di[k].frequence =1;
			k++;
		}
	}
	a.nbdi=k;
//////////////////////
int taille_tab_tri = a.nb - 2;
k = 0;

	for(i=0; i<taille_tab_tri; i++)
	{
		tmp1[0] = chaine[i];
		tmp1[1] = '\0';
		tmp2[0] = chaine[i+1];
		tmp2[1] = '\0';
		tmp3[0] = chaine[i+2];
		tmp3[1] = '\0';
		strcat(tmp1, tmp2);
		strcat(tmp1, tmp3);
		int ok = 1;
		
		for (j = 0; j < k ; j++)
		{
			if ( strcmp(a.tr[j].nom,tmp1) == 0)
			{
				ok =0;
				a.tr[j].frequence +=1;
			}
		}
		
		if (ok == 1)
		{
			strcpy(a.tr[k].nom, tmp1);
			a.tr[k].frequence =1;
			k++;
		}
	}
	a.nbtr=k;
	return a;
}
