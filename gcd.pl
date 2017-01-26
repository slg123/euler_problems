#!/usr/bin/perl 

use strict;
#use warnings;
use bigint;
use Memoize;

memoize 'factorial';

sub factorial {
    my $n = shift;
    return 1, if $n == 1;
    return $n * factorial($n-1);
}

sub gcd {
    my $m = shift;
    my $n = shift;

    if ($m == 0 && $n == 0) {
        return -1;
    }

    if ($m < 0) { $m = -$m };
    if ($n < 0) { $n = -$n };

    my $r;
    while ($n) {
        $r = $m % $n;
        $m = $n;
        $n = $r;
    }
    return $m;
}

print gcd((factorial(2016)+1), factorial(2017)), "\n"; 
