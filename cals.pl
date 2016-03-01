#!/usr/bin/perl -w

# cals.pl - simple calorie calculator that reads in a text datafile
#           and calculates calories, protein and fat totals. 

use strict;

my @quantities;
my @calories;
my @protein;
my @fat;

#--------------------------------------------------------------
# format (cals.txt):
#  item_name  - quantity quantity_type - calories protein fat
# 
# example:
# chocolate_milk  - 1 serving  -  140    13    4.5
# coffee          - 1 serving  -   70     6    2
# 
#--------------------------------------------------------------
my $filename = 'cals.txt'; 

sub get_data {
    open my $fh, '<', $filename or die "can't open $! for reading.";    

    while (<$fh>) {
        my @column = split ' '; 
        next if $_ =~ /^#/; 

        push @quantities, $column[2] if defined $column[2]; 
        push @calories,   $column[5] if defined $column[5]; 
        push @protein,    $column[6] if defined $column[6]; 
        push @fat,        $column[7] if defined $column[7]; 

        #last if $_ =~ /$daily_record_end/; 
    }
}

my $total_calories;
my $total_protein;
my $total_fat;

sub calc_calories {
    for my $i (0 .. $#quantities) {
        $total_calories += $quantities[$i] * $calories[$i];
        $total_protein  += $quantities[$i] * $protein[$i];
        $total_fat      += $quantities[$i] * $fat[$i];
    }
}

sub print_totals {
    print "total calories: ".$total_calories."\n"; 
    print "total protein:  ".$total_protein."\n"; 
    print "total fat:      ".$total_fat."\n"; 
}

sub update_datafile {
    chomp(my $weekday = `date +%a`);  # Sun Mon Tue Wed Thu Fri Sat
    my $daily_record_end = "# ".$weekday." END"; 
    open my $fh, '>>', $filename or die "can't open $! for appending."; 
    print $fh $daily_record_end; 
    print $fh "\n# Daily totals: $total_calories calories, $total_protein g protein, $total_fat g fat"; 
    close $fh;
}

sub main() {
    get_data();
    calc_calories(); 
    print_totals();
    update_datafile(); 
}

main(); 
