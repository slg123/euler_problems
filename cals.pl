#!/usr/bin/perl -w

# cals.pl - simple calorie calculator that reads in a text datafile
#           and calculates calories, protein and fat totals. 

use strict;

my @quantities;
my @calories;
my @protein;
my @fat;

chomp(my $weekday = `date +%a`);  # Sun Mon Tue Wed Thu Fri Sat
my $daily_record_end = $weekday." END"; 

my $filename = 'cals.txt'; 

sub get_daily_data {
    open my $fh, '<', $filename or die "can't open $! for reading.";    

    while (<$fh>) {
        my @column = split ' '; 
        next if $_ =~ /^#/; 

        push @quantities, $column[2] if defined $column[2]; 
        push @calories,   $column[5] if defined $column[5]; 
        push @protein,    $column[6] if defined $column[6]; 
        push @fat,        $column[7] if defined $column[7]; 

        last if $_ =~ /$daily_record_end/; 
    }
}

my $total_calories;
my $total_protein;
my $total_fat;

sub calc_daily_calories {
    for my $i (0 .. $#quantities) {
        $total_calories += $quantities[$i] * $calories[$i];
        $total_protein  += $quantities[$i] * $protein[$i];
        $total_fat      += $quantities[$i] * $fat[$i];
    }
}

get_daily_data(); 
calc_daily_calories(); 

print "total calories: ".$total_calories."\n"; 
print "total protein:  ".$total_protein."\n"; 
print "total fat:      ".$total_fat."\n"; 

open my $fh, '>>', $filename or die "can't open $! for appending."; 
print $fh "# Daily totals: $total_calories calories, $total_protein g protein, $total_fat g fat"; 
close $fh;
