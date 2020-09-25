#include <cassert>
#include <ctime>
#include <iostream>
#include "ticket.hpp"

//Retourne un entier aléatoire en fonction de l'heur à laquelle elle s'execute
int my_rand (void){
    static int first = 0;
   
    if (first == 0){
        srand (time (NULL));
        first = 1;
    }

    return (rand());
}

Ticket::Ticket(){
    int num = 1;
    num = num + my_rand(); 
    this->numTicket = num;  
}

//fonction de hashage
size_t Ticket::hash_code() const{
    size_t numHash = this->numTicket * 0.000001;
    return numHash;
}

//test si ticket et autres sont égaux 
bool Ticket::operator==(Ticket const& autre) const{
    return this->numTicket == autre.numTicket ;

}
//test si ticket et autres sont différents  
bool Ticket::operator!=(Ticket const& autre) const{
    return this->numTicket != autre.numTicket ;

}
