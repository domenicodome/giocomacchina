# Documentazione del codice 

  

Il codice fornito è un semplice gioco che simula un viaggio in auto. Il giocatore deve inserire l'età del personaggio, il nome, il budget iniziale e la targa dell'auto. Successivamente, il giocatore può inserire la distanza percorsa e la velocità di guida. Il programma calcola il tempo totale trascorso, il consumo di carburante e il numero di stazioni di servizio visitate. Il gioco termina quando il giocatore decide di smettere o se il serbatoio dell'auto è vuoto. 

  

## Librerie utilizzate 

  

Il programma utilizza le seguenti librerie: 

  

```cpp 

#include <iostream> 

#include <string> 

#include <ctime> 

#include <cstdlib> 

``` 

  

- `iostream` viene utilizzata per consentire l'input/output da tastiera. 

- `string` viene utilizzata per gestire le stringhe di testo. 

- `ctime` e `cstdlib` vengono utilizzate per generare numeri casuali. 

  

## Struct 

  

Il codice definisce due struct: `Personaggio` e `Auto`. 

  

```cpp 

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

``` 

  

- `Personaggio` rappresenta un personaggio del gioco e contiene i seguenti membri: 

  - `eta` (intero): l'età del personaggio. 

  - `nome` (stringa): il nome del personaggio. 

  - `soldi` (numero in virgola mobile): il budget iniziale del giocatore. 

  - `modalitaGuida` (stringa): la modalità di guida del personaggio. 

   

- `Auto` rappresenta l'auto del giocatore e contiene i seguenti membri: 

  - `targa` (stringa): la targa dell'auto. 

  - `serbatoio` (numero in virgola mobile): la quantità di carburante nel serbatoio dell'auto. 

  

## Funzione `main` 

  

La funzione `main` è il punto di ingresso del programma. 

  

```cpp 

int main() { 

    // ... 

} 

``` 

  

### Dichiarazione delle variabili 

  

All'interno della funzione `main`, vengono dichiarate le seguenti variabili: 

  

```cpp 

Personaggio giocatore; 

Auto autoGiocatore; 

double kmPercorsi = 0.0; 

double tempoTotale = 0.0; 

double costoCarburante = 0.0; 

double prezzoCarburante = 0.0; 

int contatoreStazioni = 0; 

``` 

  

- `giocatore` (di tipo `Personaggio`): rappresenta il personaggio del giocatore. 

- `autoGiocatore` (di tipo `Auto`): rappresenta l'auto del giocatore. 

- `kmPercorsi` (numero in virgola mobile): tiene traccia dei chilometri totali percorsi. 

- `tempoTotale` (numero in virgola mobile): tiene traccia del tempo totale trascorso. 

- `costoCarburante` (numero in virgola mobile): tiene traccia del costo totale del carburante. 

- `prezzoCarburante` (numero in virgola mobile): indica il prezzo del carburante alla 

  

stazione di servizio. 

- `contatoreStazioni` (intero): tiene traccia del numero di stazioni di servizio visitate. 

  

### Input dei dati del giocatore 

  

```cpp 

cout << "Inserisci l'età del personaggio: "; 

cin >> giocatore.eta; 

``` 

  

La riga di codice sopra richiede all'utente di inserire l'età del personaggio e memorizza il valore nella variabile `giocatore.eta`. 

  

Successivamente, viene eseguito un controllo per verificare se l'età del giocatore è inferiore a 18. In tal caso, il programma mostra un messaggio di errore e termina il gioco. 

  

```cpp 

if (giocatore.eta < 18) { 

    cout << "Spiacenti, devi avere almeno 18 anni per giocare!"; 

    return 0; 

} 

``` 

  

```cpp 

cout << "Inserisci il nome del personaggio: "; 

cin >> giocatore.nome; 

``` 

  

La riga di codice sopra richiede all'utente di inserire il nome del personaggio e memorizza il valore nella variabile `giocatore.nome`. 

  

```cpp 

cout << "Inserisci il budget iniziale del giocatore: "; 

cin >> giocatore.soldi; 

``` 

  

La riga di codice sopra richiede all'utente di inserire il budget iniziale del giocatore e memorizza il valore nella variabile `giocatore.soldi`. 

  

