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
    my @column = split ' '; 
    next if $_ =~ /^#/; 
    push @quantities, $column[2] if defined $column[2]; 
    push @calories,   $column[5] if defined $column[5]; 
    push @protein,    $column[6] if defined $column[6]; 
    push @fat,        $column[7] if defined $column[7]; 
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
