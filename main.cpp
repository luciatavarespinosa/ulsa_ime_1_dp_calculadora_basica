// Práctica 4: Calculadora básica
// Traduce la receta de RECETA.md a C++, paso por paso.
// Deja el comentario "// Paso N" sobre cada bloque de código.

// ¿Recuerdas qué hace iostream?
#include <iostream>

// ¿Qué funciones trae ahora utilerias.h? ¿Qué devuelve cada una?
#include "utilerias.h"
using namespace std;
int main() {

    double numero1;
    double numero2;
    int opcion;

     cout<<"Calculadora basica/n";

     cout<<"Ingresa el primer numero";
     cin>> numero1;
     
     cout<<"Ingresa el segundo numero";
     cin>> numero2;

     cout<<"Selecciona una operacion \n";
     cout<<"1.Suma \n";
    cout<<"2.Resta \n";
    cout<<"3.Multiplicacion \n";
    cout<<"4.Division \n";
    cout<<"Ingresa tu opcion::";
    cin>> opcion;
    
switch(opcion){
        case 1:
            cout<< "El resultado de la suma es: " << numero1 + numero2 << endl;;
            break;
        case 2:
            cout<< "El resultado de la resta es: " << numero1 - numero2 << endl;
            break;
        case 3:
            cout<< "El resultado de la multiplicacion es: " << numero1 * numero2 << endl;
            break;
        case 4:
            if(numero2 == 0){
                cout<< "Error: No se puede dividir entre cero." << endl;
            } else {
                cout<< "El resultado de la division es: " << numero1 / numero2 << endl;
            }
            break;
        default:
            cout<< "Opción no válida." << endl;
    }

    // Variables (siempre inicializadas)
    // TODO: opcion, a, b, resultado y simbolo.
    //       ¿De qué tipo es cada una? Revisa la sección 2 de tu README.
    //       ¿Con qué valor empieza un char?

    // Pasos 1 y 2: título y menú
    // TODO

    // Paso 3: leer la opción con leerEntero y repetir si no está entre 1 y 4
    // TODO: ¿qué ciclo usaste en la Práctica 3 para volver a pedir un dato?

    // Pasos 4 y 5: leer los dos números con leerDecimal
    // TODO

    // Paso 6: SOLO si la opción es división, ¿qué haces si b es 0?
    // TODO

    // Paso 7: decisión múltiple
    // TODO: switch (opcion) { case 1: ... break; ... default: ... }
    //       ¿Qué pasa si olvidas un break? (Experimento A)

    // Paso 8: salida -> a simbolo b = resultado
    // TODO

    // ¿Qué significa return 0;?
    return 0;
}