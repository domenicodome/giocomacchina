#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Personaggio {
    int eta;
    string nome;
    double soldi;
    string modalitaGuida;
};

struct Auto {
    string targa;
    double serbatoio;
};

int main() {
    Personaggio giocatore;
    Auto autoGiocatore;

    cout << "Inserisci l'età del personaggio: ";
    cin >> giocatore.eta;

    if (giocatore.eta < 18) {
        cout << "Spiacenti, devi avere almeno 18 anni per giocare!";
        return 0;
    }

    cout << "Inserisci il nome del personaggio: ";
    cin >> giocatore.nome;

    cout << "Inserisci il budget iniziale del giocatore: ";
    cin >> giocatore.soldi;

    cout << "Inserisci la targa dell'auto: ";
    cin >> autoGiocatore.targa;

    autoGiocatore.serbatoio = 60.0;

    srand(static_cast<unsigned>(time(0)));
    double velocitaEfficiente = (static_cast<double>(rand()) / RAND_MAX) * (110.0 - 80.0) + 80.0;

    double kmPercorsi = 0.0;
    double tempoTotale = 0.0;
    double costoCarburante = 0.0;
    double prezzoCarburante = 0.0;
    int contatoreStazioni = 0;

    cout << "Inizia il gioco!\n";

    while (true) {
        double kmTrascorsi;
        double velocita;
        cout << "Inserisci i km trascorsi (0 per uscire): ";
        cin >> kmTrascorsi;

        if (kmTrascorsi == 0) {
            break;
        }

        if (kmTrascorsi < 0) {
            cout << "Non è possibile fare un percorso negativo!\n";
            continue;
        }

        cout << "Inserisci la velocità (km/h): ";
        cin >> velocita;

        tempoTotale += kmTrascorsi / velocita;  // Aggiungi il tempo trascorso

        // Modalità di guida
        if (giocatore.eta < 18) {
            giocatore.modalitaGuida = "calma";
        }
        else {
            cout << "Inserisci la modalità di guida (calma, normale, aggressiva): ";
            cin >> giocatore.modalitaGuida;
        }

        double consumoBase;
        if (giocatore.modalitaGuida == "calma") {
            consumoBase = 3.0;
        }
        else if (giocatore.modalitaGuida == "normale") {
            consumoBase = 4.5;
        }
        else {
            consumoBase = 5.0;
        }

        double differenzaVelocita = abs(velocita - velocitaEfficiente);
        double consumoCarburante;
        if (differenzaVelocita <= 20.0) {
            consumoCarburante = kmTrascorsi * ((consumoBase - 1.5 * (1 - differenzaVelocita / 20.0)) / 100.0);
        }
        else {
            consumoCarburante = kmTrascorsi * (consumoBase / 100.0);
        }    autoGiocatore.serbatoio -= consumoCarburante;
        if (autoGiocatore.serbatoio < 0) {
            cout << "Carburante insufficiente per completare il percorso.\n";
            break;
        }

        kmPercorsi += kmTrascorsi;

        // Stazione di servizio
        contatoreStazioni++;
        if (contatoreStazioni % 3 == 0 && rand() % 2 == 0) {
            prezzoCarburante = (static_cast<double>(rand()) / RAND_MAX) * (2.50 - 0.98) + 0.98;
            cout << "Sei arrivato a una stazione di servizio. Il prezzo del carburante è di " << prezzoCarburante << "€ al litro.\n";
            cout << "Vuoi fare rifornimento? (e per sì, x per no): ";
            char risposta;
            cin >> risposta;
            if (risposta == 'e') {
                double litriDaAggiungere;
                cout << "Quanti litri di carburante vuoi aggiungere? ";
                cin >> litriDaAggiungere;
                if (litriDaAggiungere > 60.0 - autoGiocatore.serbatoio) {
                    cout << "Non puoi aggiungere più di " << 60.0 - autoGiocatore.serbatoio << " litri.\n";
                    continue;
                }
                double costo = litriDaAggiungere * prezzoCarburante;
                if (costo > giocatore.soldi) {
                    cout << "Non hai abbastanza soldi per fare rifornimento!\n";
                    continue;
                }
                giocatore.soldi -= costo;
                autoGiocatore.serbatoio += litriDaAggiungere;
            }
        }

        cout << "Hai percorso " << kmPercorsi << " km.\n";
        cout << "Serbatoio rimanente: " << autoGiocatore.serbatoio << " litri\n";
        cout << "Budget rimanente: " << giocatore.soldi << "€.\n";
        cout << "Tempo totale trascorso: " << tempoTotale << " ore.\n";
    }

    cout << endl;
    cout << "Fine del gioco. Risultati:\n";
    cout << "Km percorsi: " << kmPercorsi << " km.\n";
    cout << "Budget rimanente: " << giocatore.soldi << "€.\n";
    cout << "Serbatoio rimanente: " << autoGiocatore.serbatoio << " litri\n";
    cout << "Tempo totale trascorso: " << tempoTotale << " ore.\n";

    return 0;
}