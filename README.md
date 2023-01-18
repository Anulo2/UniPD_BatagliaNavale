# UniPD_BattagliaNavale
[Questa repo](https://github.com/Anulo2/UniPD_BattagliaNavale) raccoglie il codice dedicato al progetto per la prova finale di laboratorio di programmaizone all'università di Padova.

## Partecipanti

- Leonardo Canello
- Eris Sanson
- Enrico Zanoni


## Compilare
Compilare con 
```sh
bash build.sh
```
## Eseguire
In base a cosa vorrai eseguire hai vari comandi a disposizione:

### Main

Il main prende 2 argomenti: pc e cc.
Se vuoi giocare contro il computer esegui:
```sh
./build/battaglia_navale pc
```
Se invece vuoi che il computer giochi da solo esegui:
```sh
./build/battaglia_navale cc
```

### MainReplay

Il replay accetta 2 argomenti: v e f.
Se vuoi vedere un replay in console esegui:
```sh
./build/replay v ./logs/mainLogPCVSPC.txt 
```
Se invece vuoi stampare direttamente su file il replay esegui:
```sh
./build/replay f ./logs/mainLogPCVSPC.txt ./logs/outputMainReplay.txt 
```


## Altro

Le partite verranno di default salvate sui corrispettivi file `./logs/mainLogPCVSPC.txt` oppure `./logs/mainLogPLVSPC.txt`

Ovviamente nel replay si può caricare qualunque file si desideri.

Non si può usare lo stesso file come input ed output di replay.

## Implementazioni aggiuntive

Abbiamo implementato vari comandi che svolgono varie funzioni mentre si è in gioco:
| Comando | Azione|
|------|-----------|
|XX XX | Display your defense and attack grid
|AA AA | Reset the attack grid
|BB BB | Removes all the Miss form the attack grid
|DD DD | Removes all the radar scans 'y' 'Y' form the attack grid


Inoltre la selezione dell'unità che deve performare un'azione non è obbligata al solo centro dell'unità ma si può scegliere l'unità con una qualunque posizione appartenente ad essa.

Si può inoltre piazzare i sottomarini inserendo una singola coordinata (es: H11) rendendo più veloce il processo di inserimento.


