# UniPD_BattagliaNavale
Questa repo raccoglie il codice dedicato al progetto per la prova finale di laboratorio di programmazione.

compilare con 

    bash ./build.sh


# Classi


### Controller

Implementazione che gestisce l'interazione con l'umano

## Unit 

Classe astratta per implementare i vari velivoli

### Submarine

Implementazione sottomarino

### Support 

Implementazione nave di supporto

### Battleship

Implementazione nave di attacco

## Grid

Classe astratta delle 2 griglie

### DefenseGrid

Implementazione griglia di difesa

### AttackGrid 

Implementazione griglia di attacco

## Replay

SI appoggia al controller

## Game

Classe astratta che inizializza il cazzafa

### PcVsPc
...
### PcVsPlayer
...
### Replay
...


## Main

Chiama le classi 




Controller
    Grid (astratta):
        DefenseGrid
            char []
        AttackGrid
            Char []
    Unit [] (astratta)
        Tipi:
            Battleship
            Support
            Submarine
        * ControllerMio
        * ControlerAvversario
    
    metodo canMove
    ...




Controller
    Grid[]
        DefenseGrid
            char[]
        AttackGrid
            char[]
    Unit[]
        Battleship
        Support
        Submarine
    

Game
    Grid
        DefenseGrid
            Char []
        AttackGrid
            Char[]
    Unit
        Battleship
        Support
        Submarine
