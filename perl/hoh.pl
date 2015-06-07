#!/usr/bin/perl -w
use strict;

my %hoh = (
    'Dr. Watson' =>
        {
            street   => '221b Baker St.',
            district => 'Chelsea',
            city     => 'London',
            country  => 'England',
        },

    'Sam Gamgee' =>
        {
            street   => 'Bagshot Row',
            city     => 'Hobbiton',
            country  => 'The Shire',
        },
);

sub __dump__ {
    my @attrs = qw( street district city country ); 
    my @people = ( 'Dr. Watson', 'Sam Gamgee' ); 
    for my $person ( @people ) {
        for my $attr ( @attrs ) {
            if ( defined $hoh{$person}->{$attr} ) {
                print $hoh{$person}->{$attr}, "\n"; 
            }
        }
    }
}

__dump__; 
