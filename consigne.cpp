#include <cassert>
#include <stdexcept>
#include <queue>
#include "consigne.hpp"
#include <unordered_map>

using namespace std;

     
    Consigne::Consigne(int unsigned taille){
        //création de la nouvelle map
        std::unordered_map<Ticket, std::string> listBag;

        //si la taille est inférieur à 1 un message d'erreur est envoyé à l'utilisateur  
        if (taille < 1) {
            throw invalid_argument("erreur : la consigne ne peut pas être crée (vérifier l'entier en paramètre)");
        }
        for(int unsigned i=0; i < taille; i++){//création de neauvou casier en leurs attribuant un identifiant unique
            Casier casier;
            casier.idf = i;

            //on insert donc le casier à la fin afin que le premier casier soit celui donc l'utilisation est la plus ancienne
            casierLibre.push(casier);
        }

        tailleListe = taille;
    }   

    bool Consigne::estPlein(){
        return casierLibre.empty();
    }

    unsigned int Consigne::tailleRestante(){
        return tailleListe;
    }

    Ticket Consigne::ajoutBagage(BAG Bag) {
        Ticket ticket = Ticket();

        //verification si la liste actuelle est pleine si c'est le cas on envoie une erreur à l'utilisateur
        if (this->estPlein()) {
            throw length_error("erreur : impossible de déposer d'avantage de bagage, aucun casier libre");
        }
        
        Casier casier = casierLibre.front();//Accées à l'élément suivant de la queue
        casierLibre.pop(); // retrait de l'élément suivant
        casier.bag = Bag;

        listeCasierPris.insert({ticket, casier}); //insertion dans la map
        tailleListe = tailleListe - 1;

        return ticket;
    }


    BAG Consigne::retraitBagage(Ticket ticket) {
        //iterateur nous pérmettant de parcourir et de trouver le bagage recherché dans la map
        std::unordered_map<Ticket,Casier>::iterator pos;

        //récuperation du bagage corréspondant au ticket donné en paramètre 
        BAG bag = listeCasierPris[ticket].bag;
        Casier nvCasierVide = listeCasierPris[ticket];

        // Bagage correspondant au Ticket en param s'il est trouvé dans la map
        if (listeCasierPris.find(ticket) != listeCasierPris.end()){
            
            pos = listeCasierPris.find(ticket);
            listeCasierPris.erase(pos);

            //à chaque fois qu'un casier est vidé on le rajoutes à la fin de la file comme ça le premier élement de la file c'est celui utilisé y'a le plus longtemps
            casierLibre.push(nvCasierVide);
            tailleListe = tailleListe + 1;

            return bag;

        }else{

            throw out_of_range("erreur : votre ticket est invalide");

        }
    }


