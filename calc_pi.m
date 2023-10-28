n = 10000;
[x1_notri, y1_notri, x1_zunaj, y1_zunaj, notri]= mcc_pi(n);
[pi_izrac, napaka] = area_pi(n, notri);

% Izriše točke
plot(x1_notri,y1_notri,'b.');
hold on
plot(x1_zunaj,y1_zunaj,'r.');

% Izriše krožnico z radijem r
fplot(@(t) 0.5*sin(t), @(t) 0.5*cos(t))
title('Grafični prikaz točk')
xlabel('x') 
ylabel('y') 

% Funkcija, ki vse to omogoča
function[pi_izr, napaka] = area_pi(n, notri)
mcc_pi(n);
pi_izr = 4*sum(notri)/n;
napaka = abs(pi - pi_izr);
end
