#!/usr/bin/perl

use strict; 
use warnings;

my $final = 0; 
my $final_chain = 0; 
my $tmp = 0; 
my $len = 0; 

for ( my $i = 1; $i <= 1000000; $i++ ) {
    $len = get_collatz_chain($i); 
    if ( $len > $tmp ) {
        $tmp = $len; 
        $final = $i; 
        $final_chain = $len; 
    }
}
print "$final $final_chain\n"; 
print get_collatz_chain(13), "\n"; 

sub get_collatz_chain {
    my $n = shift;
    my @chain_nodes; 
    push @chain_nodes, $n; 
    while ( $n != 1 ) {
        if ( $n % 2 == 0 ) {
            push @chain_nodes, $n; 
            $n = $n / 2;
        } else {
            $n = ( $n * 3 ) + 1; 
        }
    }
    push @chain_nodes, 1;
    my $length = $#chain_nodes; 
    return $length; 
}


