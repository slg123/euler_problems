#!/usr/bin/perl

use strict;
use warnings;

my @n = (); 

my $f = 'names.txt';
open my $fh, '<', $f or die 'cannot open: $!';
while (<$fh>) {
    my @fields = split(',', $_);
    for (@fields) {
        s/\"//; 
        s/\"//; 
        push @n, $_; 
    }
}

my @sorted = sort { $a cmp $b } @n;
my @name_scores = (); 
my $posn = 1;
for (@sorted) {
    push @name_scores, ($posn * word_value($_)); 
    $posn++; 
}

sub word_value {
    my $word = shift;
    my @wordarr = split('', $word); 
    my %h;
    @h{'A' .. 'Z'} = (1 .. 26);
    my $total = 0;
    for my $i (@wordarr) {
        $total += $h{$i};
    }
    return $total;
}

my $t = 0;
for (@name_scores) {
    $t += $_;
}
print $t, "\n"; 

