//Programa para renovar a duração do servidor de minecraft de modo automático//
//Observações pertinentes:
//Incluir uma rotina para encontrar o botão de Renew e o botão de verificação
//No atual estado, o programa funcionará apenas com um monitor de determinará resolução
//Repensar uma condição de parada e ou maneira para distanciar no tempo o realizar da rotina
#define WINVER 0x0500
#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    int x, y;

    while(GetAsyncKeyState(VK_ESCAPE) == 0) //O programa é encerrado quando a tecla Esc é pressionada
    {
        POINT p; //Struct que armazenará as coordenadas x e y do cursor

        GetCursorPos(&p);

        cout << "x position : " << p.x << " | y position : " << p.y << endl;

        Sleep(100);

        //Posição do botão Renew:
        x = 160;
        y = 913;

        SetCursorPos(x, y); //Colocando o cursor sobre o botão de Renew
        INPUT iNPUT;
        //Emulando o pressionar do botão esquerdo
        iNPUT.type = INPUT_MOUSE; //Especificando o tipo de entrada
        iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        SendInput(1, &iNPUT, sizeof(iNPUT));
        ZeroMemory(&iNPUT, sizeof(iNPUT));

        //Emulando o soltar do botão esquerdo
        iNPUT.type = INPUT_MOUSE; //Especificando o tipo de entrada
        iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        SendInput(1, &iNPUT, sizeof(iNPUT));

        Sleep(5000);

        //Posição do botão de verificação
        x = 483;
        y = 572;

        SetCursorPos(x, y); //Colocando o cursor sobre o botão de Renew
        //Emulando o pressionar do botão esquerdo
        iNPUT.type = INPUT_MOUSE; //Especificando o tipo de entrada
        iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        SendInput(1, &iNPUT, sizeof(iNPUT));
        ZeroMemory(&iNPUT, sizeof(iNPUT));

        //Emulando o soltar do botão esquerdo
        iNPUT.type = INPUT_MOUSE; //Especificando o tipo de entrada
        iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        SendInput(1, &iNPUT, sizeof(iNPUT));

        Sleep(40*60000); //Notar que o programa aqui entrará em espera, logo, mesmo pressionando Esc o programa não é encerrado
        
    }

    cout << "Programa finalizado\n";
    return 0;
}