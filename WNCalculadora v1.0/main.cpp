#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <stdlib.h>
#include "resource.h"

HINSTANCE hInst;
//Declarando os controles para as caixas de texto
HWND entrada_x, entrada_y, saida_resultado;

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        //................................
    case WM_INITDIALOG:
    {
        //atribuindo as variáveis do programa às caixas de texto
        entrada_x = GetDlgItem(hwndDlg, ENTRADA_X);
        entrada_y = GetDlgItem(hwndDlg, ENTRADA_Y);
        saida_resultado = GetDlgItem(hwndDlg, SAIDA_RESULTADO);
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndDlg, 0);
    }
    return TRUE;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
            //Cases com as respostas às interações com o menu
        case SOMAR:
            {

            char x_str[15], y_str[15];

            //Pegando os valores inseridos nas caixas de texto e atribuindo as variáveis a cima
            GetWindowText(entrada_x, x_str, 15);
            GetWindowText(entrada_y, y_str, 15);

            float x, y, resultado;
            //Convertendo as strings colhidas em inteiros
            x = atof(x_str);
            y = atof(y_str);
            resultado = x + y;

            char resultado_str[15];
            //Converter o resultado para string e imprimir o resultado
            sprintf(resultado_str, "%.2f", resultado);

            SetWindowText(saida_resultado, resultado_str);
            break;
            }

        case SUBTRAIR:
            {
                char x_str[15], y_str[15];

            //Pegando os valores inseridos nas caixas de texto e atribuindo as variáveis a cima
            GetWindowText(entrada_x, x_str, 15);
            GetWindowText(entrada_y, y_str, 15);

            float x, y, resultado;
            //Convertendo as strings colhidas em inteiros
            x = atof(x_str);
            y = atof(y_str);
            resultado = x - y;

            char resultado_str[15];
            //Converter o resultado para string e imprimir o resultado
            sprintf(resultado_str, "%.2f", resultado);

            SetWindowText(saida_resultado, resultado_str);
            break;
            }
         case MULTIPLICAR:
            {
                char x_str[15], y_str[15];

            //Pegando os valores inseridos nas caixas de texto e atribuindo as variáveis a cima
            GetWindowText(entrada_x, x_str, 15);
            GetWindowText(entrada_y, y_str, 15);

            float x, y, resultado;
            //Convertendo as strings colhidas em inteiros
            x = atof(x_str);
            y = atof(y_str);
            resultado = x * y;

            char resultado_str[15];
            //Converter o resultado para string e imprimir o resultado
            sprintf(resultado_str, "%.2f", resultado);

            SetWindowText(saida_resultado, resultado_str);
            break;
            }

         case DIVIDIR:
            {
                char x_str[15], y_str[15];

            //Pegando os valores inseridos nas caixas de texto e atribuindo as variáveis a cima
            GetWindowText(entrada_x, x_str, 15);
            GetWindowText(entrada_y, y_str, 15);

            float x, y, resultado;
            char resultado_str[15];
            //Convertendo as strings colhidas em inteiros
            x = atof(x_str);
            y = atof(y_str);
            if(y!=0){
            resultado = x / y;

            //Converter o resultado para string e imprimir o resultado
            sprintf(resultado_str, "%.2f", resultado);
            }
            else
                sprintf(resultado_str, "ERROR...");

            SetWindowText(saida_resultado, resultado_str);
            break;
            }
        }
    }
    return TRUE;
    }
    //..............................
    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
