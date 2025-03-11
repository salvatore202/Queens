/*
 * Regine.cpp
 *
 *  Created on: 18 nov 2023
 *      Author: salva
 */
#include "stack2.h"
#include "node2.h"



bool is_conflict(const stack<unsigned int>& choices)
{

	 //Due regine non possono mai stare sulla stessa riga
	    //per come e' organizzato lo stack

	    //Controllo che non stiano due regine sulla stessa colonna
	    //o sulla stessa diagonale
	    for(unsigned int i = 1; i < choices.size(); ++i){
	        if((choices.top() == choices.seek(i)) || (choices.top() == choices.seek(i) + i) || (choices.top() == choices.seek(i) - i))
	            return true;
	    }
	    return false;

}


void print_solution(const stack<unsigned int>& choices)
{
	stack<unsigned int> temp = choices;
		std::cout << "\n Ecco una soluzione al problema :\n" << std::endl;

		for (unsigned int numero_regina = 1; !temp.empty(); ++numero_regina)
		{
			std::cout << "Regina " <<numero_regina << ":  (" <<numero_regina << ", " << temp.top() <<")"<< std::endl;
		    temp.pop();
		}
/*
		std::cout<<std::endl;

	for(unsigned int i=1;i<=choices.size();++i)
	{
		for(unsigned int j=0; j!=choices.seek(choices.size()-i)-1;++j)
			std::cout<<"  ";
		std::cout<<"H"<<std::endl;
	}
*/
	std::cout << "\n ------------------------" << std::endl;

}


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
                // Push information nello stack indicando che la prossima scelta è uella di piazzare la regina
                //nella riga numero choice.size( )+1 e colonna numero 1
                    choices.push(1);
            }

                      if (success)
                          print_solution(choices);

                      else
                          std::cout << "No solutions were found." << std::endl;
}



int main()
{
	unsigned int n;
	std::cout<<"\n\n        PROBLEMA DELLE N REGINE ";

	std::cout<<"\n\n  Con quante regine puoi provare ? ";
	std::cin>>n;
	queens(n);
}





