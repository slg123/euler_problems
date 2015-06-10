#!/usr/bin/perl

use strict;
use warnings;

#
# whole, float and integer check shamelessly lifted from:
#
# http://www.perl.com/doc/FMTEYEWTK/is_numeric.html
#


#
# not my code.
#
use constant {
    SUCCESS       => 0,
    FAIL          => -1,
    TRUE          => 1,
    FALSE         => 0,
    NULL          => ""
};
# eonmc


my @nums = ( 1, 23, "cat", 2.23, 1.096, 1.111, 23.333, "a", "burgundy" ); 

sub test1 {
    for (@nums) {
        if (isNumeric($_)) {
            print "$_ is numeric\n";
        } else {
            print "$_ is not numeric\n"; 
        }
    }
}

sub test2 {
    for (@nums) {
        if (is_numeric($_)) {
            print "$_ is numeric\n";
        } else {
            print "$_ is not numeric\n"; 
        }
    }
}

sub test3 {
    for (@nums) {
        if (easiest($_)) {
            print "$_ is numeric\n";
        } else {
            print "$_ is not numeric\n"; 
        }
    }
}

# not my code
sub isNumeric {
    my $n = shift;
# Return 1 if numeric
    return ( ( $n !~ /^[+|-]?\d+$/ ) && ( $n !~ /^[+|-]?\d*\.\d+$/ ) ? FALSE : TRUE);
}
# eonmc

sub is_numeric {
    my $n = shift;
    if (is_whole_number($n) || is_integer($n) || is_float($n)) {
        return TRUE;
    }
    return FALSE;
}


sub is_whole_number {
    return 1, if $_[0] =~ /^\d+$/;
    return 0;
}

sub is_integer {
    return 1, if $_[0] =~ /^[+-]?\d+$/; 
    return 0;
}

sub is_float {
    return 1, if $_[0] =~ /^[+-]?\d+\.?\d*$/; 
    return 0;
}


#
# we should probably go with this, though... 
#
sub easiest {
    my $n = shift;
    return 1, if $n += 0;
    return 0;
}

sub _main_ {
    test1;
    print "\n"x3;
    test2;
    print "\n"x3;
    test3;
}

_main_; 


