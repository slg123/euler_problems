#!/usr/bin/perl

use strict;
use warnings;

# comparing two functions isNumeric and is_numeric
# my code is the function with three helper functions. 
# not sure if that's the way to go, what do you think?
# whole, float and integer check lifted from:
#
# http://www.perl.com/doc/FMTEYEWTK/is_numeric.html
#


use constant {
    SUCCESS       => 0,
    FAIL          => -1,
    TRUE          => 1,
    FALSE         => 0,
    NULL          => ""
};


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

sub isNumeric {
    my $n = shift;
# Return 1 if numeric
    return ( ( $n !~ /^[+|-]?\d+$/ ) && ( $n !~ /^[+|-]?\d*\.\d+$/ ) ? FALSE : TRUE);
}

sub is_numeric {
    my $n = shift;
    if ( is_whole_number($n) || is_integer($n) || is_float($n)) {
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

sub _main_ {
    test1;
    print "\n"x3;
    test2;
}

_main_; 


