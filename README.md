# Serialization
It's my project to make simple serialization module in C language.</br>
Serializacja</br></br>

Version 1.0:</br>
•	Serializacja I deserializacja typów maszynowych(int,long,short,double,float…) oraz tablic tych typów</br>
•	Możliwość definiowania swoich typów(prostych: struktura mająca <=10 składowych) + dodanie użytecznych predefiniowanych</br> typów(Zespolone, Wymierne, Punkt, Prosta…)</br>
•	Kodowanie binarnego formatu do pliku tekstowego lub do konsoli/wyjścia</br>
•	Format pliku binarnego: HEADER DATA FOOTER</br>
•	HEADER:</br>
1.	[2bajty] – skrótowa nazwa/identyfikator typu</br>
2.	[2bajty] – wersja(minimalna + maksymalna), która może obsłużyć plik</br>
3.	[1bajt+] – flagi, bitfield?</br>
•	DATA:</br>
1.	Struktura: [2] długość nazwy, [?] nazwa, [2] ilość pól(mniejsza od 10) , [?] pola</br>
Pole: [1] typ, [2] rozmiar, [2] dł. nazwy [?] nazwa [?], [?] wartość</br>
2.	Tablice: [2] dł. Nazwy, [?] nazwa, [2] typ, [4/2] ilość el., [?] dane</br>
•	FOOTER:</br>
Sposób na zakończenie pliku(może być nawet 0x11 albo 0x1234)</br>
Version 2.0:</br>
•	Dodanie wsparcia GUI: otwieranie, edycja pliku binarnego, tworzenie wzorców(generacja kodu), serializacja i</br> deserializacja(powinna wywoływać odpowiednie polecenia konsolowe -> wsparcie wsteczne)</br>
•	Dodanie archiwizacji(prawdopodobnie bez kompresji)</br>
•	Dodanie funkcji skrótu, szczątkowe zabezpieczenia?</br>
