#include <iostream>
using namespace std;

class Nodo{
    
  char palabra;
  Nodo *siguiente;
  string color="Negro";
  int indice;

  public:

  Nodo(char palabra, Nodo *siguiente){
    this->palabra=palabra;
    this->siguiente=siguiente;
  }
  void set_Color(string color){
    this->color=color;
  }

  void set_Palabra(char palabra){
    this->palabra=palabra;
  }

  void set_Siguiente(Nodo *siguiente){
    this->siguiente=siguiente;
  }

  void set_Indice(int indice){
    this->indice=indice;
  }
  
  string get_Color(){
    return this->color;    
  }

  char get_Palabra(){
    return this->palabra;
  }

  Nodo* get_Siguiente(){
    return  this->siguiente;
  }
  
  int get_Indice(){
    return this->indice;
  }

  void mostar_Color(){
    cout<<"La letra: "<<this->palabra <<" tiene el valor de: "<<this->color<<endl;
  }
  
};


class LinkedList_Llp{
  Nodo* cabeza_Llp;
public:
  
  LinkedList_Llp(){
    this->cabeza_Llp=NULL;
  }

  
  Nodo* get_Cabeza(){
    return  this->cabeza_Llp;
  }

  void set_Cabeza(Nodo* cabeza){
    this->cabeza_Llp=cabeza;
  }


  void agregar_Final(char palabra,int indice){
    Nodo* nuevo= new Nodo (palabra,NULL);
    if(this->cabeza_Llp){
      Nodo* actual =this->cabeza_Llp;
      while (actual->get_Siguiente()){
        actual=actual->get_Siguiente();
      }
      actual->set_Siguiente(nuevo);
    }else{
      this->cabeza_Llp=nuevo;
    }
    nuevo->set_Indice(indice);
  }

};



class LinkedList_Lli{
  Nodo* cabeza_Lli;
public:
  
  LinkedList_Lli(){
    this->cabeza_Lli=NULL;
  }

  
  Nodo* get_Cabeza(){
    return  this->cabeza_Lli;
  }

  void set_Cabeza(Nodo* cabeza){
    this->cabeza_Lli=cabeza;
  }


  void agregar_Final(char palabra,int indice){
    Nodo* nuevo= new Nodo (palabra,NULL);
    if(this->cabeza_Lli){
      Nodo* actual =this->cabeza_Lli;
      while (actual->get_Siguiente()){
        actual=actual->get_Siguiente();
      }
      actual->set_Siguiente(nuevo);
    }else{
      this->cabeza_Lli=nuevo;
    }
    nuevo->set_Indice(indice);
  }

};
