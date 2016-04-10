#!/usr/bin/perl

use strict;
use warnings;

sub fraction_to_decimal {
    my $n = shift;
    my $d = shift;
    if ($d == 0) {
        exit;
    }
    my $count = 0;
    while ($n % $d != 0) {
        my $first = $n%$d;      # need first divisor       
        $n *= 10;
        my $remainder = $n % $d;  
        my $decimal = ($remainder * 10) / $d;
        if ($count == 0) {   
            print $first;
        }
        print int($decimal);
        $count++;
        if ($count > 200) {  
            return;
        }
    }
}

sub longest_repeating_sequence {
    # find the longest repeating integer sequence
    # for the fractions from 1/1 to 1/1000
}

for (my $i=1; $i<=1000; $i++) {
    print "\n"; 
    my $n = 1;
    print fraction_to_decimal($n, $i); 
}

