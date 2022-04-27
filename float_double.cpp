/*
Arquitectura de Computadores - CCOMP3-1
Alumno: Brian Jesse Bermudez Navarro
*/
#include <iostream>
#include <bitset>
#include <string>
#include <math.h>

using namespace std;

int main(){

    float num;
    double val_decimal;
    int val_entero;
    int formato_bit=11, signif=52, p_bit=0;
    cout<<"--------------------------------------------"<<endl;
    cout<<"Conversor de Float a Double"<<endl;
    cout<<"Ingrese un numero: ";    
    cin>>num;
    cout<<endl;
    cout<<"Direccion de memoria del numero: "<<&num<<endl;
    int int_num = (long int)&num;
    cout<<"Casteo a entero del numero: "<<int_num<<endl;
    bitset <64> bi_int_num(int_num);
    cout<<"Casteo a binario del numero: "<<endl<<bi_int_num<<endl;

    if(num>0){
        p_bit=0;
    }
    else if(num<0){
        num=num*(-1);
        p_bit=1;    
    }
    
    val_entero=num;
    int cont=0;
    int str_int_entero={},residuo, prod = 1;

    while(val_entero != 0){
        residuo = val_entero % 2;
        str_int_entero = str_int_entero + (residuo * prod);
        val_entero = val_entero / 2;
        prod *= 10;
        cont++;
    }

    string str_entero(to_string(str_int_entero));

    str_entero.erase(0,1);

    int long_cad_entero = str_entero.length();

    val_decimal= num - int(num);
    
    string str_decimal ="";
    for(int i=0 ; i< (signif-long_cad_entero); i++){          
        float bit=val_decimal*2;
        if(int (bit)==1){       
            val_decimal=bit-1;
            str_decimal=str_decimal+"1";
        }
        else if(int (bit)==0){
            val_decimal=bit;
            str_decimal=str_decimal+"0";
        }
    }

    int biased =0;
    biased=(cont-1)+((pow(2,(formato_bit-1)))-1);
    bitset <11> bi_exp(biased); 
        
    cout<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<p_bit<<" "<<bi_exp<<" "<<str_entero<<str_decimal<<endl;

    return 0;
}