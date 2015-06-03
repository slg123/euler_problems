#!/usr/bin/perl -w

use strict;
use bigint;
use Memoize;

memoize 'fibonacci';
memoize 'digitcount'; 

sub fibonacci {
    my $n = shift;
    return undef if $n < 0;
    return 0 if $n == 0;
    return 1 if $n == 1; 
    return fibonacci($n-1) + fibonacci($n-2);
}

sub digitcount {
    my $n = shift;
    my @s = split '', $n;
    return $#s+1; 
}


for (my $i=0; $i<10000; $i++) {
    if (digitcount(fibonacci($i)) == 1000) {
        print "term : $i\n"; 
        exit; 
    }
}
