//declaration des librairies

#include <stdio.h>
#include <stdlib.h>

//declaration des variables globales

#define MAX_ELEM 100

//declaration des structures

typedef struct tableau
{
    int donnee[MAX_ELEM];
    int dernier_elem;
}tableau;

//declaration des fonctions

/* Nom de la fonction: creer_tableau
 * Entrees: NULL
 * Sorties: Tableau vide
 * Description: Cette fonction nous permer de creer un tebleau vide, 
 *              ceci en initialisant dernier_elem a -1
 */

tableau *creer_tableau()
{
    tableau *tab = malloc(sizeof(tableau));
    if (!tab)   printf("Erreur allocation de memoire");//erreur
    tab->dernier_elem = -1;//initialisation de dernier_elem a 0
    return tab;
}

/* Nom de la fonction: ajout tableau
 * Entrees: Tableau dans lequel on va ajouter un element
 * Sorties: Null
 * Description: Cette fonction nous permet d'ajouter une valeur dans un
 *              tableau donne,tout en incrementant la valeur du dernier
 *              elem a chaque ajout
 */

void ajout_tableau(tableau *tab, int valeur)
{
    tab->donnee[++tab->dernier_elem]=valeur;
}

/* Nom de la fonction: remplissage_tableau
 * Entrees: Tableau a remplir
 * Sorties: Null
 * Description: Cette fonction nous permet de remplir un tableau, ceci 
 *              en faisant a chaque fois appel a la fonction d'ajout dans
 *              un tableau
 */

void remplissage_tableau(tableau *tab)
{
    char nbrs[1000];
    printf("entrez des nombres: ");
    scanf("%[^\n]s", nbrs);
    
    char *ptr = nbrs;

    
    while(ptr[0] != '\0')
    {
      int nombreCourant = (int) strtol(ptr, &ptr, 10);
      tab->donnee[tab->dernier_elem + 1] = nombreCourant;
      tab->dernier_elem++;
    }
}

/* Nom de la fonction: affichage_tableau
 * Entrees: Tableau d'entiers
 * Sorties: Null
 * Description: Cette fonction affiche les valeurs des cases d'un tableau
 *              une par une
 */

void affichage_tableau(tableau *tab)
{
    int i;
    printf("==========Affichage du tableau:=========\n");
    for ( i=0 ; i<(tab->dernier_elem + 1) ; ++i)
        printf("tab[%d] = %d\n",i ,tab->donnee[i]);
}

void affichage_tableau2(tableau *tab)
{
    int i;
    for ( i=0 ; i<(tab->dernier_elem + 1) ; ++i)
    {
        printf("%d  ",tab->donnee[i]);
    }
    printf("\n");
}



/* Nom de la fonction: echange
 * Entrees: Deux entiers dont les valeurs vont etre echangees
 * Sorties: NULL
 * Description: Cette fonction accepte pour arguments deux variables et
 *              echange leurs contenus
 */

void echange(int *val1 , int *val2)
{
    int tmp = *val1;
    *val1 = *val2;
    *val2 = tmp;
}

/* Nom de la fonction: tri_bulle
 * Entrees: Tableau d'entiers
 * Sorties: Null
 * Description: Cette fonction accepte comme argument un tableau d'entiers
 *              et lui applique la methode du tri a bulle, pour ordonner
 *               ses elements
 */

/*void tri_bulle(tableau *tab)
{
    int i, c = 0;
    while(c < (tab->dernier_elem+1))
    {
       for (i=0 ; i < (tab->dernier_elem); ++i)
       {
           if(tab->donnee[i] > tab->donnee[i+1])
               echange(&tab->donnee[i], &tab->donnee[i+1]);
           affichage_tableau(tab);
       }
       c++;
    }
}*/

/* Nom de la fonction: tri_bulleo
 * Entrees: Tableau d'entiers
 * Sorties: Null
 * Description: Cette fonction accepte comme argument un tableau 
 *              d'entiers et lui applique la methode du tri a bulle, 
 *              pour ordonner ses elements
 */

void tri_bulleo(tableau *tab)
{
    int i, f = 1;
    while(f){
        f=0;
        for (i=0 ; i<(tab->dernier_elem) ; i++)
        {
            if(tab->donnee[i]>tab->donnee[i+1])
            {
                echange(&tab->donnee[i], &tab->donnee[i+1]);
                f=1;
            }
        }
        affichage_tableau2(tab);
    }
}


/* Nom de la fonction: tri_incertion
 * Entrees: Tableau d'entiers
 * Sorties: Null
 * Description: Cette fonction accepte comme argument un tableau d'entiers
 *              et lui applique la methode du tri par incertion, pour 
 *              ordonner ses elements
 */

void tri_incertion(tableau *tab)
{
    int i, j, tmp;
    for ( i=0; i < (tab->dernier_elem+1); i++)
    {
        tmp = tab->donnee[i];
        j=i;
        while ((j>0) && (tmp < tab->donnee[j-1]))
        /*tant que l'element est inf a l'element courant, et on a pas 
          atteint le debut du tableau*/
        {
            //on decale l'element vers la droite
            tab->donnee[j] = tab->donnee[j-1];
            /*on decremente l'indice, pour recommencer la comparaison 
             avec l'element qui precede*/
            j--;
        }
        tab->donnee[j] = tmp;//on insert l'element au bon endroit
        affichage_tableau2(tab);
    }
}