```cpp 

cout << "Inserisci la targa dell'auto: "; 

cin >> autoGiocatore.targa; 

``` 

  

La riga di codice sopra richiede all'utente di inserire la targa dell'auto e memorizza il valore nella variabile `autoGiocatore.targa`. 

  

### Inizializzazione delle variabili 

  

```cpp 

autoGiocatore.serbatoio = 60.0; 

``` 

  

La riga di codice sopra inizializza la variabile `autoGiocatore.serbatoio` con il valore 60.0, che rappresenta la capacità massima del serbatoio dell'auto. 

  

```cpp 

srand(static_cast<unsigned>(time(0))); 

double velocitaEfficiente = (static_cast<double>(rand()) / RAND_MAX) * (110.0 - 80.0) + 80.0; 

``` 

  

La riga di codice sopra inizializza la variabile `velocitaEfficiente` con una velocità casuale compresa tra 80.0 e 110.0. La funzione `srand` inizializza il generatore di numeri casuali, mentre `rand()` restituisce un numero casuale tra 0 e `RAND_MAX`. La velocità efficiente viene calcolata mappando il valore restituito dalla funzione `rand()` nell'intervallo desiderato. 

  

### Ciclo principale del gioco 

  

```cpp 

cout << "Inizia il gioco!\n"; 

  

while (true) { 

    // ... 

} 

``` 

  

Il ciclo `while (true)` rappresenta il ciclo principale del gioco, che viene eseguito finché non viene interrotto con un'istruzione `break`. 

  

### Input dei dati di viaggio 

  

All'interno del ciclo principale del gioco, il programma richiede i dati relativi al viaggio al giocatore. 

  

```cpp 

double kmTrascorsi; 

double velocita; 

  

cout << "Inserisci i km trasc 

  

orsi (0 per uscire): "; 

cin >> kmTrascorsi; 

``` 

  

Le righe di codice sopra richiedono all'utente di inserire i chilometri trascorsi durante il viaggio e memorizzano il valore nella variabile `kmTrascorsi`. 

  

Se il valore inserito è 0, il gioco termina con l'istruzione `break`. 

  

```cpp 

if (kmTrascorsi == 0) { 

    break; 

} 

``` 

  

```cpp 

cout << "Inserisci la velocità (km/h): "; 

cin >> velocita; 

``` 

  

La riga di codice sopra richiede all'utente di inserire la velocità di guida durante il viaggio e memorizza il valore nella variabile `velocita`. 

  

### Calcolo dei tempi e delle modalità di guida 

  

```cpp 

tempoTotale += kmTrascorsi / velocita; 

``` 

  

La riga di codice sopra calcola il tempo trascorso durante il viaggio aggiungendo il rapporto tra i chilometri trascorsi (`kmTrascorsi`) e la velocità di guida (`velocita`) alla variabile `tempoTotale`. 

  

```cpp 

if (giocatore.eta < 18) { 

    giocatore.modalitaGuida = "calma"; 

} 

else { 

    cout << "Inserisci la modalità di guida (calma, normale, aggressiva): "; 

    cin >> giocatore.modalitaGuida; 

} 

``` 

  

Se l'età del giocatore è inferiore a 18, viene assegnata automaticamente la modalità di guida "calma" alla variabile `giocatore.modalitaGuida`. Altrimenti, viene richiesto all'utente di inserire la modalità di guida desiderata, che viene memorizzata nella stessa variabile. 

  

### Calcolo del consumo di carburante 

  

```cpp 

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

``` 

  

Le righe di codice sopra determinano il consumo di carburante base (`consumoBase`) in base alla modalità di guida scelta. Se la modalità di guida è "calma", il consumo base è 3.0 litri per 100 chilometri. Se la modalità di guida è "normale", il consumo base è 4.5 litri per 100 chilometri. Altrimenti, se la modalità di guida è "aggressiva", il consumo base è 5.0 litri per 100 chilometri. 

  

```cpp 

double differenzaVelocita = abs(velocita - velocitaEfficiente); 

double consumoCarburante; 

if (differenzaVelocita <= 20.0) { 

    consumoCarburante = kmTrascorsi * ((consumoBase - 1.5 * (1 - differenzaVelocita / 20.0)) / 100.0); 

} 

else { 

    consumoCarburante = kmTrascorsi * (consumoBase / 100.0); 

} 

``` 

  

