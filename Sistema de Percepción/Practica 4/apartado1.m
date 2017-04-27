%   Practica Transformaciones proyectivas 2D. Sistema de percepción
%   Realizado con Matlab 2016b
%   Master Ingeniería Mecatrónica Universidad de Málaga
%   Realizado: Juan Carlos Contreras Márquez
%   Fecha: 25/04/2017

% Leo imagen del escritorio
I1 = imread('imagenes_homografias/escritorio.jpg');
%Obtengo los cuatro puntos:
figure;
imshow(I1);
%Se muestra en la ventana de comandos como elegir los puntos.
disp('Selecciona 4 puntos de la siguiente forma y pulsa enter.')
disp(' ');
disp('   1------------2');
disp('   |            |');
disp('   |            |');
disp('   |            |');
disp('   4------------3');
[x, y]  = getpts;
%Formo x1 y x2
X1 = [x(1),x(2),x(3),x(4); y(1),y(2),y(3),y(4); 1,1,1,1];
X2 = [1,400,400,1;1,1,200,200;1,1,1,1];
%Calculo la Matriz H (3x3) 
H = homography2d(X1, X2);
%Aplico la transformacion a la imagen
%Me quedo con la parte seleccionada y sin perspectiva
tf = maketform('projective',H');
img2 = imtransform(I1, tf, 'XData', [1 400], 'YData', [1 200]);
figure;
imshow(img2);