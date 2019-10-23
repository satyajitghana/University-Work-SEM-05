num = [ 1  0 ];       % Numerator: s
den = [ 1  2  10 ];   % Denominator: s^2 + 2 s + 10
H = tf(num,den);
step(H)
%% Continous Time Model
num = [ 1  -1 ];
den = [ 1  -1.85  0.9 ];
H = tf(num,den,0.1);
step(H)