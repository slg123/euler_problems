#!/usr/bin/perl -n
#
# Fischer-Krause ordered permutation generator,
# lifted from stackoverflow.com.
#
sub permute (&@) {
    my $code = shift;
    my @idx = 0..$#_;
    while ( $code->(@_[@idx]) ) {
        my $p = $#idx;
        --$p while $idx[$p-1] > $idx[$p];
        my $q = $p or return;
        push @idx, reverse splice @idx, $p;
        ++$q while $idx[$p-1] > $idx[$q];
        @idx[$p-1,$q]=@idx[$q,$p-1];
    }
}

my @s = qw( 0 1 2 3 4 5 6 7 8 9 ); 

sub permute (&@); 
my @a;
permute { push @a, "@_" } @s; 
my $count = 0;
for (@a) {
    $count++; 
    if ($count == 1000000) {
        print "$count : $_\n"; 
        exit;
    }
}
