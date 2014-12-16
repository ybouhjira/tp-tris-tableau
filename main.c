
//declaration des librairies

#include <stdio.h>
#include <stdlib.h>
#include "tabs.h"

//programme principal

int main ()
{
  tableau *tab, *tab1, *tab2, *tab3, *tab4, *tab5;

  tab = creer_tableau();//creation d'un tableau
  tab1 = creer_tableau();
  tab2 = creer_tableau();
  tab3 = creer_tableau();
  tab4 = creer_tableau();
  tab5 = creer_tableau();

  remplissage_tableau(tab);//remplissage d'un tableau

  tab1=copie(tab, tab1);
  tab2=copie(tab, tab2);
  tab3=copie(tab, tab3);
  tab4=copie(tab, tab4);
  tab5=copie(tab, tab5);
  affichage_tableau(tab);//affichage



  affichage_tableau2(tab1);
  tri_bulleo(tab1);//si 1 appliquer le tri a bulle

  printf("\ntri par insertion:\n");
  affichage_tableau2(tab2);
  tri_incertion(tab2);//si 2 appliquer le tri par incertion

  printf("\ntri par selection:\n");
  affichage_tableau2(tab3);
  tri_selection(tab3);//si 3 appliquer le tri par selection

  printf("\ntri rapide (Qsort):\n");
  affichage_tableau2(tab4);//tri rapide (QSort)
  tri_rapide(tab4, 0, tab4->dernier_elem);

  printf("\ntri par tas (Hsort):\n");
  affichage_tableau2(tab5);//tri rapide (QSort)
  tri_par_tas(tab5);
  affichage_tableau2(tab5);


  return 0;
}
