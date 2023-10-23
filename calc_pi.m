n = 10000;
[x1_znotraj, y1_znotraj, x1_zunaj, y1_zunaj, znotraj]= mcc_pi(n);
[pi_izrac, napaka] = area_pi(n, znotraj);

% Izriše točke
plot(x1_znotraj,y1_znotraj,'b.');
hold on
plot(x1_zunaj,y1_zunaj,'r.');

% Izriše krožnico z radijem r
fplot(@(t) 0.5*sin(t), @(t) 0.5*cos(t))

% Funkcija, ki vse to omogoča
function[pi_izr, napaka] = area_pi(n, znotraj)
mcc_pi(n);
pi_izr = 4*sum(znotraj)/n;
napaka = abs(pi - pi_izr);
end
