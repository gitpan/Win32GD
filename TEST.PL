
    use GD;

    print "Content-type: image/gif\n\n";

    $File = "\&STDOUT" unless ($File) = @ARGV;

    open(GRFILE, "< test.gif") || die;
    binmode GRFILE;
    $im = newFromGif GD::Image(GRFILE) || die;

    $white = GetColor($im, 255, 255, 255);
    $black = GetColor($im, 0, 0, 0);
    $red = GetColor($im, 255, 127, 127);
    $blue = GetColor($im, 0, 0, 255);
    $green = GetColor($im, 0, 255, 0);
    $darkgreen = GetColor($im, 0, 127, 0);
    $verydarkgreen = GetColor($im, 0, 16, 0);

        #foreach(<GRFILE>){print;}
    close (GRFILE);

        # Convert the image to GIF and print it on standard output
    ($Ix, $Iy) = $im->getBounds();
    print "\nImage is $Ix pixels wide and $Iy pixels tall.\n\n";

    $Fx = GD::Font::width(gdLargeFont);
    $Fy = GD::Font::height(gdLargeFont);

    $TotalCols = int($Ix/$Fx);
    $TotalRows = int($Iy/$Fy);

    Draw("Win32::GD Rules!");

    # Convert the image to GIF and print it on standard output
    if ($im->gif($File)){
        print STDERR "\n\nThe file was successfully dumped to \"$File\"\n";
    }else{
        print STDERR "\n\nThe file failed to be written to \"$File\"\n";
    }

sub GetColor{
    my($Gif, $Red, $Green, $Blue) = @_;
    my($Color);

    $Result = $Gif->colorAllocate($Red, $Green, $Blue);
    if ($Result == -1){
        $Result = $Gif->colorClosest($Red, $Green, $Blue);
    }
    return $Result;
}



sub Draw{
    my($String, $Row) = @_;
    my($X, $Y);
    my($Copy);

    $X = int( (int($TotalCols - length($String)) * $Fx) / 2);
    $Y = int( (int($TotalRows - 0) * $Fy) / 2);
    print "Printing \"$String\" at ($X, $Y).\n\n";


    $dX = length($String) * $Fx;
    $dY = $Fy;

    $Buffer = 6;

    $Copy = new GD::Image($dX + ($Buffer), $dY + ($Buffer));

    print "Copying a portion of the graphic to a buffer...\n";
    $Copy->copy($im, 0, 0, $X - ($Buffer/2),  $Y - ($Buffer/2), $dX + ($Buffer), $dY + ($Buffer));

    print "Drawing a rectangle and filling it in...\n";
    $im->filledRectangle($X - ($Buffer * 2), $Y - ($Buffer * 2), $X + $dX + ($Buffer * 2) , $Y + $dY + ($Buffer * 2), $blue);

    print "Drawing a border around the rectangle...\n";
    $im->rectangle($X - ($Buffer * 2), $Y - ($Buffer * 2), $X + $dX + ($Buffer * 2), $Y + $dY + ($Buffer * 2), $green);

    print "Copying the saved buffer back to the graphic...\n";
    $im->copy($Copy, $X - ($Buffer/2), $Y - ($Buffer/2), 0, 0, $dX + ($Buffer), $dY + ($Buffer));

    print "Drawing a border around the copied area...\n";
    $im->rectangle($X - ($Buffer/2) - 1, $Y - ($Buffer/2) - 1, $X + $dX + ($Buffer) - ($Buffer/2), $Y + $dY + ($Buffer) - ($Buffer/2), $black);

    print "Printing text to graphic...\n";
    $im->string(gdLargeFont, $X + 2, $Y + 2, $String, $verydarkgreen);
    $im->string(gdLargeFont, $X + 1, $Y + 1, $String, $darkgreen);
    $im->string(gdLargeFont, $X, $Y, $String, $green);

}


