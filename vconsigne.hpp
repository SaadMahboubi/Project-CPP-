#ifndef VCONSIGNE_HPP
#define VCONSIGNE_HPP

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
#include "ticket.hpp"

using namespace std;

//Bagage
typedef struct {
  unsigned int volume;
  string nom;
} BAG;

class Vconsigne{
public:
  //constructeur 
  Vconsigne(vector< pair<unsigned int,unsigned int> > casiers);


  /** 
     * verification si la Vconsigne est pleine 
     * @pre la Vconsigne courante
     * @param /
     * @return un boolean, True si la Vconsigne est pleine sinon False
  */
  bool estPlein();


  //ajoute un nouveau bagage
  /** 
   * Ajoute un nouveau bagage
   * @pre un bagage de type BAG et la Vconsigne courante
   * @param bag de type BAG à déposer
   * @return ticket de type Ticket qui fait référence au baggage à déposer
  */  
  Ticket ajoutBagage(BAG bag) ;


  /** 
   * Retrait d'un bagage
   * @pre un ticket de type Ticket et la Vconsigne courante
   * @param ticket de type Ticket à qui fait référence au bagage à retirer
   * @return ticket de type Ticket qui référencie le baggage déposer
  */
  BAG retraitBagage(Ticket ticket) ;


  //test s’il existe au moins un casier libre dont le volume est supérieur à un volume donné
    /** 
   * test s’il existe au moins un casier libre dont le volume est supérieur à un volume donné
   * @pre la Vconsigne courante et un volume en entier
   * @param volume de type unsigned int 
   * @return un boolean, True si la Vconsigne possède un casier dont le volume suffit (inferieur à 'volume' passé en paramètre) sinon False
  */
  bool testVolumeCasier(unsigned int volume);

private:

  typedef struct {
      unsigned int idf; //identifiant unique du casier
      unsigned int volume; //volume que possède le casier
      BAG bag; //bagage contenu dans le casier
    } Casier; //structure du type casier

  typedef struct {
      unsigned int volume; //volume qui caractérise ce TypeCasier
      unsigned int numero; //numero unique du TypeCasier
      queue<Casier>* casiers; //casiers qui pointe vers une queue de casiers 
    } TypeCasier; //structure du type TypeCasier

  int unsigned  nbCasiers; // nombre de casiers présents 
  vector<TypeCasier> casierLibre; // conteneurs de séquences représentant des casiers dont la taille est dynamique
  std::unordered_map<Ticket, Casier> listeCasierPris; ///conteneurs associatifs d'une valeur de clé (Ticket) et d'une valeur (Casier) 

};

#endif
