#!/usr/local/bin/perl

use GD;

$| = 1;

$File = "\&STDOUT" unless ($File) = @ARGV;

print "Content-type: image/gif\n\n";
        
# create a new image
$im = new GD::Image(100,100);

# allocate some colors
$white = $im->colorAllocate(255,255,255);
$black = $im->colorAllocate(0,0,0);       
$red = $im->colorAllocate(255,0,0);      
$blue = $im->colorAllocate(0,0,255);
$green = $im->colorAllocate(0,255,0);

# make the background transparent and interlaced
$im->transparent($white);
$im->interlaced('true');

# Put a black frame around the picture
$im->rectangle(0,0,99,99,$black);

# Draw a blue oval
$im->arc(50,50,95,75,0,360,$blue);

# And fill it with red
$im->fill(50,50,$red);

# Add the creative string!...
$im->string(gdSmallFont,23,40,"Win32::GD",$green);
$im->string(gdSmallFont,23,50,"  Rules!",$green);

# Convert the image to GIF and print it on standard output
if ($im->gif($File)){
    print STDERR "\n\nThe file was successfully dumped to \"$File\"\n";
}else{
    print STDERR "\n\nThe file failed to be written to \"$File\"\n";
}


