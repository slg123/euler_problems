#!/usr/bin/perl

use strict;
use warnings;

sub b2d {
    my $str = shift; 
    my @bits = split('', $str); 
    my $sum = 0;
    my $posn = @bits;
    for my $i (@bits) {
        $posn--;
        if ($i eq 1) {
            $sum += (2**$posn); 
        }
    }
    return $sum; 
}

print b2d(1101), "\n"; 
print b2d(11010000), "\n"; 
print b2d(11111111); 
