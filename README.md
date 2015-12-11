# Serialization
It's my project to make simple serialization module in C language.
Serializacja

Version 1.0:
•	Serializacja I deserializacja typów maszynowych(int,long,short,double,float…) oraz tablic tych typów
•	Możliwość definiowania swoich typów(prostych: struktura mająca <=10 składowych) + dodanie użytecznych predefiniowanych typów(Zespolone, Wymierne, Punkt, Prosta…)
•	Kodowanie binarnego formatu do pliku tekstowego lub do konsoli/wyjścia
•	Format pliku binarnego: HEADER DATA FOOTER
•	HEADER:
1.	[2bajty] – skrótowa nazwa/identyfikator typu
2.	[2bajty] – wersja(minimalna + maksymalna), która może obsłużyć plik
3.	[1bajt+] – flagi, bitfield?
•	DATA:
1.	Struktura: [2] długość nazwy, [?] nazwa, [2] ilość pól(mniejsza od 10) , [?] pola
Pole: [1] typ, [2] rozmiar, [2] dł. nazwy [?] nazwa [?], [?] wartość
2.	Tablice: [2] dł. Nazwy, [?] nazwa, [2] typ, [4/2] ilość el., [?] dane
•	FOOTER:
Sposób na zakończenie pliku(może być nawet 0x11 albo 0x1234)
Version 2.0:
•	Dodanie wsparcia GUI: otwieranie, edycja pliku binarnego, tworzenie wzorców(generacja kodu), serializacja i deserializacja(powinna wywoływać odpowiednie polecenia konsolowe -> wsparcie wsteczne)
•	Dodanie archiwizacji(prawdopodobnie bez kompresji)
•	Dodanie funkcji skrótu, szczątkowe zabezpieczenia?
