package GD;

# Copyright 1995 Lincoln D. Stein.  See accompanying README file for
# usage information

#           WIN32::GD
#           ---------
#
#   Alterations necessary for use in Win32 Perl made by
#   Dave Roth <roth@panda.dnr.state.mi.us>
#

require Exporter;
require DynaLoader;
require AutoLoader;

@ISA = qw(Exporter DynaLoader);
# Items to export into callers namespace by default. Note: do not export
# names by default without a very good reason. Use EXPORT_OK instead.
# Do not simply export all your public functions/methods/constants.
@EXPORT = qw(
	gdBrushed
	gdDashSize
	gdMaxColors
	gdStyled
	gdStyledBrushed
	gdTiled
	gdTransparent
    gdSmallFont
    gdLargeFont
    gdMediumBoldFont
    gdTinyFont
);
sub AUTOLOAD {
    # This AUTOLOAD is used to 'autoload' constants from the constant()
    # XS function.  If a constant is not found then control is passed
    # to the AUTOLOAD in AutoLoader.

    local($constname);
    ($constname = $AUTOLOAD) =~ s/.*:://;
    $val = constant($constname, @_ ? $_[0] : 0);
    if ($! != 0) {
	if ($! =~ /Invalid/) {
	    $AutoLoader::AUTOLOAD = $AUTOLOAD;
	    goto &AutoLoader::AUTOLOAD;
	}
	else {
	    ($pack,$file,$line) = caller;
	    die "Your vendor has not defined GD macro $pack\:\:$constname, used at $file line $line.\n";
	}
    }
    eval "sub $AUTOLOAD { $val }";
    goto &$AUTOLOAD;
}

bootstrap GD;

# Preloaded methods go here.
sub GD::gdSmallFont {
    return &GD::Font::Small;
}

sub GD::gdLargeFont {
    return &GD::Font::Large;
}

sub GD::gdMediumBoldFont {
    return &GD::Font::MediumBold;
}

sub GD::gdTinyFont {
    return &GD::Font::Tiny;
}

# This is a C callback
sub GD::fileno {
    local($fh) = @_;
    local($package) = caller;
    return fileno "$package\:\:$fh";
}

# This handles the Gif method
#   Modified for Win32::GD by Roth <rothd@infowire.com> 96.05.15
#
sub GD::Image::gif {
    my ($self, $File) = @_;
    my($Return);
    if ($File eq ""){
        $File = "\&STDOUT";
    }
    if(open(FILE, ">" . $File)){
        binmode(FILE);
        $self->__Gif(fileno(FILE));
        close(FILE);
        $Return = 1;
    }else{
        print "FAILED: opening $File\n";
        $Return = 0;
    }
    return $Return;
}

# This handles creation of gd data
#   Modified for Win32::GD by Roth <rothd@infowire.com> 96.05.15
#
sub GD::Image::gd {
    my ($self, $File) = @_;
    my($Return);
    if ($File eq ""){
        $File = "\&STDOUT";
    }
    if(open(FILE, ">" . $File)){
        binmode(FILE);
        $self->__Gd(fileno(FILE));
        close(FILE);
        $Return = 1;
    }else{
        print "FAILED: opening $File\n";
        $Return = 0;
    }
    return $Return;
}

### The polygon object ###
# create a new polygon
sub GD::Polygon::new {
    return bless { 'length'=>0,'points'=>[] },GD::Polygon;
}

# automatic destruction of the polygon
sub GD::Polygon::DESTROY {
    my $self = shift;
    undef $self->{'points'};
}

# add an x,y vertex to the polygon
sub GD::Polygon::addPt {
    my($self,$x,$y) = @_;
    push(@{$self->{'points'}},[$x,$y]);
    $self->{'length'}++;
}

# get a vertex
sub GD::Polygon::getPt {
    my($self,$index) = @_;
    return () unless ($index>=0) && ($index<$self->{'length'});
    return @{$self->{'points'}->[$index]};
}

# change the value of a vertex
sub GD::Polygon::setPt {
    my($self,$index,$x,$y) = @_;
    unless (($index>=0) && ($index<$self->{'length'})) {
	warn "Attempt to set an undefined polygon vertex";
	return undef;
    }
    @{$self->{'points'}->[$index]} = ($x,$y);
    1;
}

# return the total number of vertices
sub GD::Polygon::length {
    my $self = shift;
    return $self->{'length'};
}

# return the array of vertices.
# each vertex is an two-member (x,y) array
sub GD::Polygon::vertices {
    my $self = shift;
    return @{$self->{'points'}};
}

# return the bounding box of the polygon
# (smallest rectangle that contains it)
sub GD::Polygon::bounds {
    my $self = shift;
    my($top,$bottom,$left,$right) = @_;
    $top =    99999999;
    $bottom =-99999999;
    $left =   99999999;
    $right = -99999999;
    my $v;
    foreach $v ($self->vertices) {
	$left = $v->[0] if $left > $v->[0];
	$right = $v->[0] if $right < $v->[0];
	$top = $v->[1] if $top > $v->[1];
	$bottom = $v->[1] if $bottom < $v->[1];
    }
    return ($left,$top,$right,$bottom);
}

# delete a vertex, returning it, just for fun
sub GD::Polygon::delete {
    local($index) = @_;
    local($vertex) = splice(@{$self->{'points'}},$index,1);
    return @$vertex;
}

# translate the polygon in space by deltaX and deltaY
sub GD::Polygon::offset {
    my($self,$dh,$dv) = @_;
    my $size = $self->length;
    my($i);
    for ($i=0;$i<$size;$i++) {
	my($x,$y)=$self->getPt($i);
	$self->setPt($i,$x+$dh,$y+$dv);
    }
}

# map the polygon from sourceRect to destRect,
# translating and resizing it if necessary
sub GD::Polygon::map {
    my($self,$srcL,$srcT,$srcR,$srcB,$destL,$destT,$destR,$destB) = @_;
    my($factorV) = ($destB-$destT)/($srcB-$srcT);
    my($factorH) = ($destR-$destL)/($srcR-$srcL);
    my($vertices) = $self->length;
    my($i);
    for ($i=0;$i<$vertices;$i++) {
	my($x,$y) = $self->getPt($i);
	$x = int($destL + ($x - $srcL) * $factorH);
	$y = int($destT + ($y - $srcT) * $factorV);
	$self->setPt($i,$x,$y);
    }
}

# Autoload methods go after __END__, and are processed by the autosplit program.
1;
__END__
