#include "game.h"
#include <Windows.h>
Game::Game()
{
}

Game::~Game()
{
}

void Game::postavi_igrace()
{
	string ime;
	int broj_igraca;
	cout << "Unesite broj igraca:" << endl;
	while (true)
	{
		cin >> broj_igraca;
		if (broj_igraca > 5)
			cout << "Max 5 igraca. Unesite ponovno: " << endl;
		else
			break;

	}
	cout << "Unesite imena igraca, svaki igrac je dobio bonus od 250 cipova:" << endl;
	int counter = 1;
	for (int i = 0; i < broj_igraca; i++)
	{
		cout << "Ime Igraca " << counter << ": ", cin >> ime;
		igraci.push_back({ ime, 250 });
		counter++;
	}
}

void Game::start()
{
	int my_players = igraci.size();
	while (my_players)
	{
		dek.set_dek();
		dek.promijesaj();
		int ulog;

		cout << "Postavljanje uloga..." << endl;
		Sleep(1000);
		for (int i = 0; i < my_players; i++)
		{
			while (true)
			{
				cout << endl << igraci[i].get_ime() << " imate " << igraci[i].get_broj_cipova() <<  " cipova, unesite ulog: " << endl;
				cin >> ulog;
				if (!igraci[i].ulozi(ulog))
					cout << "Nemate toliko cipova..." << endl;
				else
				{
					break;
				}
			}
		}

		cout << endl << "Dijeljenje karata..." << endl;
		Sleep(2000);
		for (int i = 0; i < my_players; i++)
		{
			cout << "Igrac " << igraci[i].get_ime() << " dobiva prvu kartu..." << endl;
			Sleep(2000);
			Karta karta = dek.podijeli_kartu();
			if (karta.get_broj_karte() == 11)
			{
				igraci[i].povecaj_aseve();
			}
			igraci[i].add_to_ruka(karta);
		}

		
		cout << "Dealer dobiva prvu kartu..." << endl;
		Sleep(1500);
		Karta karta = dek.podijeli_kartu();
		if (karta.get_broj_karte() == 11)
		{
			dealer.povecaj_aseve();
		}
		dealer.add_to_ruka(karta);


		
		for (int i = 0; i < my_players; i++)
		{
			cout << "Igrac " << igraci[i].get_ime() << " dobiva drugu kartu..." << endl;
			Sleep(1500);
			Karta karta = dek.podijeli_kartu();
			if (karta.get_broj_karte() == 11)
			{
				igraci[i].povecaj_aseve();
			}
			igraci[i].add_to_ruka(karta);
		}

		cout << "Dealer dobiva drugu, skrivenu kartu..." << endl;
		Sleep(1000);
		karta = dek.podijeli_kartu();
		if (karta.get_broj_karte() == 11)
		{
			dealer.povecaj_aseve();
		}
		dealer.add_to_ruka(karta);

		cout << "Loading..." << endl;
		Sleep(1000);
		cout << endl << "Dealerova karta: " << endl;
		Sleep(1000);
		Karta prva = dealer.get_prva();
		prva.print_karta();
		int broj_busteva = 0;
		int broj_bj = 0;
		for (int i = 0; i < my_players; i++)
		{
			cout << endl;
			Sleep(2000);
			string choice;
			while (true)
			{
				cout << igraci[i].get_ime() << ", vase karte: " << endl;
				Sleep(1000);
				igraci[i].print_ruka();
				if (igraci[i].get_vrijednost() > 21 && igraci[i].get_asevi() > 0)
				{
					igraci[i].change_vrijednost();
					igraci[i].smanji_aseve();
				}
				cout << "Vrijednost: " << igraci[i].get_vrijednost() << endl;
				if (igraci[i].get_vrijednost() == 21)
				{
					if (igraci[i].size() == 2)
					{
						cout << "BLACK JACK!" << endl;
						broj_bj++;
						Sleep(2000);
						break;
					}
					else
					{
						Sleep(2000);
						break;
					}			
				}
				if (igraci[i].get_vrijednost() > 21 && igraci[i].get_asevi() == 0)
				{
					cout << "BUST!" << endl;
					broj_busteva++;
					Sleep(2000);
					break;
				}
				Sleep(1000);
				cout << "hit or stay? " << endl;
				cin >> choice;
				if (choice != "hit" && choice != "HIT" && choice != "stay" && choice != "STAY")
					cout << "Krivi unos..." << endl;
				else if (choice == "stay")
					break;
				else if (choice == "hit")
				{
					cout << endl << igraci[i].get_ime() << " povlaci kartu..." << endl;
					Sleep(2000);
					Karta my_card = dek.podijeli_kartu();
					if (my_card.get_broj_karte() == 11)
					{
						igraci[i].povecaj_aseve();
					}
					igraci[i].add_to_ruka(my_card);
				}
			}		
		}

		cout << endl;


		if (broj_bj + broj_busteva == my_players)
		{
			for (int i = 0; i < my_players; i++)
			{
				if (igraci[i].get_vrijednost() == 21 && igraci[i].size() == 2)
				{
					cout << igraci[i].get_ime() << " je osvojio " << igraci[i].getulog() * 1.5 + igraci[i].getulog() << " cipova." << endl;
					igraci[i].isplati(igraci[i].getulog() + igraci[i].getulog() * 1.5);
				}
				else
					cout << igraci[i].get_ime() << " je izgubio." << endl;
			}
		}


		else
		{
			while (true)
			{

				Sleep(2000);
				cout << "Dealerove karte: " << endl;
				Sleep(1000);
				dealer.print_ruka();
				if (dealer.get_vrijednost() > 21 && dealer.get_asevi() > 0)
				{
					dealer.change_vrijednost();
					dealer.smanji_aseve();
				}
				cout << "Vrijednost: " << dealer.get_vrijednost() << endl << endl;
				if (dealer.get_vrijednost() > 21 && dealer.get_asevi() == 0)
				{
					Sleep(2000);
					cout << "Dealer BUST, you win if you didn't BUST !" << endl;
					for (int i = 0; i < my_players; i++)
					{
						if (igraci[i].get_vrijednost() == 21 && igraci[i].size() == 2)
						{
							cout << igraci[i].get_ime() << " je osvojio " << igraci[i].getulog() * 1.5 + igraci[i].getulog() << " cipova." << endl;
							igraci[i].isplati(igraci[i].getulog() + igraci[i].getulog() * 1.5);
						}
						else if (igraci[i].get_vrijednost() < 22)
						{
							cout << igraci[i].get_ime() << " je osvojio " << igraci[i].getulog() * 2 << " cipova." << endl;
							igraci[i].isplati(igraci[i].getulog() * 2);
						}
						else
							cout << igraci[i].get_ime() << " je izgubio." << endl;
					}
					break;
				}
				else if (dealer.get_vrijednost() <= 21 && dealer.get_vrijednost() >= 17)
				{
					Sleep(2000);
					for (int i = 0; i < my_players; i++)
					{
						if (igraci[i].get_vrijednost() == 21 && igraci[i].size() == 2)
						{
							cout << igraci[i].get_ime() << " je osvojio " << igraci[i].getulog() * 1.5 + igraci[i].getulog() << " cipova." << endl;
							igraci[i].isplati(igraci[i].getulog() + igraci[i].getulog() * 1.5);
						}
						else if (( (igraci[i].get_vrijednost() > dealer.get_vrijednost()) && (igraci[i].get_vrijednost() < 22) ))
						{
							cout << igraci[i].get_ime() << " je osvojio " << igraci[i].getulog() * 2 << " cipova." << endl;
							igraci[i].isplati(igraci[i].getulog() * 2);
						}
						else if (igraci[i].get_vrijednost() == dealer.get_vrijednost())
						{
							igraci[i].isplati(igraci[i].getulog());
							cout << igraci[i].get_ime() << " je vratio ulog." << endl;
						}
						else
							cout << igraci[i].get_ime() << " je izgubio." << endl;
					}
					break;
				}
				Sleep(1000);
				cout << "Dealer povlaci kartu... " << endl;
				Karta karta = dek.podijeli_kartu();
				if (karta.get_broj_karte() == 11)
				{
					dealer.povecaj_aseve();
				}
				dealer.add_to_ruka(karta);

			}
		}
	
		cout << endl;

		for (auto it = igraci.begin(); it != igraci.end(); )
		{
			if (it->get_broj_cipova() < 1)
			{
				cout << endl << it->get_ime() << " izgubili ste sve cipove. Zavrsili ste igru." << endl;
				it = igraci.erase(it);
				my_players -= 1;
			}
			else
				it++;
		}

		for (auto it = igraci.begin(); it != igraci.end();)
		{		
			cout << it->get_ime() << " zelite li nastaviti igrati ? DA - NE" << endl;
			string odgovor;
			while (true)
			{
				cin >> odgovor;
				if (odgovor == "DA" || odgovor == "da")
				{
					it++;
					break;
				}
				else if (odgovor == "NE" || odgovor == "ne")
				{
					cout << it->get_ime() << ", zavrsili ste igru s " << it->get_broj_cipova() << " cipova, cestitamo !" << endl << endl;
					it = igraci.erase(it);
					my_players -= 1;
					break;
				}
				else
					cout << "Krivi unos..." << endl;
			}
		}

		for (int i = 0; i < my_players; i++)
		{
			igraci[i].reset_ruka();
			igraci[i].reset_ulog();
			igraci[i].reset_vrijednost();
			igraci[i].reset_asevi();
		}
		dealer.reset_ruka();
		dealer.reset_vrijednost();
		dealer.reset_asevi();
	}
}
