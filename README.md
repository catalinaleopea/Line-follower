Proiect final

Autor: Leopea Catalina, grupa 243
Nume: Line follower
BOM: https://docs.google.com/spreadsheets/d/1A_e2OxjNEu9Ygx_3SRN27qNWQzmCbTon1t-9HxiU1zs/edit#gid=0

Hardware: 
Componente
pololu QTR-8A Reflectance array sensor
driver de motor l293d
2 motoare DC
2 roti
ball caster
Arduino Uno
placa suport
distantiere
suruburi
fire tata-tata
fire mama-tata
4 baterii AA
suport baterii

Software:
Cu ajutorul unor senzori de lumina infrarosie robotul poate să urmărească o linie neagră pe un fundal alb. De asemenea, acesta reușește să se redrezese cu succes în momentul în care iese de pe linie.
Pentru acest proiect am folosit 5 din cei 8 senzori. Fiecare senzor are o sursa care emite lumina IR si un receptor de lumina IR. Folosind comanda qtrrc.readLine(); din biblioteca "QTRSensors.h" determin pozitia pe care se afla linia. Pentru a se deplasa acesta stie pozitia actuala si anterioara a liniei si primeste impulsuri electrice de diferite intensitati catre motoare pentru a-si regla viteza.
