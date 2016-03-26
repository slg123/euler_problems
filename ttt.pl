#!/usr/bin/perl

use strict;
use warnings;
use autodie;

my %h; 

@h{'A' .. 'Z'} = (1 .. 26);

while (my ($key, $value) = each %h) {
    print "$key $value\n";
}

sub get_name_value {
    my @n = split("", shift); 
    my $total = 0; 
    foreach my $i (@n) {
        $total += $h{$i}; 
    }
    return $total; 
}

my @names = qw( NINA SCOTT BUGS BUNNY );
for my $name(@names) {
    print "value for: $name == ", (get_name_value($name), "\n"); 
}

