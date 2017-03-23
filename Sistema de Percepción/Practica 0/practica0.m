%   Practica 0. Sistema de percepción
%   Realizado con Matlab 2016b
%   Master Ingeniería Mecatrónica Universidad de Málaga
%   Realizado: Juan Carlos Contreras Márquez
%   Fecha: 23/03/2017

%Leer una imagen
imc = imread('lily.tif');
%Convertir a escala de grises
img = rgb2gray(imc);

%Calcular histograma de una imagen
count = imhist(img, 256);

%Imagen umbralizada(Con dos tonos: Blanco 255 y negro 0
ibw = im2bw(imc, 100/255);

%Imagen con mitad de resolucion
i2 = imresize(imc, 0.5); %Metodo de interpolacion

%Quedarse con la subimagen del centro
y2 = round(size(img,1)/2);
x2 = round(size(img,2)/2);
w = 25; % subimage de ancho y alto 51 px
isub = img(y2 - w : y2 + w, x2 - w : x2 + w);

%Muestro las figuras
subplot(2,3,1), imshow(imc), title('Color');
subplot(2,3,2), imshow(img), title('Grises');
subplot(2,3,3), bar(count), title('Histograma');
subplot(2,3,4), imshow(ibw), title('Umbralizada');
subplot(2,3,5), imshow(i2), title('Mitad resolucion');
subplot(2,3,6), imshow(isub), title('Imagen central');
