/*
 * regine_array.cpp
 *
 *  Created on: 27 gen 2024
 *      Author: salva
 */


#include <iostream>
#include "stack1.h"
#include <cassert>

using namespace main_savitch_7A;

// Funzione per verificare se ci sono conflitti sulla scacchiera
bool is_conflict(const stack<unsigned int>& choices) {
    // Implementa la logica per verificare i conflitti tra le regine
    // Restituisce true se c'è un conflitto, altrimenti false
    // ...


	//Due regine non possono mai stare sulla stessa riga
		    //per come e' organizzato lo stack

		    //Controllo che non stiano due regine sulla stessa colonna
		    //o sulla stessa diagonale
	for(unsigned int i = 1; i < choices.size(); ++i)
		if((choices.top() == choices.seek(i)) || (choices.top() == (choices.seek(i) + i)) || (choices.top() == (choices.seek(i) - i)))
			return true;

    return false;
}

// Funzione per stampare la soluzione trovata
void print_solution(const stack<unsigned int>& choices)
{
	stack<unsigned int> temp = choices;
	std::cout << "Ecco una soluzione al problema :\n" << std::endl;

	for (unsigned int numero_regina = 1; !temp.empty(); ++numero_regina)
	{
		std::cout << "Regina " << numero_regina << ":  (" << numero_regina << ", " << temp.top() <<")"<< std::endl;
	    temp.pop();
	}

	std::cout << "\n ------------------------" << std::endl;

	/*
	for(unsigned int i=1;i<=choices.size();++i)
	{
		for(unsigned int j=choices.seek(choices.size()-i)-1; j!=0;--j)
			std::cout<<"  ";
		std::cout<<"H"<<std::endl;
	}
	*/
}

/*
void print_solution(const stack<unsigned int>& scelte) {
    // Implementazione semplificata della funzione per stampare la soluzione
    std::cout << "Soluzione trovata:" << std::endl;
    stack<unsigned int> temp = scelte;

    for (unsigned int numero_regina = 1; !temp.empty(); ++numero_regina)
    {
    	std::cout << "Regina " << numero_regina << ":  (" << numero_regina << ", " << temp.top() <<")"<< std::endl;
        temp.pop();
    }
}
*/

void queens(unsigned int n)
    {
        stack<unsigned int> choices;
        unsigned int next;
        bool success = false;
        assert (n >= 1);
        choices.push(1);
        success = false;
        while (!success && !choices.empty( ))
        //Precondition: Controllo se la più recente scelta (nella cima dello stack) è nella stessa riga, stessa
        //colonna o stessa diagonale come per le altre scelte (prima del top dello stack). Se così allora c’è un
        //conflitto altrimenti no
        {
            if (is_conflict(choices))
                //POP elementi dallo stack finche esso non si svuota o il top dello stack non è in colonna n.
                //Se lo stack non è vuoto allora incremento il numero della colonna del top choice di 1
                {
                 while (!choices.empty( ) && choices.top( ) == n)
                     choices.pop( );

                 if (!choices.empty( ))
                 {
                     next = choices.top( ) + 1;
                     choices.pop( );
                     choices.push(next);
                 }
                }
                else if (choices.size( ) == n)
                //no conflict and stack size pari a n.
                //success=true, ho trovato una soluzione al problema delle n regine
                    success = true;

                else
                // Push information nello stack indicando che la prossima scelta è quella di piazzare la regina
                //nella riga numero choice.size( )+1 e colonna numero 1
                    choices.push(1);
            }
                      if (success)
                          print_solution(choices);

                      else
                          std::cout << "No solutions were found." << std::endl;
        }

int main() {

	unsigned int n;
	do
	{
		std::cout<<"\n\n Inserisci un numero di regine con cui vuoi provare\n Inserire 0 per fermarsi\n\n N = ";
			std::cin>>n;
		    queens(n);

	}while(n!=0);

    return 0;
}

