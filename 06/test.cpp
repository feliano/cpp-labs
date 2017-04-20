#include <iostream>
#include <vector>

using namespace std;

struct Flight;

struct Passenger {
	string name;
	string phone_number;
	bool is_no_fly;
	vector<Flight*> tickets;

	// ...
};

struct Flight{
	string flight_number;
	int seats;

	// ...

	vector<Passenger*> passengers;
};

struct Airline{
	string name;
	vector<Flight*> flights;

	// ...

	void background_check(Flight * f); // return value?
	vector<Passenger *> no_fly_list;

};

void Airline::background_check(Flight * f){

	auto p_it = f->passengers.begin();

	// check if passengers on flight are on no fly list
	while(p_it != f->passengers.end()){

		if((*p_it)->is_no_fly){
			Passenger* p = *p_it;
			no_fly_list.push_back(p); // add passenger to no fly list.
			
			// delete all tickets for passenger
			auto ticket_it = (*p_it)->tickets.begin();
			while(ticket_it != (*p_it)->tickets.end()){
				delete *ticket_it; // deletes all flight objects pointed to by passenger, dangling pointers			
				++ticket_it;
			}
		}
		++p_it;
	}

	// loop through all passengers in no fly list to check that all are correctly classified
	auto nf_it = no_fly_list.begin();
	while(nf_it != no_fly_list.end()){
		*p_it = *nf_it; // adds no fly to passenger list, overwrites p_it object -> memory leak.

		if((*p_it)->is_no_fly){
			no_fly_list.push_back(*p_it); // will contain many references to same object.
		}
		++nf_it;
	}
}

/*
Fråga: vad är problemet(-en) med background_check()?
Korrekt svar:

Loopar först igenom passagerare för en flight där man lägger till alla passengers i no fly list:
	No fly list fylls bara på utan att tömmas, eventuella dubletter kan uppstå. Tar inte heller bort passagerare från 
	flighten.

Loppar alla tickets för passageraren och deletar dem:
	Genom att deletea alla tickets som egentligen bara är flight-pekare så kommer många dangling pointers uppstå
	då andra delar av programmet pekar på dessa Flight objekt. Inga memory leaks men odefinierat beteende kan uppstå vid
	dereferncing av dessa Flight-pekare.


Loopar igenom no fly list och ser om passengers där är no fly:
	*p_it = *nf_it gör att pekaren i passengers vektorn pekar på en passenger i no fly! Om passengern var dynamiskt allokerad leder detta till
	minnesläcka. Vidare så läggs de objekt som redan finns i no fly list till igen i slutet på den. Fler dubletter.


Ganska Rätt:
Korrekt identifierat minnesläckan och vad den beror på. Missat andra problem med dubbletter och dangling pointers
är okej men minus. Svävande förklaring kring vad minnesläckan beror på är fel (kräver komplettering). 

"Det sker en minnesläcka när *p_it = *nf_it" - komplettera
"*p_it = *nf_it gör att pekaren till passenger-objektet i vektorn omtilldelas och börjar peka på ett objekt i no-fly vektorn, ingen pekare pekar
på det ursprungliga objektet i passengervektorn vilket resulterar i en minnesläcka" Rätt men kunde nämnt andra problem med koden.


Fel:
Att ha missat var minnet läcker och/eller felaktigt påstå att fel del av koden typ
dangling pointers leder till minnesläckage. Missad minnesläcka ger fel även om övriga problem
har påvisats.

"delete *ticket_it; resulterar i en minnesläcka då den tar bort objekt som andra objekt i koden pekar på"  fel inte minnesläcka men odefinierbart beteende

*/

int main(){


	return 0;
}