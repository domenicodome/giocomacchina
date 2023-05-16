# Documentazione dettagliata del codice

## Introduzione
Il codice è un gioco di simulazione di guida in cui il giocatore controlla un personaggio che guida un'auto. Durante il gioco, il giocatore inserisce l'età del personaggio, il nome, il budget iniziale e la targa dell'auto. Successivamente, il giocatore può inserire i km percorsi e la velocità dell'auto, e il programma calcola il tempo totale trascorso, il consumo di carburante e fornisce informazioni sullo stato del gioco. Il gioco termina quando il giocatore inserisce 0 come km percorsi.

## Strutture dati
Il codice utilizza due strutture dati: `Personaggio` e `Auto`. La struttura `Personaggio` contiene i seguenti campi:
- `eta` (int): rappresenta l'età del personaggio.
- `nome` (string): rappresenta il nome del personaggio.
- `soldi` (double): rappresenta il budget del giocatore.
- `modalitaGuida` (string): rappresenta la modalità di guida del personaggio.

La struttura `Auto` contiene i seguenti campi:
- `targa` (string): rappresenta la targa dell'auto.
- `serbatoio` (double): rappresenta il livello di carburante nel serbatoio dell'auto.

## Funzione `controllaMulta`
La funzione `controllaMulta` viene utilizzata per controllare se il giocatore riceve una multa per eccesso di velocità. Prende in input la velocità attuale dell'auto e un riferimento al personaggio giocatore. Se la velocità supera i 130 km/h con una probabilità del 20%, viene calcolato l'importo della multa (10€ per ogni km/h oltre il limite) e sottratto dal budget del giocatore.

**Esempio:**
```cpp
void controllaMulta(double velocita, Personaggio& giocatore) {
    if (velocita > 130.0 && rand() % 100 < 20) {  // 20% di probabilità di multa
        double importoMulta = (velocita - 130.0) * 10.0;  // Multa di 10€ per km/h oltre il limite
        cout << "Hai superato il limite di velocità! Ricevi una multa di " << importoMulta << "€.\n";
        giocatore.soldi -= importoMulta;
    }
}
```

Se la velocità inserita è 140 km/h e si verifica la probabilità del 20% di multa, verrà stampato il seguente messaggio:
```
Hai superato il limite di velocità! Ricevi una multa di 100€.
```

## Funzione `main`
La funzione `main` è la funzione principale del programma, che avvia il gioco e gestisce l'interazione con il giocatore. Di seguito è riportata una descrizione passo-passo delle operazioni svolte nella funzione:

1. Vengono dichiarate le variabili locali `giocatore` di tipo `Personaggio` e `autoGiocatore` di tipo `Auto`, che rappresentano il personaggio controll

ato dal giocatore e l'auto del giocatore, rispettivamente.

2. Vengono richiesti all'utente i dati del personaggio: l'età, il nome e il budget iniziale. Questi dati vengono memorizzati all'interno della struttura `giocatore`.

**Esempio:**
```cpp
cout << "Inserisci l'età del personaggio: ";
cin >> giocatore.eta;

cout << "Inserisci il nome del personaggio: ";
cin >> giocatore.nome;

cout << "Inserisci il budget iniziale del giocatore: ";
cin >> giocatore.soldi;
```

Se l'età del personaggio è inferiore a 16 anni, verrà stampato il seguente messaggio:
```
Spiacenti, devi avere almeno 16 anni per giocare!
```

3. Viene richiesta all'utente la targa dell'auto e viene memorizzata all'interno della struttura `autoGiocatore`.

**Esempio:**
```cpp
cout << "Inserisci la targa dell'auto: ";
cin >> autoGiocatore.targa;
```

4. Il serbatoio dell'auto viene inizializzato a 60 litri.

```cpp
autoGiocatore.serbatoio = 60.0;
```

5. Viene inizializzato il generatore di numeri casuali utilizzando il valore corrente del tempo come seme.

```cpp
srand(static_cast<unsigned>(time(0)));
```

6. Viene generata casualmente una velocità efficiente compresa tra 80 e 110 km/h.

```cpp
double velocitaEfficiente = (static_cast<double>(rand()) / RAND_MAX) * (110.0 - 80.0) + 80.0;
```

Se la velocità efficiente generata è 95 km/h.

7. Vengono dichiarate le variabili `kmPercorsi`, `tempoTotale`, `costoCarburante`, `prezzoCarburante` e `contatoreStazioni` per tenere traccia delle statistiche del gioco.

```cpp
double kmPercorsi = 0.0;
double tempoTotale = 0.0;
double costoCarburante = 0.0;
double prezzoCarburante = 0.0;
int contatoreStazioni = 0;
```

8. Viene stampato il messaggio di inizio gioco.

```cpp
cout << "Inizia il gioco!\n";
```

9. Viene avviato un ciclo `while (true)` che continua finché non viene inserito 0 come km percorsi.

```cpp
while (true) {
    // ...
}
```

10. All'interno del ciclo, vengono richiesti all'utente i km percorsi e la velocità dell'auto.

```cpp
double kmTrascorsi;
double velocita;
cout << "Inserisci i km trascorsi (0 per uscire): ";
cin >> kmTrascorsi;

if (kmTrascorsi == 0) {
    break;
}

cout << "Inserisci la velocità (km/h): ";
cin >> velocita;
```

**Esempio:**
```
Inserisci i km trascorsi (0 per uscire): 50
Inserisci la velocità (km/h): 100
```

11. Viene chiamata la funzione `

controllaMulta` per verificare se il giocatore riceve una multa per eccesso di velocità.

```cpp
controllaMulta(velocita, giocatore);
```

