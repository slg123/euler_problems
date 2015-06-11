#!/usr/bin/perl

use strict;
use warnings;

# Graham Cumming's version of Turing's Vigenere cypher.

my @alpha = split('', 'ABCDEFGHIJKLMNOPQRSTUVWXYZ');

my %frequencies = ( 'A' => 84, 'B' => 23, 'C' => 21, 'D' => 46, 'E' => 116,
                    'F' => 20, 'G' => 25, 'H' => 49, 'I' => 76, 'J' => 2,
                    'K' => 5,  'L' => 38, 'M' => 34, 'N' => 66, 'O' => 66,
                    'P' => 15, 'Q' => 2,  'R' => 64, 'S' => 73, 'T' => 81,
                    'U' => 19, 'V' => 11, 'W' => 21, 'X' =>  2, 'Y' => 24,
                    'Z' => 3 );

foreach my $a (keys %frequencies) {
    $frequencies{$a} /= 1000;
}

# slurp in the sample file and process it 
my $file = $ARGV[0] || 'sample'; 
my $keylen = $ARGV[1] || 6; 
local( $/, *FH );
open( FH, $file ) or die "Cannot open: $!"; 
my $text = join( '', <FH> ); 
$text =~ s/\R//g; 
$text =~ s/ //g; 
my @cipher = split('', $text); 

my %bans;

foreach my $a (keys %frequencies) {
    my $x = (25 * $frequencies{$a}) / (1 - $frequencies{$a});
    $x = (20*log($x))/log(10);
    $bans{ord($a) - ord('A')} = int($x);
}

for my $key (@alpha) {
    print "$key: ";
    my $k = ord($key) - ord('A');
    for my $col (0..$keylen-1) {
        my $i = $col;
        my $evidence = 0;
        while ($i <= $#cipher) {
            my $c = ord($cipher[$i]) - ord('A');
            my $diff = $c - $k;
            if ($diff < 0) {
                $diff += 26;
            }
            $evidence += $bans{$diff};
                       $i += $keylen;
        }

        if ($evidence > 0) {
            print sprintf("%4d ", $evidence);
        } else {
            print "   . ";
        }
    }
    print "\n";
}
