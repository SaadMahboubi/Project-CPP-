#include <iostream>
#include <string>
#include <unordered_map>
#include "ticket.hpp"
#include "consigne.hpp"

using namespace std;

typedef std::string BAG;

string boolAuString(bool Bool){
    if(Bool){
        return "Oui";
    }else{
        return "Non";
    }
}

int main(){
    
    Ticket ticket1 = Ticket();
    Ticket ticket2 = Ticket();

    size_t tick1Hash = ticket1.hash_code();
    size_t tick2Hash = ticket2.hash_code();

    bool testEga12 = ticket1==(ticket2);
    bool testEga11 = ticket1==(ticket1);

    bool testDiff12 = ticket2!=(ticket1);
    bool testDiff22 = ticket2!=(ticket2);

    cout << "test" << endl << endl << endl;

    cout << "après code de hashage ticket 1 devient " << tick1Hash << endl;
    cout << "après code de hashage ticket 2 devient " << tick2Hash << endl << endl;

    cout << "ticket 1 et ticket 2 sont-ils égaux : " << boolAuString(testEga12) << endl;
    cout << "ticket 1 et ticket 1 sont-ils égaux : " << boolAuString(testEga11) << endl;

    cout << "ticket 1 et ticket 2 sont-ils différents : " << boolAuString(testDiff12) << endl;
    cout << "ticket 2 et ticket 2 sont-ils différents : " << boolAuString(testDiff22) << endl << endl;

    try {

    Consigne cons = Consigne(3);
    BAG bagageX = "Bagage de Mr X";
    Ticket tickX = cons.ajoutBagage(bagageX);
    BAG bagageY = "Bagage de Mme Y";
    Ticket tickY = cons.ajoutBagage(bagageY);
    cout << "la consigne est est-elle plein : " << boolAuString(cons.estPlein()) << endl;
    cout << "il reste " << cons.tailleRestante() << " place(s) libre dans la consigne " << endl << endl;
    cons.retraitBagage(tickY);
        cout << "veuillez récupérer votre bagage..." << endl;

    cons.retraitBagage(tickX);
        cout << "veuillez récupérer votre bagage..." << endl;
        
    cout << "la consigne est est-elle plein : " << boolAuString(cons.estPlein()) << endl;
    cout << "il reste " << cons.tailleRestante() << " place(s) libre dans la consigne " << endl << endl;


   


    string rep1;

    cout << "Mr X voulez vous retirez votre bagage? (oui/non)" << endl;
    cin >> rep1;
    if(rep1 == "oui"){
        cons.retraitBagage(tickX);
        cout << "veuillez récupérer votre bagage..." << endl;
    }else{
        cout << "le bagage ne va pas être récupéré " << endl << endl;
    }

    string rep2 = "";
    cout << "Mme Y voulez vous retirez votre bagage? (oui/non)" << endl;
    cin >> rep2;
    if(rep2 == "oui"){
        cons.retraitBagage(tickY);
        cout << "veuillez récupérer votre bagage..." << endl;
    }else{
        cout << "le bagage ne va pas être récupéré " << endl << endl;
    }
    } catch(exception const& e){
        cerr << e.what() << endl;
    }



}

/* après code de hashage ticket 1 devient 1246
test


après code de hashage ticket 1 devient 1215
après code de hashage ticket 2 devient 876

ticket 1 et ticket 2 sont-ils égaux : Non
ticket 1 et ticket 1 sont-ils égaux : Oui
ticket 1 et ticket 2 sont-ils différents : Oui
ticket 2 et ticket 2 sont-ils différents : Non

la consigne est est-elle plein : Non
il reste 1 place(s) libre dans la consigne

veuillez récupérer votre bagage...
veuillez récupérer votre bagage...
la consigne est est-elle plein : Non
il reste 3 place(s) libre dans la consigne

Mr X voulez vous retirez votre bagage? (oui/non)
non
le bagage ne va pas être récupéré

Mme Y voulez vous retirez votre bagage? (oui/non)
oui
veuillez récupérer votre bagage...
*/