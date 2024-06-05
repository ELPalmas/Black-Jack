#include<iostream>
#include<string.h>
#include<ctime>
#include<windows.h>

using namespace std;

int baraja[4][13] = {};
int carta[2] = {};
int manoCrupier = 0, manoJugador = 0, valorAs = 0;
bool hayAs = false;

void generarBaraja();
void generarCartas();
void imprimirCartas();
void primerTurno();

int main()
{
    int valorAs = 0, plantarse = 0;
    bool terminar = true, turnoJugador = true, ronda = true;

    generarBaraja();
    primerTurno();
    do
    {
        if(turnoJugador == true)
        {
            do
            {
                cout << "¿Pides o te plantas? 1)Pedir 2)Plantarse" << endl;
                cin >> plantarse;
                switch(plantarse)
                {
                case 1:
                    generarCartas();
                    if(carta[1]+1 > 10)
                    {
                        manoJugador += 10;
                    }
                    else if(carta[1]+1 == 1)
                    {
                        cout << "Escoge el valor del As: 1 u 11";
                        cin >> valorAs;
                        switch(valorAs)
                        {
                        case 1:
                            manoJugador += 1;
                            cout << "Total: " << manoJugador << endl;
                            break;
                        case 11:
                            manoJugador += 11;
                            cout << "Total: " << manoJugador << endl;
                            break;
                        }
                    }
                    else
                    {
                        manoJugador += carta[1]+1;
                    }
                    imprimirCartas();
                    cout << "Total: " << manoJugador << endl;
                    break;
                case 2:
                     turnoJugador = false;
                }
            }
            while(turnoJugador == true);
        }

        if(turnoJugador == false)
        {
            generarCartas();
            if(carta[1]+1 > 10)
            {
                manoCrupier += 10;
            }
            else if(carta[1]+1 == 1)
            {
                if((manoCrupier + 11) < 21)
                {
                    manoCrupier += 11;
                }
                else if((manoCrupier + 11) == 21)
                {
                    cout << "BlackJack" << endl;
                    ronda = false;
                }
                else
                {
                    cout << "El Crupier se paso de 21" << endl;
                    ronda = false;
                }
            }
            else
            {
                manoCrupier += carta[1]+1;
            }
            imprimirCartas();
        }
    }
    while(ronda == true);
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
}

void generarCartas()
{
    srand(time(0));
    int x = 0, y = 0;
    bool seguir = true;

    do
    {
        x = rand()% 13;
        y = rand()% 4;

        if(baraja[y][x] != 0)
        {
            carta[0] = y;
            carta[1] = x;
            baraja[y][x] -=1;
            seguir = false;
        }
    }
    while(seguir == true);
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
    else if(carta[1]+1 == 1)
    {
        hayAs = true;
    }
    else
    {
        manoJugador += carta[1]+1;
    }
    imprimirCartas();
    generarCartas();
    if(hayAs == true)
    {
        imprimirCartas();
        if(carta[1]+1 > 10)
        {
            manoJugador += 10;
        }
        else if(carta[1]+1 == 1)
        {
            manoJugador = 12;
        }
        else
        {
            manoJugador += carta[1]+1;
        }
        cout << "Escoge el valor del As: 1 u 11";
        cin >> valorAs;
        switch(valorAs)
        {
        case 1:
            manoJugador += 1;
            cout << "Total: " << manoJugador << endl;
            break;
        case 11:
            manoJugador += 11;
            cout << "Total: " << manoJugador << endl;
            break;
        }
    }
    else
    {
        if(carta[1]+1 > 10)
        {
            manoJugador += 10;
        }
        else if(carta[1]+1 == 1)
        {
            cout << "Escoge el valor del As: 1 u 11";
            cin >> valorAs;
            switch(valorAs)
            {
            case 1:
                manoJugador += 1;
                cout << "Total: " << manoJugador << endl;
                break;
            case 11:
                manoJugador += 11;
                cout << "Total: " << manoJugador << endl;
                break;
            }
        }
        else
        {
            manoJugador += carta[1]+1;
        }
        imprimirCartas();
    }
    cout << "Total: " << manoJugador << endl;
    cout << endl;
}
