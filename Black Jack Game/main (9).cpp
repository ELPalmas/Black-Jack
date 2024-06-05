/*******************************************************************************
            CESAR Gregorio Palma Venegas
            Jorge Luis Leggis Romero
        INGENIERIA DE SOFTWARE TM-A
Creacion de juego de Black jack
Proyecto Final
    |||||||||||||
    |           |
    |   0   0   |
    |           |
    |   |---|   |
    |           |
    |||||||||||||
*******************************************************************************/
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

int respuestaInicio, respuestaMenu;
int baraja[4][13] = {};
int manoCrupier = 0, manoJugador = 0;
int valueCart=0;

void generarBaraja();
void generarCartas();
void reglasJuego();
void startGame();
void imprimirCartas();
void primerTurno();

int main()
{
    do{
        cout<<" Bienvenido a Black Jack!"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"[1]Partida Rapida"<<endl;
        cout<<"[2]Reglamento"<<endl;
        cout<<"[3]Salir del juego"<<endl;
        cin>>respuestaInicio;


        switch(respuestaInicio)
        {
            case 1:
                cout<<"Se inicio la partida"<<endl;
                generarBaraja(); 
                primerTurno();
                //startGame();


                break;

            case 2:
                reglasJuego();
                break;

            case 3:
                cout<<"*Saliste del juego*";
                exit (0);
                break;

        }


        cout<<"Quieres volver al menu? 1)MENU  2)SALIR"<<endl;
        cin>>respuestaMenu;
    }while(respuestaMenu==1);


}

void generarBaraja()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            baraja[i][j] = 1;
        }
    }

    cout << endl;
    cout << endl;
    cout << endl;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            cout << "\t" << baraja[i][j];
        }
        cout << endl;
        cout << endl;
        cout << endl;
    }
}

void generarCartas()
{
    int x = 0, y = 0;
    bool seguir = true;

    do
    {
        x = rand()% 13;
        y = rand()% 4;

        if(baraja[y][x] != 0)
        {
            baraja[y][x] -=1;
            seguir = false;
        }
    }
    while(seguir == true);
}
void reglasJuego()
{
    cout<<"1. Inicio del Juego:"<<endl;
    cout<<"    El crupier reparte dos cartas visibles a cada jugador, incluido él mismo."<<endl;
    cout<<"    Una de las cartas del crupier está boca arriba (visible) y la otra boca abajo (oculta)."<<endl;
    cout<<"2. Turno del Jugador:"<<endl;
    cout<<"    El jugador decide si pide más cartas (""hit"") para acercarse a 21 o se planta (""stand"") con su mano actual."<<endl;
    cout<<"    Si la suma de las cartas del jugador supera 21, pierde automáticamente (""busto"")."<<endl;
    cout<<"    El As puede valer 1 u 11 puntos según la mano del jugador."<<endl;
    cout<<"3. Turno del Crupier:"<<endl;
    cout<<"    Después de que todos los jugadores hayan actuado, el crupier revela su carta oculta."<<endl;
    cout<<"    El crupier debe seguir un conjunto de reglas preestablecidas, generalmente pedir cartas hasta alcanzar 17 o más."<<endl;
    cout<<"4. Determinación del Ganador:"<<endl;
    cout<<"    Si el jugador tiene una mano más cercana a 21 que el crupier sin pasarse, gana y recibe un pago."<<endl;
    cout<<"    Si el crupier se pasa de 21 (""busto""), todos los jugadores que no se pasaron ganan automáticamente."<<endl;
    cout<<"    Si la mano del jugador y la del crupier tienen el mismo valor, es un empate (""push"")."<<endl;
}
///se suman los puntos de el jugador
int puntosPlayer(int valueCart)
{
    manoJugador+=valueCart;
    return manoJugador;
}
///se suman los puntos del Crupier
int puntosCrupier(int valueCart)
{
    manoCrupier+=valueCart;
    return manoCrupier;
}

///funcion que inicia la partida
void startGame()
{
    cout<<"Player"<<endl;
    cout<<"*******"<<endl;

    cout<<"Puntos totales de Player"<< puntosPlayer(valueCart)<<endl;

    cout<<"Casa"<<endl;
    cout<<"*******"<<endl;

    cout<<"Puntos totales de Crupier"<< puntosCrupier(valueCart)<<endl
}

void imprimirCartas()
{
    if(carta[1]+1 == 1)
    {
        cout << "Ace";
    }
    else if(carta[1]+1 > 10)
    {
        switch(carta[1]+1)
        {
        case 11:
            cout << "Jack";
            break;
        case 12:
            cout << "Queen";
            break;
        case 13:
            cout << "King";
        }
    }
    else
    {
        cout << carta[1]+1;
    }

    switch(carta[0]+1)
    {
    case 1:
        SetConsoleOutputCP(CP_UTF8);
        printf("♥\n");
        break;
    case 2:
        SetConsoleOutputCP(CP_UTF8);
        printf("♦\n");
        break;
    case 3:
        SetConsoleOutputCP(CP_UTF8);
        printf("♣\n");
        break;
    case 4:
        SetConsoleOutputCP(CP_UTF8);
        printf("♠\n");
        break;
    }
}
void primerTurno()
{
    generarBaraja();
    cout << "Crupier: " << endl;
    generarCartas();
    manoCrupier += carta[1]+1;
    cout << "???, ";
    generarCartas();
    manoCrupier += carta[1]+1;
    imprimirCartas();
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Jugador: " << endl;
    generarCartas();
    if(carta[1]+1 > 10)
    {
        manoJugador += 10;
    }
    else
    {
        manoJugador += carta[1]+1;
    }
    imprimirCartas();
    generarCartas();
    if(carta[1]+1 > 10)
    {
        manoJugador += 10;
    }
    else
    {
        manoJugador += carta[1]+1;
    }
    imprimirCartas();
    cout << "Total: " << manoJugador << endl;
}
