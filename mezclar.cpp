#include <iostream>
#include "nombres.h"
using namespace std;




    int  mezclarCartas(int tam){
    int r;
    r=rand()%tam;
    return r;
        }
    void repartirCartas(int &ronda, string vPalo[4],string vValor[5],int vPaloj1[5], int vPaloj2[5], int vValorj1[5], int vValorj2[5],string &jugador1,string &jugador2,int vPuntajeCartas[5],int &puntaTotalj1,int &puntajeTotalj2){
        int indice;
        int i,y,palo,valor;
        do{
        indice=0;
    for(i=0;i<5;i++){
        palo = mezclarCartas(4);
        valor = mezclarCartas(5);
        vPaloj1[i] = palo;
        vValorj1[i] = valor;
        palo = mezclarCartas(4);
        valor = mezclarCartas(5);
        vPaloj2[i] = palo;
        vValorj2[i] = valor;
    }
    for(i=0;i<5;i++){
        for (y=0;y<5;y++){
            if(vPaloj1[i] == vPaloj1[y] && vValorj1[i] == vValorj1[y] && i!=y){
                indice ++;
            }
        }
    }
    for(i=0;i<5;i++){
        for (y=0;y<5;y++){
            if(vPaloj2[i] == vPaloj2[y] && vValorj2[i] == vValorj2[y] && i!=y){
                indice ++;
            }
        }
    }
    for(i=0;i<5;i++){
        for (y=0;y<5;y++){
            if(vPaloj1[i] == vPaloj2[y] && vValorj1[i] == vValorj2[y]){
                indice ++;
            }
        }
    }
        }while(indice!=0);
        system("cls");
        cout<<"         EMBAUCADO       "<<endl;
        cout<<"<RONDA #"<<ronda + 1<<">"<<endl;
        cout<<endl;
        cout<<"  "<<jugador1<<" vs "<<jugador2<<endl;
        cout<<endl;
        cout<<"   <"<< jugador1<<"> < "<<puntaTotalj1<<" >"<<endl;
        cout<<endl;
        cout<<"----------------"<<endl;
        for(i=0;i<5;i++){
            cout<<"  "<<vValor[vValorj1[i]]<<" de "<<vPalo[vPaloj1[i]]<< "   <<<<"<<vPuntajeCartas[vValorj1[i]] <<endl;
            cout<<"                 |"<<endl;
        }
        cout<<"----------------"<<endl;
        cout<<endl;
        cout<<"   <"<< jugador2<<"> <"<<puntajeTotalj2<<">"<<endl;
        cout<<endl;
        cout<<"----------------"<<endl;
        for(i=0;i<5;i++){
            cout<<"  "<<vValor[vValorj2[i]]<<" de "<<vPalo[vPaloj2[i]]<< "   <<<<"<<vPuntajeCartas[vValorj2[i]] <<endl;
            cout<<"                 |"<<endl;
        }
        cout<<"----------------"<<endl;

    }
    void mostrarEmbaucadora(string vPalo[4],int &embaucadora){
        //int embaucadora;
        //embaucadora=mezclarCartas(4);
        cout<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"Carta Embaucadora: "<<vPalo[embaucadora]<<endl;;
        cout<<"---------------------------"<<endl;
        }

    void mostrarManos(int vPaloj1[5],int vPaloj2[5],int vValorj1[5],int vValorj2[5],string vPalo[4],string vValor[5]){
        cout<<"         EMBAUCADO       "<<endl;
        cout<<"<"<<endl;
        int i;
        for(i=0;i<5;i++){
            cout<<vValor[vValorj1[i]]<<" de "<<vPalo[vPaloj1[i]]<<endl;
        }
        cout<<"jugador2"<<endl;
        for(i=0;i<5;i++){
            cout<<vValor[vValorj2[i]]<<" de "<<vPalo[vPaloj2[i]]<<endl;
        }

        }



    void guardarNombres(string &jugador1,string &jugador2){
    string opc;
    system("cls");
    int confirmar=1;
    do{cout<<"          EMBAUCADO"<<endl;
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"Antes de comenzar deben registrar sus nombres:"<<endl;
    cout<<endl;
    cout<<"¿Nombre del Jugador 1? ";
    cin >>jugador1;
    cout<<"¿Nombre del Jugador 2? ";
    cin >>jugador2;
    cout<<endl;
    cout<<"¿Confirmar nombres? (S/N)";
    cin >> opc;
    if (opc=="s"|| opc =="S"){
        confirmar--;
        }else{
            confirmar++;
            }
    }while(confirmar!=0);
    }

    int cambioEmbaucadora(bool &bandera, int &embaucadora,string vPalo[4], string &jugador1,string jugador2, int &puntajeTotalj1,int &puntajeTotalj2){
       string opc;
       int r=embaucadora;
       if(puntajeTotalj1>=20 && bandera==false){
        cout<<jugador1<<"  Desea cambiar la cambiar la carta EMBAUCADORA? S/N  ";
        cin>>opc;
        if (opc=="s"||opc=="S"){
            r = mezclarCartas(4);
            bandera = true;
            puntajeTotalj1=puntajeTotalj1-20;
        }else{
                if(opc=="n"||opc=="N") {
                    bandera = true;
                    if(puntajeTotalj2>=20 && bandera==true){
                        cout<<jugador2<<"  Desea cambiar la cambiar la carta EMBAUCADORA? S/N  ";
                        cin>>opc;
                        if (opc=="s"||opc=="S"){
                            r = mezclarCartas(4);
                            bandera = false;
                            puntajeTotalj2=puntajeTotalj2-20;
                        }
                        else{
                        bandera = false;}
                    }
                }
            }
       }
       return r;
   }


    void calcularPuntaje( int &embaucadora,int vPaloj1[5],int vPaloj2[5],int vValorj1[5],int vValorj2[5],int vPuntajeCartas[5],int vPuntajeRondaj1[5],int vPuntajeRondaj2[5]){
          int i;
          for(i=0;i<5;i++){
          vPuntajeRondaj1[i]=vPuntajeCartas[vValorj1[i]];
          vPuntajeRondaj2[i]=vPuntajeCartas[vValorj2[i]];
          }
          for(i=0;i<5;i++){
            if(vPaloj1[i]==embaucadora){
                vPuntajeRondaj1[i]=0;
            }
          }
          for(i=0;i<5;i++){
            if(vPaloj2[i]==embaucadora){
                vPuntajeRondaj2[i]=0;
            }
          }

    }

    void mostrarPuntaje(int &ronda,string &jugador1,string &jugador2,int vPuntajeRondaj1[5], int vPuntajeRondaj2[5],int vpuntajeXrondaj1[3], int vpuntajeXrondaj2[3]){
        int i;
        cout<<endl;
        cout<<"PUNTAJES OBTENIDOS"<<endl;
        cout<<"----------------------"<<endl;
        cout<<jugador1<<" ";
        for(i=0;i<5;i++){

            cout<<" + "<<vPuntajeRondaj1[i];
        }
        cout<<" : "<<vpuntajeXrondaj1[ronda];
        cout<<endl;
        cout<<jugador2<<" ";
        for(i=0;i<5;i++){
            cout<<" + "<<vPuntajeRondaj2[i];
        }
        cout<<" : "<<vpuntajeXrondaj2[ronda];

    }

    void puntajeXronda(int &ronda,int vPuntajeRondaj1[5], int vPuntajeRondaj2[5],int vpuntajeXrondaj1[3], int vpuntajeXrondaj2[3]){
    int i;
    for(i=0;i<5;i++){
        vpuntajeXrondaj1[ronda]+=vPuntajeRondaj1[i];
        vpuntajeXrondaj2[ronda]+=vPuntajeRondaj2[i];
        }
    }
    void mostrarPuntajesTotales(int &puntajeTotalj1, int &puntajeTotalj2, string &jugador1, string &jugador2,int vPuntajeXrondaj1[3], int vPuntajeXrondaj2[3]){

    int i;

    cout<<" EMBAUCADO"<<endl;
    cout<<" ------------------------------------------------------------------------"<<endl;

    cout<<"RONDA"<<"    "<<  jugador1<<"    "<<jugador2<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    for(i=0;i<3;i++){
    cout<<i +1<<"       "<<vPuntajeXrondaj1[i]<<"     "<<vPuntajeXrondaj2[i]<<endl;
    }

    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"TOTAL     "<< puntajeTotalj1<<"    "<<puntajeTotalj2<<endl;
    cout<<endl;
    if(puntajeTotalj1>puntajeTotalj2){
       cout<<"GANADOR: "<<jugador1<<" con "<<puntajeTotalj1<<" puntos de victoria"<<endl;
    }else{
        if(puntajeTotalj2>puntajeTotalj1){
        cout<<"GANADOR: "<<jugador2<<" con "<<puntajeTotalj2<<" puntos de victoria"<<endl;
        }else{
            cout<<"NINGUNO GANO, EMPATE -.- CON "<<puntajeTotalj1<<endl;
            }
    }

}

    void funcionEstadisticas(string &jugador1, string &jugador2,int &acuPuntajeTotalj1,int &acuPuntajeTotalj2 ){
    int puntajeMaximo;
    string maximoJugador;
        if(acuPuntajeTotalj1>acuPuntajeTotalj2){
            puntajeMaximo=acuPuntajeTotalj1 ;
            maximoJugador= jugador1;
            }else{
            puntajeMaximo=acuPuntajeTotalj2;
            maximoJugador=jugador2;
            }
        cout<<" EL MAXIMO GANADOR ES : "<<maximoJugador<<" con "<< puntajeMaximo<<" PUNTOS"<<endl;
    }
    void funcionReglas(){
    cout<<"Embaucado es un juego de naipes para dos jugadores que puede" <<endl;
    cout<< "jugarse con algunas cartas de la baraja francesa y con un mazo de cartas especiales llamado figuras."<<endl;
    cout<<"Las cartas de la baraja francesa a utilizar son los 10, J, Q, K y A de las cuatro figuras" <<endl;
    cout<<"Corazón, Diamantes, Picas y Tréboles. En total son 20 cartas." <<endl;
    cout<<"Del mazo de figuras solamente se cuenta con 4 cartas: Corazón, Diamante, Pica y Trébol." <<endl;
    cout<<"Estas cartas, como se puede observar, no disponen de valor sino de una figura."  <<endl;
    cout<<endl;
    cout<<"Una partida de Embaucado la gana quien haya obtenido más puntos a lo largo" <<endl;
    cout<<"de tres rondas. En cada ronda los jugadores reciben cinco cartas al azar"<<endl;
    cout<<"que se denominan mano. Además, se da vuelta sobre la mesa una carta de las figuras."<<endl;
    cout<<"Esta carta se denomina embaucadora y es la que da nombre al juego." <<endl;
    cout<<endl;
    cout<<"El puntaje de cada jugador se determina a partir de los naipes de su mano"<<endl;
    cout<<"y la carta embaucadora es la que impide que el jugador pueda sumar puntaje."<<endl;

        }


