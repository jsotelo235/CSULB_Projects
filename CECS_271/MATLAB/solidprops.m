function [volume, surfaceArea] = solidprops(length, width, height)
surfaceArea = 2*(width*length+height*length+height*width);
volume = width*height*length;
end