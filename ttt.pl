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
    my $name = shift;
    my @n = split("", $name); 
    my $total = 0; 
    foreach my $i (@n) {
        $total += $h{$i}; 
    }
    return $total; 
}

print(get_name_value("NINA"), "\n"); 
print(get_name_value("SCOTT"), "\n");
print(get_name_value("BUGS"), "\n");
print(get_name_value("BUNNY"), "\n");