Le righe di codice sopra calcolano il consumo di carburante (`consumoCarburante`) in base alla differenza tra la velocità di guida sc 

  

elta (`velocita`) e la velocità efficiente (`velocitaEfficiente`). Se la differenza di velocità è inferiore o uguale a 20.0, viene utilizzata un'equazione lineare per calcolare il consumo di carburante in base alla differenza di velocità. Altrimenti, viene utilizzato il consumo base senza alcuna penalità. 

  

### Aggiornamento del serbatoio dell'auto 

  

```cpp 

autoGiocatore.serbatoio -= consumoCarburante; 

if (autoGiocatore.serbatoio < 0) { 

    cout << "Carburante insufficiente per completare il percorso.\n"; 

    break; 

} 

``` 

  

Le righe di codice sopra sottraggono il consumo di carburante (`consumoCarburante`) dal serbatoio dell'auto (`autoGiocatore.serbatoio`). Se il serbatoio diventa inferiore a 0, viene visualizzato un messaggio di errore e il gioco termina con un'istruzione `break`. 

  

### Aggiornamento dei dati e stazione di servizio 

  

```cpp 

kmPercorsi += kmTrascorsi; 

``` 

  

La riga di codice sopra aggiorna i chilometri totali percorsi (`kmPercorsi`) aggiungendo i chilometri trascorsi durante il viaggio (`kmTrascorsi`). 

  

```cpp 

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

``` 

  

Le righe di codice sopra gestiscono la stazione di servizio. Ogni volta che il contatore delle stazioni (`contatoreStazioni`) raggiunge un multiplo di 3 e viene generato un numero casuale pari a 0, il giocatore arriva a una stazione di servizio. 

  

Viene generato un prezzo casuale del carburante tra 0.98 €/litro e 2.50 €/litro. Successivamente, viene chiesto al giocatore se des 

  

idera fare il rifornimento. Se la risposta è 'e', viene richiesto al giocatore di inserire la quantità di litri di carburante da aggiungere (`litriDaAggiungere`). 

  

Vengono effettuati alcuni controlli, come ad esempio verificare se la quantità di carburante da aggiungere supera la capacità rimanente del serbatoio (`60.0 - autoGiocatore.serbatoio`) o se il costo del carburante è superiore al budget del giocatore (`giocatore.soldi`). 

  

Se tutti i controlli sono superati, il costo del carburante viene calcolato e sottratto dal budget del giocatore (`giocatore.soldi`), mentre la quantità di carburante viene aggiunta al serbatoio dell'auto (`autoGiocatore.serbatoio`). 

  

### Output dei risultati parziali 

  

```cpp 

cout << "Hai percorso " << kmPercorsi << " km.\n"; 

cout << "Serbatoio rimanente: " << autoGiocatore.serbatoio << " litri\n"; 

cout << "Budget rimanente: " << giocatore.soldi << "€.\n"; 

cout << "Tempo totale trascorso: " << tempoTotale << " ore.\n"; 

``` 

  

Le righe di codice sopra mostrano i risultati parziali del gioco, inclusi i chilometri percorsi (`kmPercorsi`), la quantità di carburante rimanente nel serbatoio dell'auto (`autoGiocatore.serbatoio`), il budget rimanente del giocatore (`giocatore.soldi`) e il tempo totale trascorso (`tempoTotale`). 

  

### Fine del gioco e output finale 

  

```cpp 

cout << "Fine del gioco. Risultati:\n"; 

cout << "Km percorsi: " << kmPercorsi << " km.\n"; 

cout << "Budget rimanente: " << giocatore.soldi << "€.\n"; 

cout << "Serbatoio rimanente: " << autoGiocatore.serbatoio << " litri\n"; 

cout << "Tempo totale trascorso: " << tempoTotale << " ore.\n"; 

  

return 0; 

``` 

  

Le righe di codice sopra segnalano la fine del gioco e mostrano i risultati finali del gioco, inclusi i chilometri percorsi, il budget rimanente del giocatore, la quantità di carburante rimanente nel serbatoio dell'auto e il tempo totale trascorso. 

  

Infine, la funzione `main` restituisce 0, indicando il termine del programma. 
