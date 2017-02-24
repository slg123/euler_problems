#!/usr/bin/perl

# You have an array of numbers. 
# Each number but one appears an even number of times. 
# Identify the number that appears an odd number of times. 

my @a = ( 10, 10, 20, 20, 30, 30, 30, 10, 10, 9, 9, 8, 8, 7, 7, 6, 6 ); 

my @unique;

my %seen;

for my $n (@a) {
    if (!$seen{$n}) {
        push @unique, $n;
        $seen{$n} = 1;
    }
}

sub get_num {
    my $n = shift;
    my $count = 0;

    for my $i (@a) {
        if ($n == $i) {
            $count++;
        }
    }
    return $count;
}

my $wanted; 
for (@unique) {
    my $n = get_num($_);
    if ($n % 2 != 0) {
        $wanted = $_; 
    }
}

print $wanted, "\n"; 
