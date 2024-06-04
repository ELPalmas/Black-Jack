#include <iostream>

using namespace std;

int baraja[4][13] = {};
int manoCrupier = 0, manoJugador = 0;

void generarBaraja();
void generarCartas();

int main()
{
    generarBaraja();
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
