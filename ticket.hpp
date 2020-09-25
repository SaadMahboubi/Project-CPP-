#ifndef TICKET_HPP
#define TICKET_HPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Ticket{
public:
  /*constructeur création un ticket un numéro un int*/
  Ticket();


  /** 
   * calcul de code de hashage du ticket
   * @pre le ticket courant
   * @param /
   * @return un size_t donc le numero de ticket hasher
  */
  size_t hash_code() const;


  /** 
   * test d'égalité de deux ticket 
   * @pre le ticket courant et un autre ticket
   * @param autre de type Ticket
   * @return un boolean, True si il y a égalité entre les 2 ticket sinon False
  */
  bool operator==(Ticket const& autre) const;


  /** 
   * test d'inégalité de deux ticket 
   * @pre le ticket courant et un autre ticket
   * @param autre de type Ticket
   * @return un boolean, True si il y a inégalité entre les 2 ticket sinon False
  */
  bool operator!=(Ticket const& autre) const;

private:

size_t numTicket; //numero unique du ticket

};


//spécialisation du hash<Ticket> et utilisation de l'unique ticket (ID)
namespace std {
  template<> struct hash<Ticket> {
    size_t operator()(const Ticket& x) const
    {
      return x.hash_code();
    }
  };
}

#endif