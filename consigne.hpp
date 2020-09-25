#ifndef CONSIGNE_HPP
#define CONSIGNE_HPP

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include "ticket.hpp"

using namespace std;

typedef std::string BAG;

class Consigne{
public:
  //constructeur 
  Consigne(int unsigned size);

  /** 
   * verification si la consigne est pleine
   * @pre la consigne courante
   * @param /
   * @return vrai (boolean) si la consigne est plaine sinon retourne faux (boolean)
  */
  bool estPlein();
  

  /** 
   * Accesseur  à la taille de la liste vite restante
   * @pre la consigne courante
   * @param /
   * @return entier la taille 
  */   
  unsigned int tailleRestante();


  /** 
   * Ajoute un nouveau bagage
   * @pre un bagage de type BAG et la consigne courante
   * @param bag de type BAG à déposer
   * @return ticket de type Ticket qui fait référence au baggage à déposer
  */  
  Ticket ajoutBagage(BAG bag) ;

  /** 
   * Retrait d'un bagage
   * @pre un ticket de type Ticket et la consigne courante
   * @param ticket de type Ticket à qui fait référence au bagage à retirer
   * @return ticket de type Ticket qui référencie le baggage déposer
  */
  BAG retraitBagage(Ticket ticket) ;

private:

  typedef struct {
      unsigned int idf; //identifiant unique
      BAG bag; //bagage contenu dans le casier
    } Casier; //structure du type casier

  queue<Casier> casierLibre; //queue -> liste trié qui facilite l'accès à l'élément le plus acien 
  std::unordered_map<Ticket, Casier> listeCasierPris; //conteneurs associatifs d'une valeur de clé et d'une valeur
  int unsigned tailleListe;//taille de la liste restante 

};

#endif
