#!/usr/bin/perl

use strict;
use warnings;

sub get_decimal {
    my $d = shift;
    my $n = 1;
    my $count=0;
    while ($n%$d != 0) {
        my $first = $n%$d;
        $n *= 10;
        my $val = $n % $d;
        my $decimal = ($val * 10) / $d;
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

for (my $i=1; $i<=1000; $i++) {
    print "\n"; 
    get_decimal($i); 
}

