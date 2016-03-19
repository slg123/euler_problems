#!/usr/bin/perl

use 5.016;
use warnings;
use autodie;

my %cats = map { $_ => 1 } qw( Jack Brad Mars Grumpy );

while (my ($key, $value) = each %cats) {
    print "$key $value\n"; 
}

my %addresses = (
         '1027 foo place', 'NY USA',
         '111 bar plaza',  'NY USA',
         '999 fifth avenue', 'NY USA',
);

my %canada_addresses = (
        '123 maple way', 'Toronto ON Canada',
        '93 hoose boot', 'Toronto ON Canada',
        '55 hockey st', 'Toronoto ON Canada',
);

#
# merge two hashes with some forbidden kung-fu:
#
@addresses{ keys %canada_addresses } = values %canada_addresses;


while (my ($key, $value) = each %addresses) {
    print "$key $value\n"; 
}


        

