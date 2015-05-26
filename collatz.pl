#!/usr/bin/perl

use strict;
use warnings;

my $end = 0;
my $tmp = 0; 
for (my $i = 1000001; $i > 2; $i--) {
    my $chain = 0; 
    my $n = $i; 
    while ($n != 1) {
        $n = $n%2==0 ? $n/2 : $n*3+1; 
        $chain++; 
    }
    if ($chain > $tmp) {
        $tmp = $chain;
        $end = $i;
    }
}
print $end, "\n"; 
