#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
struct ticket {
    int nT, dd, mm, aa, nArt, art[20];
    float total, prop, iva, totalmiva;
};

int main()
{
    int op1, opc, imp, nC = 0, a, v = 0, i;
    ticket cliente[5];
    do {
        cout << "******************************************************\n";
        cout << "Seleccione una opcion:\n1. Alta de ticket.\t2. Lista de tickets.\n3. Limpiar pantalla.\t0. Salir.\n";
        cin >> op1;
        switch (op1) {
        case 1:
            cout << "******************************************************\n";
            a = 0;
            cliente[nC].nArt = 0;
            cliente[nC].total = 0;
            cliente[nC].nT = nC;

            cout << "Ingrese la fecha de hoy (dd/mm):\ndd: ";
            cin >> cliente[nC].dd;
            do {
                if (cliente[nC].dd < 1 || cliente[nC].dd > 30) {
                    cout << "******************************************************\n";
                    cout << "ERROR -- INGRESA UN DIA VALIDO: ";
                    cin >> cliente[nC].dd;
                }
                else {
                    v = 1;
                }
            } while (v == 0);
            v = 0;
            cout << "mm: ";
            cin >> cliente[nC].mm;
            do {
                if (cliente[nC].mm < 1 || cliente[nC].mm > 12) {
                    cout << "******************************************************\n";
                    cout << "ERROR -- INGRESA UN MES VALIDO: ";
                    cin >> cliente[nC].mm;
                }
                else {
                    v = 1;
                }
            } while (v == 0);
            cliente[nC].aa = 2023;
            cout << "******************************************************\n";
            cout << "Seleccione los articulos que llevara el cliente:\n1. Refresco de cola (600ml)\t\t$ 17.50\n2. Jugo natural de fruta (500ml)\t$ 15.00\n3. Frituras de queso (58g)\t\t$ 23.00\n4. Cacahuates enchilados (67g)\t\t$ 17.00\n5. Galletas de chocolate (114g)\t\t$ 21.50\n6. Cafe helado (281ml)\t\t\t$ 32.00\n0. Terminar seleccion.\n---\n";
            do {
                cout << "Realiza tu seleccion: ";
                cin >> opc;
                cliente[nC].art[a] = opc;
                cliente[nC].nArt++;
                a++;
                switch (opc) {
                case 1:
                    cliente[nC].total = cliente[nC].total + 17.50;
                    break;
                case 2:
                    cliente[nC].total = cliente[nC].total + 15;
                    break;
                case 3:
                    cliente[nC].total = cliente[nC].total + 23;
                    break;
                case 4:
                    cliente[nC].total = cliente[nC].total + 17;
                    break;
                case 5:
                    cliente[nC].total = cliente[nC].total + 21.50;
                    break;
                case 6:
                    cliente[nC].total = cliente[nC].total + 32;
                    break;
                case 0:
                    break;
                default:
                    cout << "******************************************************\n";
                    cout << "ERROR -- SELECCIONA UNA OPCION VALIDA\n";
                    break;
                }
            } while (opc != 0);
            cliente[nC].iva = cliente[nC].total * 0.16;
            cliente[nC].totalmiva = cliente[nC].total * 1.16;
            cout << "******************************************************\n";
            cout << "GRACIAS POR SU COMPRA\n";
            printf("Su total es : $ %.2f", cliente[nC].totalmiva);
            cout << "\n******************************************************\n";
            cout << "SELECCIONE CUALQUIER OPCION PARA SALIR O '1' PARA IMPRIMIR SU TICKET: ";
            cin >> imp;
            switch (imp) {
            case 1:
                cout << "\n------------------------------------------------------\n";
                cout << "\n******************************************************\n";
                cout << "\tABARROTES DON CARLOS\n";
                cout << "******************************************************\n\n";
                printf("Fecha : %d // %d // %d Numero de ticket :  %d\n", cliente[nC].dd, cliente[nC].mm, cliente[nC].aa, cliente[nC].nT);
                cout << "------------------------------------------------------\n";
                for (i = 0; i < cliente[nC].nArt; i++) {
                    switch (cliente[nC].art[i]) {
                    case 1:
                        printf("|Refresco de cola (600ml) : $ %14.2f|\n", 17.50);
                        break;
                    case 2:
                        printf("|Jugo natural de fruta (500ml) : $ %9.2d|\n", 15);
                        break;
                    case 3:
                        printf("|Frituras de queso (58g) : $ %15.2d|\n", 23);
                        break;
                    case 4:
                        printf("|Cacahuates enchilados (67g) : $ %11.2d|\n", 17);
                        break;
                    case 5:
                        printf("|Galletas de chocolate (114g) : $ %10.2f|\n", 21.50);
                        break;
                    case 6:
                        printf("|Cafe helado (281ml) : $ %19d|\n", 32);
                        break;
                    default:
                        break;
                    }
                }
                cout << "======================================================\n";
                printf("|Total de articulos : $ %20.2f|\n|IVA : $ %35.2f|\n|Total + IVA : $ %27.2f|\n\n", cliente[nC].total, cliente[nC].iva, cliente[nC].totalmiva);
                cout << "------------------------------------------------------\n\n";
                break;
            default:
                break;
            }
            nC++;
            break;
        case 2:
            cout << "******************************************************\n";
            cout << "#Ticket\t\t\tArticulos\t\t\tTotal\n";
            for (i = 0; i < nC; i++) {
                printf("|%-10d\t\t%d %35.2f|\n", cliente[i].nT, cliente[i].nArt, cliente[i].total);
            }
            break;
        case 3:
            cout << "******************************************************\n";
            cout << "\tLIMPIANDO PANTALLA...\n";
            system("cls");
            break;
        case 0:
            cout << "******************************************************\n";
            break;
        default:
            cout << "******************************************************\n";
            cout << "ERROR -- SELECCIONA UNA OPCION VALIDA\n";
        }
    } while (op1 != 0);
}

