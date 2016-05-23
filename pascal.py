#!/usr/bin/python

# pascal's triangle up to row 20, no pretty printing

n=20
last_row = []
this_row = [1]
for i in range(n):
    last_row = this_row
    this_row = [1]
    for j in range(i):
        this_row.append(last_row[j]+last_row[j+1])
    this_row.append(1)
    print this_row

""" adapted from the following perl:

sub ton_pascal {
    my $rows = shift;
    my $last_row = [];
    my $this_row = [1];

    last unless ($rows > 0);
    print "1\n";   # first row
    for (my $i=1; $i<$rows; $i++) {
        $last_row = $this_row;
	$this_row = [1];
	for (my $j=1; $j<$i; $j++) {
	    push(@$this_row, $last_row->[$j-1]+$last_row->[$j]);
	}
	push(@$this_row, 1);
	print join(' ',@$this_row)."\n";
    }
}

"""




