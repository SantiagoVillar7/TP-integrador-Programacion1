#include <iostream>
#include <cstdlib>
#include <ctime>
#include "nombres.h"
using namespace std;

int main()
{
    srand(time(0));
    int vPuntajeCartas[5]{10,11,12,15,20};
    int vPuntajeRondaj1[5]{};
    int vPuntajeRondaj2[5]{};
    string vPalo[4]{"Corazon","Pica","Trebol","Diamante"};
    string vValor[5]{"10","J","Q","K","A"};
    string jugador1;
    string jugador2;
    int  vValorj1[5];
    int  vValorj2[5];
    int  vPaloj1[5];
    int  vPaloj2[5];
    int vpuntajeXrondaj1 [3]{};
    int vpuntajeXrondaj2 [3]{};
    int puntajeTotalj1 =0;
    int puntajeTotalj2 =0;
    int acuPuntajeTotalj1=0;
    int acuPuntajeTotalj2=0;
    int  embaucadora;
    int ronda;
    bool bandera;
    bandera=false;
    int opcion;
    int salir=0;
    while(true){
    system("cls");
    cout<<"EMBAUCADO"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"1 - JUGAR"<<endl;
    cout<<"2 - ESTADiSTICAS"<<endl;
    cout<<"3 - CREDITOS"<<endl;
    cout<<"4 - REGLAS"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"0 - SALIR"<<endl;
    cin>>opcion;



   // mezclar();
   switch(opcion){
    case 1:   //JUGAR
        puntajeTotalj1=0;
        puntajeTotalj2=0;
        guardarNombres(jugador1,jugador2);
        for(ronda=0; ronda<3; ronda++){
            repartirCartas( ronda,vPalo,vValor,vPaloj1, vPaloj2, vValorj1, vValorj2,jugador1,jugador2,vPuntajeCartas,puntajeTotalj1,puntajeTotalj2);  //funcion que smula tirada y muestra cartas
            embaucadora=mezclarCartas(4);                                                          //funcion que define el codigo de carta embaucadora
            mostrarEmbaucadora(vPalo,embaucadora);                                                 //funcion que muestra carta embaucadora
            cout<<endl;
            if (puntajeTotalj1>=20 ||  puntajeTotalj2>=20){
                if(ronda>=1){
                embaucadora = cambioEmbaucadora(bandera,embaucadora,vPalo,jugador1,jugador2,puntajeTotalj1,puntajeTotalj2);//en este if pregunto por el cambio
                mostrarEmbaucadora(vPalo,embaucadora);                                                                     // de embaucadora a partir de ronda 2
                }
            }
            calcularPuntaje( embaucadora, vPaloj1,vPaloj2, vValorj1, vValorj2, vPuntajeCartas, vPuntajeRondaj1, vPuntajeRondaj2);
            puntajeXronda(ronda, vPuntajeRondaj1, vPuntajeRondaj2,vpuntajeXrondaj1, vpuntajeXrondaj2); //funcion donde ordeno los puntajes, tanto la suma como x ronda
            mostrarPuntaje(ronda,jugador1,jugador2,vPuntajeRondaj1,vPuntajeRondaj2,vpuntajeXrondaj1,vpuntajeXrondaj2); //muestro la suma del puntaje y el puntaje de cada ronda
            cout<<endl;
            puntajeTotalj1+=vpuntajeXrondaj1[ronda]; //acumulo x cada ronda el puntaje total
            puntajeTotalj2+=vpuntajeXrondaj2[ronda];

        system("pause");
        }
        system("cls");
        mostrarPuntajesTotales(puntajeTotalj1,puntajeTotalj2,jugador1,jugador2,vpuntajeXrondaj1,vpuntajeXrondaj2);  //determino al ganador y muestro los resultados x pantalla
        system("pause");

        acuPuntajeTotalj1+=puntajeTotalj1;
        acuPuntajeTotalj2+=puntajeTotalj1;
        break;
    case 2:
        system("cls") ;
        cout<<"estadsticas";
        funcionEstadisticas(jugador1,jugador2,acuPuntajeTotalj1,puntajeTotalj2);
        system("pause");
        break;
    case 3:
        system("cls") ;
        cout<<"ESTE JUEGO FUE HECHO POR"<<endl;
        cout<<"SANTIAGO VILLAR LEGAJO : 31181"<<endl;

        system("pause");
        break;
    case 4:
        system("cls");
        funcionReglas();
        system("pause");
        break;
    case 0:
        system("cls") ;
        cout<<"gracias x jugar ";
        system("pause");
        return 0;
        break;
    default:
        //system("cls");
        cout<<"INGRESE ALGUN NUMERO VALIDO"<<endl;
        system("pause");
        break;

    }



    //calcularPuntaje( vPuntajeCartas, vPaloj1, vPaloj2, vValorj1, vValorj2 , vPuntajeRondaj1, vPuntajeRondaj2);
    //mostrarManos(vPaloj1,vPaloj2,vValorj1,vValorj2,vPalo,vPalo);

    }
}
