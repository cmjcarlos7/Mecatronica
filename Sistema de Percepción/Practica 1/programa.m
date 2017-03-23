%   Practica 1. Sistema de percepción
%   Realizado con Matlab 2016b
%   Master Ingeniería Mecatrónica Universidad de Málaga
%   Realizado: Juan Carlos Contreras Márquez
%   Fecha: 23/03/2017

%   Llamo a la funcion suavizado y le paso el nombre de la imagen 
%   y un parametro: (0-Ruido Gaussiano, 1-Ruido salt & pepper 
im = suavizado ('blood.tif', 1);
%   Recibo 0 si las imagenes mostradas han usado el filtro gaussiano
%   Recibo 1 si las imagenes mostradas han usado el filtro salt&pepper
