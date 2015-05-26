#!/usr/bin/perl

#
# not my code. perl solution to triangle sums, project euler
# problem number 18 - http://www.projecteuler.net
#

use strict;
use warnings;
use List::Util qw(max);

my @tri = map { chomp; [split] } <>;

for my $r (reverse 0..$#tri - 1) {
    for my $c (0..$#{$tri[$r]}) {
        $tri[$r][$c] += max ($tri[$r + 1][$c], $tri[$r + 1][$c + 1]);
    }
}
print $tri[0][0];

__DATA__