**Esempio:**
Se la velocità inserita è 140 km/h e si verifica la probabilità del 20% di multa, verrà stampato il seguente messaggio:
```
Hai superato il limite di velocità! Ricevi una multa di 100€.
```

12. Viene calcolato il tempo totale trascorso aggiungendo il tempo necessario per percorrere la distanza inserita.

```cpp
tempoTotale += kmTrascorsi / velocita;
```

**Esempio:**
Se i km trascorsi sono 50 e la velocità è 100 km/h, il tempo totale trascorso sarà 0.5 ore.

13. Viene determinata la modalità di guida in base all'età del giocatore.

```cpp
if (giocatore.eta < 18) {
    giocatore.modalitaGuida = "calma";
}
else {
    cout << "Inserisci la modalità di guida (calma, normale, aggressiva): ";
    cin >> giocatore.modalitaGuida;
}
```

**Esempio:**
Se l'età del giocatore è inferiore a 18 anni, la modalità di guida sarà impostata su "calma".

14. Viene calcolato il consumo di carburante in base alla modalità di guida e alla differenza di velocità rispetto alla velocità efficiente.

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
double differenzaVelocita = abs(velocita - velocitaEfficiente);
double consumoCarburante;
if (differenzaVelocita <= 20.0) {
    consumoCarburante = kmTrascorsi * ((consumoBase - 1.5 * (1 - differenzaVelocita / 20.0)) / 100.0);
}
else {
    consumoCarburante = kmTrascorsi * (consumoBase / 100.0);
}
```

**Esempio:**
Se la modalità di guida è "calma" e la differenza di velocità rispetto alla velocità efficiente è 10 km/h, il consumo di carburante sarà 1.5 litri.

15. Viene sottratto il consumo di carburante dal serbatoio dell'auto. Se il serbatoio diventa negativo, viene stampato un messaggio di carburante insufficiente e si esce dal ciclo.

```cpp
autoGiocatore.serbatoio -= consumoCarburante;
if (autoGiocatore.serbatoio < 0) {
    cout << "Carburante insufficiente per completare il percorso.\n";
    break;
}
```

**Esempio:**
Se il consumo di carburante è 1.5 litri e il serbatoio dell'auto contiene 2 litri di carburante, il serbatoio rimanente sarà 0.5 litri.

16. Vengono aggiornati i

 km percorsi.

```cpp
kmPercorsi += kmTrascorsi;
```

**Esempio:**
Se i km trascorsi sono 50, dopo il primo turno i km percorsi saranno 50.

17. Viene controllato se il giocatore si trova ad una stazione di servizio. Ogni 3 stazioni, con una probabilità del 50%, viene generato casualmente un prezzo per il carburante e viene chiesto al giocatore se desidera fare rifornimento. Se il giocatore accetta, viene richiesto il numero di litri di carburante da aggiungere. Viene effettuato un controllo sulla disponibilità di carburante nel serbatoio e sulla disponibilità di budget del giocatore. Se tutti i controlli passano, viene aggiunto il carburante al serbatoio e sottratto il costo dal budget del giocatore.

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

**Esempio:**
Se il giocatore si trova alla terza stazione di servizio e viene generato un prezzo di carburante di 1.5€ al litro, verrà stampato il seguente messaggio:
```
Sei arrivato a una stazione di servizio. Il prezzo del carburante è di 1.5€ al litro.
Vuoi fare rifornimento? (e per sì, x per no):
```
Se il giocatore sceglie di fare rifornimento e inserisce 30 litri di carburante, verrà calcolato il costo del carburante (30 litri * 1.5€/litro) e sottratto dal budget del giocatore. Inoltre, verranno aggiunti 30 litri al serbatoio dell'auto.

18. Vengono stampate le informazioni sullo stato del gioco, come i km percorsi, il livello del serbatoio

, il budget rimanente e il tempo totale trascorso.

```cpp
cout << "Hai percorso " << kmPercorsi << " km.\n";
cout << "Serbatoio rimanente: " << autoGiocatore.serbatoio << " litri\n";
cout << "Budget rimanente: " << giocatore.soldi << "€.\n";
cout << "Tempo totale trascorso: " << tempoTotale << " ore.\n";
cout << endl;  // Separa i turni con una linea vuota
```

**Esempio:**
```
Hai percorso 50 km.
Serbatoio rimanente: 0.5 litri
Budget rimanente: 400€.
Tempo totale trascorso: 0.5 ore.
```

19. Si ripete il ciclo finché non viene inserito 0 come km percorsi.

20. Alla fine del gioco, vengono stampati i risultati finali, tra cui i km percorsi, il budget rimanente, il livello del serbatoio e il tempo totale trascorso.

```cpp
cout << "Fine del gioco. Risultati:\n";
cout << "Km percorsi: " << kmPercorsi << " km.\n";
cout << "Budget rimanente: " << giocatore.soldi << "€.\n";
cout << "Serbatoio rimanente: " << autoGiocatore.serbatoio << " litri\n";
cout << "Tempo totale trascorso: " << tempoTotale << " ore.\n";
```

**Esempio:**
```
Fine del gioco. Risultati:
Km percorsi: 200 km.
Budget rimanente: 400€.
Serbatoio rimanente: 10 litri.
Tempo totale trascorso: 2.0 ore.
```

21. Il programma termina restituendo 0.

## Conclusioni
Il codice implementa un semplice gioco di simulazione di guida in cui il giocatore controlla un personaggio che guida un'auto. Attraverso l'interazione con l'utente, il programma calcola statistiche come i km percorsi, il consumo di carburante e il tempo totale trascorso. La documentazione dettagliata del codice fornisce una spiegazione esaustiva delle diverse parti del programma e delle loro funzionalità, inclusi gli esempi che illustrano l'interazione con l'utente e i risultati ottenuti durante il gioco.
