#!/usr/bin/perl

my %h; 

@h{'A' .. 'Z'} = (1 .. 26);

while (my ($key, $value) = each %h) {
    print "$key $value\n";
}

sub get_value {
    my $item = shift;
    print $h{$item};
    print "\n"; 
}

get_value('B');
get_value('U');
get_value('G');