/* Nom de la fonction: tri_selection
 * Entrees: Tableau d'entiers
 * Sorties: Null
 * Description: Cette fonction accepte comme argument un tableau d'entiers
 *              et lui applique la methode du tri par selection, pour
 *              ordonner ses elements
 */

void tri_selection(tableau *tab)
{
    int i,j,min;
    for (i=0 ; i<(tab->dernier_elem) ; i++)
    {
        min = i;
        
        for(j=i+1 ; j<(tab->dernier_elem + 1) ; j++)
        {
           if(tab->donnee[j] < tab->donnee[min])
            //si l'element est inferieur au min, affecter min
               min = j;
        }
        
        //si la valeur du min a changer effectuer l'echange
        if(min != i)  echange(&tab->donnee[i], &tab->donnee[min]);
        affichage_tableau2(tab);
    }
}

/*
tableau *decallage_tableau_g(tableau *tab, int position)
{
    int i,tmp;
    tmp = tab->donnee[0];
    for ( i=0 ; i < (position - 1) ; i++)
      tab->donnee[i] = tab->donnee[i+1];
    tab->donnee[position] = tmp;
    return tab;
}

int classer_tableau2(tableau *tab, int debut, int fin)
{
    int i,j,p;
    i = debut + 1;
    j = fin;
    p = tab->donnee[debut];
    while (i < j)
    {
        while ((i < j) && (tab->donnee[i] < p))  i++;
        while ((i < j) && (tab->donnee[j] > p))  j--;
        echange(&tab->donnee[j], &tab->donnee[i]);
        i++;
        j--;
    }
    tab = decallage_tableau_g(tab,j);
    return p;
}


void tri_rapide(tableau *tab, int debut, int fin)
{
    int p;
    if(debut < fin)
    {
        p = classer_tableau2(tab, debut, fin);
        tri_rapide(tab,debut,p-1);
        tri_rapide(tab,p+1,fin);
    }
}
*/

/* Nom de la fonction: copie_tableau
 * Entrees: Deux Tableaux d'entiers
 * Sorties: Un Tableau d'entiers
 * Description: Cette fonction accepte comme argument deux tableaux 
 *              d'entiers et copie le premier dans le deuxieme qui est 
 *              a priori vide
 */

tableau *copie(tableau *tab1, tableau *tab2)
{
    int i;
    for(i=0 ; i < (tab1->dernier_elem + 1) ; i++)
       ajout_tableau(tab2, tab1->donnee[i]);
    return tab2;
}

/* Nom de la fonction: tri_rapide
 * Entrees: Tableau d'entiers
 *          Deux entiers
 * Sorties: Null
 * Description: Cette fonction accepte comme argument un tableau d'entiers 
 *              et lui applique la methode du tri rapide, pour ordonner
 *              ses elements
 */

void tri_rapide(tableau *tableau, int debut, int fin)
{
    int gauche = debut-1;
    int droite = fin+1;
    int pivot = tableau->donnee[debut];
   
    if(debut >= fin) return;
    while(1)
    {
        do droite--; while(tableau->donnee[droite] > pivot);
        do gauche++; while(tableau->donnee[gauche] < pivot);
        if(gauche < droite)  echange(&tableau->donnee[gauche],
                                     &tableau->donnee[droite]);
        else break;
    }
    printf("pivot : %d       ,", pivot);
    affichage_tableau2(tableau);

    tri_rapide(tableau, debut, droite);
    tri_rapide(tableau, droite+1, fin);
}

/* Nom de la fonction: placer
 * Entrees: Tableau d'entiers
 *          Deux entiers
 * Sorties: Null
 * Description: Cette fonction accepte comme argument un tableau d'entiers 
 *              et remplace les valeurs des cases tableau de rang n par 
 *              le sup des valeurs des cases 2n et 2n+1 (si elles sont 
 *              superieurs)
 */

void placer(tableau *tableau, int indice, int taille)
{
    int k,j;
    k=indice;
    j=2*k;
    while(j <= taille)
    {
        if((j < taille) && (tableau->donnee[j] < tableau->donnee[j+1]))
           j++;
        if(tableau->donnee[k] < tableau->donnee[j])
           {
               echange(&tableau->donnee[k], &tableau->donnee[j]);
               k=j;
               j=2*k;
           }
        else break;
     }
}
           
/* Nom de la fonction: tri_tas
* Entrees: Tableau d'entiers
* Sorties: Null
* Description: Cette fonction accepte comme argument un tableau d'entiers
*              et lui applique la methode du tri par tas, pour 
*              ordonner ses elements
*/
    
void tri_par_tas(tableau *tableau)
{
    int i;
    int longueur = tableau->dernier_elem;
    for(i=(longueur/2); i>=0; i--)  placer(tableau, i, longueur);
    for(i=longueur; i>=1; i--)
    {
        echange(&tableau->donnee[i], &tableau->donnee[0]);
        placer(tableau, 0, i-1);
        affichage_tableau2(tableau);
    }
}
