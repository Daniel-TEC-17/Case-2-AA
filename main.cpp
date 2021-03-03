#include <iostream>
using namespace std;


class Delivery{
public:
    
    double speed; // km/h
    double type; // 1=bicycle, 2=moto, 3=car


    

    double getTimeRestaurantHome(double pDistance, double pSpeed){ // Distancia en kilometros
        cout<< "Dura "<<(pDistance/pSpeed)*60 << " minutos en llegar del restaurante a la casa"<<endl;
        return (pDistance/pSpeed)*60; // retorna tiempo en minutos


    }
    double getTimeDeliveryRestaurant(double pDistance , double pSpeed){ // Distancia en kilometros

        cout<< "Dura "<<(pDistance/pSpeed)*60 << " minutos en llegar de donde esta el repartidor a el restaurante"<<endl;;
        return (pDistance/pSpeed)*60; // retorna tiempo en minutos

    }
    
  


};

class Bicycle: public Delivery {
   public:
      
};

class Motocycle: public Delivery {
   public:
      
};

class Car: public Delivery {
   public:
      
};


class Restaurant{

    public:
        string name;
        Delivery observers[3];

        void encontrarRepartidor(double pBicicleta, double pCar, double pMoto){
            if( pBicicleta < pCar){

                if( pBicicleta < pMoto){


                    cout<< "El metodo mas veloz es la Bicicleta con un tiempo total en minutos de: "<< pBicicleta<<endl;
                }else{
                    cout<< "El metodo mas veloz es la Moto con un tiempo total en minutos de: "<< pMoto<<endl;
                    }
                }else{
                    if (pCar < pMoto){
                        cout<< "El metodo mas veloz es el CArro con un tiempo total en minutos de: "<< pCar<<endl;
                    }else{
                        cout<< "El metodo mas veloz es la Moto con un tiempo total en minutos de: "<< pMoto<<endl;
                    }
                }
            }
        
};
int main() {
   Restaurant rest;
   Bicycle bici;
   Motocycle moto;
   Car carro;

   bici.speed = 20;
   bici.type = 1;

   moto.speed = 40;
   moto.type = 2;

   carro.speed = 30;
   carro.type = 3;

   rest.observers[0] = bici;
   rest.observers[1] = moto;
   rest.observers[2] = carro;
    double distance;
    double distanceM;
    double distanceC;
    double distanceB;

    cout<< "Cual es la distancia del restaurante a su casa?" <<endl;
    cin>> distance;
    cout<< "Cual es la distancia de la moto a el restaurante?" <<endl;
    cin>> distanceM;
    cout<< "Cual es la distancia del carro a el restaurante?" <<endl;
    cin>> distanceC;
    cout<< "Cual es la distancia de la bici a el restaurante?" <<endl;
    cin>> distanceB;


    cout<< "-----------BICI-----------------"<< endl;

    double bicicleta = rest.observers[0].getTimeDeliveryRestaurant(distanceB , rest.observers[0].speed) + rest.observers[0].getTimeRestaurantHome(distance, rest.observers[0].speed);
    
    cout<< "-------------CARRO---------------"<< endl;
    double car = rest.observers[0].getTimeDeliveryRestaurant(distanceC , rest.observers[0].speed) + rest.observers[0].getTimeRestaurantHome(distance, rest.observers[0].speed);
    
    cout<< "--------------MOTO--------------"<< endl;
    double  pMoto = rest.observers[0].getTimeDeliveryRestaurant(distanceM , rest.observers[0].speed) + rest.observers[0].getTimeRestaurantHome(distance, rest.observers[0].speed);
    

    cout<< "---------------RESPUESTA--------- "<<endl;

    rest.encontrarRepartidor(bicicleta, car, pMoto);


    return 0;
}