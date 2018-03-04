Proiect final

Autor: Leopea Catalina, grupa 243
Nume: Line follower
BOM: https://docs.google.com/spreadsheets/d/1A_e2OxjNEu9Ygx_3SRN27qNWQzmCbTon1t-9HxiU1zs/edit#gid=0

Hardware: 
Componente
Matrice de Senzori Infraroșu Reflectivi (8 Senzori);
driver de motor l293D;
2 motoare DC;
2 roti;
ball caster;
Arduino Uno;
placa suport;
distantiere;
suruburi;
fire tata-tata;
fire mama-tata;
4 baterii AA;
suport baterii

Software:
Cu ajutorul unor senzori de lumina infrarosie robotul poate să urmărească o linie neagră pe un fundal alb. De asemenea, acesta reușește să se redrezese cu succes în momentul în care iese de pe linie.

Pentru acest proiect am folosit 7 din cei 8 senzori. Fiecare senzor are o sursa care emite lumina IR si un receptor de lumina IR. Senzorii se bazează pe proprietatea radiației cu această lungime de undă, și anume că suprafețele de culoare albă reflectă radiația IR primită, iar suprafețele de culoare neagră absorb radiația IR primită. Pentru a citi informatia de la senzori folosesc comanda digitalread().

Pentru a se deplasa robotul verifica ce senzori sunt deasupra liniei si trimite impulsuri electrice de diferite intensitati catre motoare.
ex: pentru a merge in stanga accelereaza motorul din dreapta si incetineste motorul din stanga.
