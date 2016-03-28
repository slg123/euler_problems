#!/usr/bin/perl

sub dec2bin {
    my $n = shift;
    my @bin;
    while (int($n) > 0) {
        if ($n % 2 == 0) { 
            push @bin, 0; 
        } else {
            push @bin, 1;
        }
        $n = $n / 2; 
    }
    return reverse(@bin);
}

print dec2bin(42), "\n"; 
print dec2bin(512), "\n"; 
print dec2bin(1024), "\n"; 
print dec2bin(1138), "\n"; 
print dec2bin(2016), "\n"; 
