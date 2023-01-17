# UniPD_BattagliaNavale
Questa repo raccoglie il codice dedicato al progetto per la prova finale di laboratorio di programmazione.
## Compilare
Compilare con 
```bash
bash build.sh
```
## Eseguire
In base a cosa vorrai eseguire hai vari comandi a disposizione:

### Main

Il main prende 2 argomenti: pc e cc.
Se vuoi giocare contro il computer esegui:
```bash
./build/battaglia_navale pc
```
Se invece vuoi che il computer giochi da solo esegui:
```bash
./build/battaglia_navale cc
```

### MainReplay

Il replay accetta 2 argomenti: v e f.
Se vuoi vedere un replay in console esegui:
```bash
./build/replay v ./logs/mainLogPCVSPC.txt 
```
Se invece vuoi stampare direttamente su file il replay esegui:
```bash
./build/replay f ./logs/mainLogPCVSPC.txt ./logs/outputMainReplay.txt 
```


## Altro

Le partite verranno di default salvate sui corrispettivi file `./logs/mainLogPCVSPC.txt` oppure `./logs/mainLogPLVSPC.txt`

Ovviamente nel replay si può caricare qualunque file si desideri.

Non si può usare lo stesso file come input ed output di replay.

