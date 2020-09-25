#include <cassert>
#include <stdexcept>
#include <queue>
#include <vector>
#include "vconsigne.hpp"
#include <unordered_map>

using namespace std;

    Vconsigne::Vconsigne(vector< pair<unsigned int,unsigned int> > casiers){

        casierLibre = vector<TypeCasier>(casiers.size());
    

        int idf = 0; //ID que va prendre le casier
    
        for(int unsigned i = 0; i < casiers.size(); i++) {
            casiers[i];

            TypeCasier type;
            type.numero = casiers[i].first;
            type.volume = casiers[i].second;

            queue<Casier> * queueType = new queue<Casier>;

            for(int unsigned i = 0; i < type.numero; i++){
                Casier casier;
                casier.idf = idf;
                casier.volume = type.volume;

                (*queueType).push(casier);

                idf++;
            }

            type.casiers = queueType;
            casierLibre.push_back(type);
        }

        nbCasiers = nbCasiers + idf;
    }

    bool Vconsigne::estPlein(){
        return casierLibre.empty();
    }


    Ticket Vconsigne::ajoutBagage(BAG bag){
        //nouveau ticket 
        Ticket ticket = Ticket();

        //verifie si la map est pleine si c'est le cas erreur sera envoyé
        if (this->estPlein()) {
            throw length_error("erreur : impossible de déposer d'avantage de bagage, aucun casier libre");
        }

        if(!testVolumeCasier(bag.volume)){
            throw length_error("erreur : il existe aucun casier possédant le volume nécessaire ");
        }

     
        bool trouve = false;
        int unsigned i=0;

        //recherche du casier ou se trouve le bon volume du bagage en paramètre afin de le remplir
        while(!trouve && i <= casierLibre.size()){
            trouve = casierLibre[i].volume == bag.volume;
            i++;
        }

        if (!trouve){
            throw length_error("erreur : il existe aucun casier possédant le volume nécessaire 1.1 ");
        }

        //insetion du bagage dans la queue
        ((casierLibre[i-1].casiers)->front()).bag = bag ;
        listeCasierPris.insert({ticket, ((casierLibre[i-1].casiers)->front())});
        return ticket;

    }

    BAG Vconsigne::retraitBagage(Ticket ticket){
        //iterateur nous pérmettant de parcourir et de trouver le bagage recherché dans la map
        std::unordered_map<Ticket,Casier>::iterator pos;

        //récuperation du bagage corréspondant au ticket donné en paramètre 
        BAG bag = listeCasierPris[ticket].bag;
        Casier nvCasierVide = listeCasierPris[ticket];

        // Bagage correspondant au Ticket en param s'il est trouvé dans la map sinon envoie une erreur
        if (!(listeCasierPris.find(ticket) != listeCasierPris.end())){
            throw out_of_range("erreur : votre ticket est invalide");
        }
        pos = listeCasierPris.find(ticket);
        listeCasierPris.erase(pos);

        //verifie si il y à un casier qui possède un volume adapté
        if(!testVolumeCasier(bag.volume)){
            throw length_error("erreur : il existe aucun casier possédant le volume nécessaire ");
        }
        bool trouve = false;
        int unsigned i=0;
                
        //recherche casier ou se trouve le bagage afin de le vider
        while(!trouve && i < casierLibre.size()){
            trouve = casierLibre[i].volume == bag.volume;
            i++;
        } 

        //à chaque fois qu'un casier est vidé on le rajoutes à la fin de la file comme ça le premier élement de la file c'est celui utilisé y'a le plus longtemps
        (casierLibre[i - 1].casiers)->push(nvCasierVide);

        return bag;
            

    }

    bool Vconsigne::testVolumeCasier(unsigned int volume){
        bool trouve = false;
        int unsigned i=0;

        //parcour les casier libres afin de trouver celui qui possède le volume le plus adapté (supérieur à celui donné e paramètre)
        while(!trouve && i < casierLibre.size() ){

            trouve = casierLibre[i].volume >= volume;
            i++;
        }

        return trouve;
    }

