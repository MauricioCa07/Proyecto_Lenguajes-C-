#include "Lista_Enlazada.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;
class Adicional {
private:

  string pActual;
  LinkedList_Llp Llp;
  string palabras[10] = {"HUMANO", "PERSONA", "MUJER", "HOMBRE", "SOBRINA",
                         "MUERTA", "TRIGO",   "SANTO", "MAIZ",   "PERU"};

public:
  void bienvenida() {
    cout << "**********************************\n"
         << "BIENVENIDO A WORDLE\n"
         << "Al crear una nueva partida se le asignará una palabra "
            "aleatorimente, la cual deberá adivinar mediante pistas que se le "
            "darán según digite palabras\n"
         << "**********************************\n"
         << endl;
  }

  void cargar_Palabra() {
    srand(time(NULL));
    this->pActual = palabras[rand() % 10];
    string temp = pActual;
    for (int i = 0; i < pActual.length(); i++) {
      this->Llp.agregar_Final(temp[0], i);
      temp = temp.erase(0, 1);
    }
  }


  void comparando_Palabra() {
    cout << "\nEn esta ronda la palabra seleccionada tiene "
         << this->pActual.length() << " caracteres" << endl;
    int j = 1;
    cout << "\n**********************************\n";
    while (j <= 6) {
      cout << "\nIngrese a continuación su intento " << j << endl;
      string comparar;
      cin >> comparar;
      comparar=aMayuscula(comparar);
      // esto verifica si el intento es valido o no
      if (comparar.length() == pActual.length()) {
        LinkedList_Lli Lli;
        string temp2 =
            comparar; // aqui se agrega la palabra, se ejecuta las mismas veces
                      // que la logitud de la palabra a comparar
        for (int i = 0; i < pActual.length(); i++) {
          Lli.agregar_Final(temp2[0], i);
          temp2 = temp2.erase(0, 1);
        }

        Nodo *current1 = Llp.get_Cabeza();
        Nodo *current2 = Lli.get_Cabeza();
        Nodo *current_Temp=current2;

        while (current2 != NULL) {
          while (current1 != NULL) {
            if (current1->get_Palabra() == current2->get_Palabra() &&
                current1->get_Indice() == current2->get_Indice()) {
              current2->set_Color("Verde");
            }
            if (current1->get_Palabra() == current2->get_Palabra() &&
                current1->get_Indice() != current2->get_Indice()) {
              current2->set_Color("Amarillo");
            }
            current1 = current1->get_Siguiente();
          }
          current2->mostar_Color();
          current1 = Llp.get_Cabeza();
          current2 = current2->get_Siguiente();
        }
        if(ganar(current_Temp, j)){
          break;
        }
        j++;
      } else {
        cout << "\nIntento invalido,pruebe de nuevo con una palabra de "
             << pActual.length() << " caracteres." << endl;
      }
    }
    cout << "**********************************\n";
  }

  bool ganar (Nodo *current, int p) {
    int cont=0;
    Nodo *temp=current;
    Nodo *temp2=Llp.get_Cabeza();
    
    while (current != NULL) {
      if (current->get_Color() == "Verde") {
        cont++;
      }
      temp=current;
      current=current->get_Siguiente();
    }  
    if(cont==temp->get_Indice()+1 && p<=6){
      cout<<"\nFelicidades Adivino la palabra\n"<<endl;
      return true;
    }else if(cont!=temp->get_Indice()+1 && p==6){  
       cout<<"\nNo adivino la palabra,la cual era:"<<endl;
      while (temp2!= NULL) {
        cout<<rojo<<temp2->get_Palabra();
        temp2=temp2->get_Siguiente();
      }
      cout<<gris<<", La siguiente sera la vencida"<<endl;
      return true;
    }
    return false;
  }

  string aMayuscula(string cadena) {
  for (int i = 0; i < cadena.length(); i++){
    cadena[i] = toupper(cadena[i]);
    }
  return cadena;
  }

};
