#!/usr/bin/perl

# prime_gap.pl - find gaps between prime numbers 

use strict;
use warnings;
use Memoize;

memoize('is_prime');

sub is_prime {
    my $n = shift;
    for (my $i=2; $i<$n; $i++) {
        if ($n % $i == 0 && $i != $n) {
            return 0;
        }
    }
    return 1;
}

sub prime_distance {
    my $prev = shift;
    my $curr = shift;
    return $curr - $prev;
}

my $curr = 0;
my $prev = 0;
my $prime_gap = 0;

for (my $i=0; $i<=99999999999999999999999; $i++) {
    if (is_prime($i)) {
        $curr = $i;
        $prime_gap = prime_distance($prev, $curr);
        if ($prime_gap > 100) {
            print "$prev - $curr : $prime_gap\n";
        }
        $prev = $curr;
    }
}
