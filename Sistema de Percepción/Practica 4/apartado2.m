%   Practica Transformaciones proyectivas 2D. Sistema de percepción
%   Realizado con Matlab 2016b
%   Master Ingeniería Mecatrónica Universidad de Málaga
%   Realizado: Juan Carlos Contreras Márquez
%   Fecha: 25/04/2017

%Obtengo la imagen
I1 = imread('imagenes_homografias/escritorio.jpg');
I2 = imread('imagenes_homografias/bob_esponja.jpg');
%Obtengo los 4 puntos de la imagen:
imshow(I1);
%Se muestra en la ventana de comandos como elegir los puntos.
disp('Selecciona 4 puntos de la siguiente forma y pulsa enter.')
disp(' ');
disp('   4------------3');
disp('   |            |');
disp('   |            |');
disp('   |            |');
disp('   1------------2');
[x,y] = getpts;

%Calculo homografia entre los puntos seleccionados y los vertices de la
%imagen bob espoja
M1 = [x(1),x(2),x(3),x(4);y(1),y(2),y(3),y(4);1,1,1,1];
M2 = [1, size(I2,2), size(I2,2),1;size(I2,1), size(I2,1),1,1;1,1,1,1];
H = homography2d(M1,M2);

%Aplico la transformacion y le calculo la inversa
tf = maketform('projective',H');
tf = fliptform(tf);
%Aplicamos la transformacion a la imagen de bob esponja
img3 = imtransform(I2, tf, 'XData', [1 size(I1,2)], 'YData', [1 size(I1,1)]);
imshow(img3);

%Aplicamos mascara
 mascara = (img3 > 0);
%Pongo los pixeles de la imagen 3 en la imagen 1
I1(mascara) = img3(mascara);
figure;
imshow(I1);


