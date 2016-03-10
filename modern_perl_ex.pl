#!/usr/bin/env perl

use strict;
use warnings;
use autodie;

my %addresses = (
    Leonardo => '123 Fib Place',
    Utako    => 'Cantor Hotel, Room 1',
    Lemmy    => '666 Motorhead Lane',
    Aleister => '93 Goodfellow Grove',
);

sub get_address_from_name { 
    return $addresses{+shift};
}

my $n = get_address_from_name('Leonardo'); 
print $n, "\n"; 

my @arr; 
sub get_all_addresses {
    foreach my $key (keys(%addresses)) {
        push @arr, get_address_from_name($key);
    }
    return @arr; 
}

my @n = get_all_addresses;
for my $i (@n) {
    print $i, "\n"; 
}

my @parsed_address = split(' ', $addresses{'Leonardo'});
print $parsed_address[2], "\n"; 
print $parsed_address[1], "\n"; 
print $parsed_address[0], "\n"; 

