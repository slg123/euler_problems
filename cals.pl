#!/usr/bin/perl -w

# cals.pl - simple calorie calculator that reads in a text datafile
#           and calculates calories, protein and fat totals. 

use strict;

my @quantities;
my @calories;
my @protein;
my @fat;

my $filename = 'cals.txt'; 
open my $fh, '<', $filename;    
while (<$fh>) {
    my @data = split ' '; 
    next if $_ =~ /^#/; 
    push @quantities, $data[2] if defined $data[2]; 
    push @calories,   $data[5] if defined $data[5]; 
    push @protein,    $data[6] if defined $data[6]; 
    push @fat,        $data[7] if defined $data[7]; 
}

my $total_calories;
my $total_protein;
my $total_fat;
for my $i (0 .. $#quantities) {
    $total_calories += $quantities[$i] * $calories[$i];
    $total_protein  += $quantities[$i] * $protein[$i];
    $total_fat      += $quantities[$i] * $fat[$i];
}

print "total calories: ".$total_calories."\n"; 
print "total protein:  ".$total_protein."\n"; 
print "total fat:      ".$total_fat."\n"; 
