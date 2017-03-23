function  y  = suavizado( nombre, apartado )
%SUAVIZADO
%   Recibe como parametros el nombre de una imagen (nombre)
%   y el tipo de ruido a usar (0 - Ruido gaussiano.
%   1 - Ruido salt&pepper) y muestra por pantalla una figura
%   con la media (3x3), mediana y suavizado gaussiano.

%   Leo la imagen
img = imread(nombre);
sigma = 0.5;
%   Compruebo si el ruido es gaussiano
if apartado == 0
   % Se añade ruido gaussiano
   im_ruido = imnoise (img,'gaussian');
   %Se aplican los kernel del tamaño 3x3
   media_kernel = fspecial('average',[3 3]);
   gauss_kernel = fspecial('gaussian', [3 3 ],sigma);
   %Filtrado mediante convolucion de la imagen mediante un kernel
   im_out_media = filter2(media_kernel, im_ruido)/255;
   im_out_gauss = filter2(gauss_kernel, im_ruido)/255;
   %Filtro de la mediana
   im_out_mediana = medfilt2(im_ruido, [3 3]);
   %Muestro las imagenes
   subplot(2,2,1), imshow(im_ruido), title('Ruido Gaussiano');
   subplot(2,2,2), imshow(im_out_media), title('Suavizado Media');
   subplot(2,2,3), imshow(im_out_gauss), title('Suavizado Gaussiano');
   subplot(2,2,4), imshow(im_out_mediana), title('Suavizado Mediana');
   y = 0;
else
   %Se añade ruido Salt&Pepper
   im_ruido = imnoise(img, 'salt & pepper');
   %Se aplican los kernel del tamaño 3x3
   media_kernel = fspecial('average',[3 3]);
   gauss_kernel = fspecial('gaussian', [3 3 ],sigma);
   %Filtrado mediante convolucion de la imagen mediante un kernel
   im_out_media = filter2(media_kernel, im_ruido)/255;
   im_out_gauss = filter2(gauss_kernel, im_ruido)/255;
   %Filtro de la mediana
   im_out_mediana = medfilt2(im_ruido, [3 3]);
   %Muestro las imagenes
   subplot(2,2,1), imshow(im_ruido), title('Ruido Salt & Pepper');
   subplot(2,2,2), imshow(im_out_media), title('Suavizado Media');
   subplot(2,2,3), imshow(im_out_gauss), title('Suavizado Gaussiano');
   subplot(2,2,4), imshow(im_out_mediana), title('Suavizado Mediana');
    
   y = 1;
end
end

