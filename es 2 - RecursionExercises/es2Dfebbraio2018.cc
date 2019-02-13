/*Scrivere la dichiarazione e la definizione della funzione ricorsiva
"estrai" che, data una stringa lunga al massimo 80 caratteri, estrae tutte le cifre numeriche
contenute e restituisce un’altra stringa contenente le sole cifre estratte;
i caratteri non numerici vanno comunque scartati.

Per esempio, data la stringa “11Marzo2014”, la stringa che dovrà essere estratta e
restituita sarà “112014”.

NOTA 1: La funzione estrai deve essere ricorsiva ed al suo interno non ci possono
essere cicli o chiamate a funzioni contenenti cicli. Si può fare uso di eventuali
funzioni ricorsive ausiliarie e/o funzioni wrapper.

NOTA 2: la funzione definita non deve in alcun modo alterare i parametri passati in ingresso.

NOTA 3: all’interno di questo programma non e' ammesso l’utilizzo di variabili globali o
di tipo static e di funzioni di libreria.
*/

/*Write the recursive function "estrai" which, given a string of max 80 chars, takes out all the
numbers and returns another string made of said numbers.

For example, given the string "11Marzo2014", the returned string will be "Marzo".

NOTE 1: the function "estrai" has to be recursive and there can't be loops or calls to functions
containing loops, but you can use wrapper functions.

NOTE 2: the defined function can't modify the parameters given to it.

NOTE 3: in this program global or static variables and library functions aren't allowed.
*/


#include<iostream>
using namespace std;

//declaring above so there won't be any problem with the recursion.
char *estrai(const char[]);
char *estraiRecursive(const char[], int, char[], int);

//max lenght of the array
const int DIM = 81;

int main(int argc, char *argv[]){
    char stringa[DIM], *estratta, risposta;

    do{
        cout << "inserisci la stringa da controllare: " << endl;
        cin >> stringa;

        estratta = estrai(stringa);

        cout << "la stringa estratta e': " << estratta << endl;
        cout << "vuoi inserire un'altra stringa? [s/n]";
        cin >> risposta;
    } while(risposta != 'n' && risposta != 'N');

    delete[] estratta;

    return 0;
}

//requested function, returns a pointer to an array with the string requested
char *estrai(const char myString[]){
    char *result = new char[DIM]; //making a dinamic array since the actual lenght of it is unknown
    return estraiRecursive(myString, 0, result, 0);
}

//function above made recursive and simplified using 2 indexes and an array as parameters
char *estraiRecursive(const char myString[], int indexMyString, char myResult[], int indexMyResult){

    //main check to leave the recursive loop
    if((myString[indexMyString] == '\0') || (indexMyString == DIM - 1)){
        myResult[indexMyResult] = '\0'; //setting the last char as the terminator of a string
        return myResult;
    }else if((myString[indexMyString] >= 'a' && myString[indexMyString] <= 'z') || (myString[indexMyString] >= 'A' && myString[indexMyString] <= 'Z')){ //looking for what the text asks
        myResult[indexMyResult] = myString[indexMyString]; //insert in the result string a char that respects the parameters
        //recursive call moving forward both the strings
        return estraiRecursive(myString, indexMyString + 1, myResult, indexMyResult + 1);
    }else  return estraiRecursive(myString, indexMyString + 1, myResult, indexMyResult); // recursive call moving forward only the main string
}