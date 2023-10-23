function[x1_notri, y1_notri, x1_zunaj, y1_zunaj, notri] = mcc_pi(n)
% Najprej funkcija naključno ustvari koordinate točk x in y, glede na
% vhodni parameter n, s katerim povemo koliko točk želimo
x = rand(n,1);
y = rand(n,1);
x1=x-0.5;
y1=y-0.5;
% Glede na točke določi radij krožnice
r = sqrt(x1.^2+y1.^2); 
% Z radijem lahko določimo ali so točke zunaj ali znotraj krožnice
notri = r<=0.5 ;
zunaj = r>0.5 ;
% Funkcija vrne koordinate x in y točk zunaj in znotraj naše krožnice 

x1_notri = x1(notri);
y1_notri = y1(notri);
x1_zunaj = x1(zunaj);
y1_zunaj = y1(zunaj);




