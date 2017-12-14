#include <stdio.h>
#include <windows.h>


int zeilen = 10; // Aktuelle Zeile die Zuweisung ist der Startpunkt
int posxn = 20; // Aktueller Punkt auf der X Achse
int richtung = 2; // Variable zur Anweisung der Flugrichtung
int schleife = 1; // Variable zum erhalt des Schleifendurchlaufs und zusätzlich zur Fehlerweitergabe
int posxa = 0; // Startpunkt des Raumschiffs auf der X Achse


void bewegung()
{
	int ascii = 0; // 0 Setzen der Variable die ASCII Zeichen aufnimmt zum beenden des Programms X 
	int codePage = 0; // Variable in die der Wert der Pfeiltasten gespeichert wird

	ascii = getch(); // Einlesen ob die Taste X gedrückt wird

	if (ascii == 88 || ascii == 120) // Überprüfung ob x oder X gedrückt wurde und das Programm beendet werden soll
	{
		schleife = 0; // 0 Setzen der Schleifenvariable um das Programm zu beenden 
	}
	else
	{
		codePage = getch(); // Einlesen der Pfeiltastenwerte
		switch (codePage) // Switch case zur Überprüfung welche Pfeiltaste gedrückt wurde
		{
		case 72: // Pfeiltaste nach oben
			zeilen--; // Die Zeilen werden um 1 verringert ; das Raumschiff fliegt um eine Zeile nach oben 
			break;
		case 80: // Pfeiltaste nach unten
			zeilen++; // Die Zeilen werden um 1 erhöht ; das Raumschiff fliegt um eine Zeile nach unten
			break;
		case 75: // Pfeiltaste nach links 
			posxn--; // Die Leerzeichen vor dem Raumschiff werden um 1 verringert ; das Raumschiff fliegt um ein Zeichen nach links
			richtung = 1; // Die Richtung des Raumschiffs wird auf 1 = Spitze nach links festgelegt
			break;
		case 77: // Pfeiltaste nach rechts
			posxn++; // Die Leerzeichen vor dem Raumschiff werden um 1 erhöht ; das Raumschiff fliegt um ein Zeichen nach rechts
			richtung = 2; // Die Richtung des Raumschiffs wird auf 2 = Spitze nach rechts festgelegt
			break;

		}
	}
}

void leerzeichen(posx) // Funktion zur Ausgabe der Leerzeichen
{

	for (int i = 0; i < posx; i++)
	{
		printf(" ");
	}
}
void yachse(zeilen) // Funktion zur Ausgabe der Leerzeilen
{

	for (int f = 0; f< zeilen; f++)
	{
		printf("\n");
	}
}


void nachrechts() // Funktion welche das Raumschiff in Flugrichtung nach rechts ausgibt
{
	yachse(zeilen); // Ausgabe der Leerzeilen

	leerzeichen(posxn); printf("\\\n");
	leerzeichen(posxn); printf("x\\ \n");
	leerzeichen(posxn); printf("( x\n");
	leerzeichen(posxn); printf("<===>-\n");
	leerzeichen(posxn); printf("( x\n");
	leerzeichen(posxn); printf("x/\n");
	leerzeichen(posxn); printf("/\n");

	posxa = posxn; // Gleichstellung der aktuell Ausgegebenen Variablen zur Variable die den aktuellen Standort in der x Achse speichert
}

void nachlinks() // Funktion welche das Raumschiff in Flugrichtung nach links ausgibt
{
	yachse(zeilen); // Ausgabe der Leerzeilen

	leerzeichen(posxn); printf("     /\n");
	leerzeichen(posxn); printf("    /x\n");
	leerzeichen(posxn); printf("   x )\n");
	leerzeichen(posxn); printf("-<===>\n");
	leerzeichen(posxn); printf("   x )\n");
	leerzeichen(posxn); printf("    \\x\n");
	leerzeichen(posxn); printf("     \\\n");

	posxa = posxn; // Gleichstellung der aktuell Ausgegebenen Variablen zur Variable die den aktuellen Standort in der x Achse speichert
}


int main()
{
	system("mode con: cols=106 lines=50"); // Festlegung der Fenstergröße

	printf("Steuere das Raumschiff mit den Pfeiltasten und zum Beenden des Programms nutze X\n");
	do
	{
		bewegung(); // Aufruf der Funktion welche die Variablen zur Bewegung festlegt

		system("cls"); // Löschen des Bildschirms um alte Eingaben bzw alte Frames zu entfernen

		if (posxn >= posxa && richtung == 2) // Feststellung der Flugrichtung
		{
			nachrechts();
		}
		else
			if (posxn <= posxa && richtung == 1) // Feststellung der Flugrichtung
			{
				nachlinks();
			}
			else
				if (schleife == 3) // Bei einem Fehler wird das Programm abgebrochen aktuell noch nicht implementiert
				{
					printf("Es gab einen Fehler im System Error Code 1");
				}

	} while (schleife); // Solange dies zutrifft wird die Schleife ausgeführt wird durch den Druck der x oder X Taste in der Bedienungs Funktion auf 0 gesetzt

	return 0;
}