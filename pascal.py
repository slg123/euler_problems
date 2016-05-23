#!/usr/bin/python

def pascals_triangle(n):
    last_row = []
    this_row = [1]
    for i in range(n):
        last_row = this_row
        this_row = [1]
        for j in range(i):
            this_row.append(last_row[j]+last_row[j+1])
        this_row.append(1)
        print this_row

if __name__ == "__main__":
    pascals_triangle(25)

""" adapted from the following perl:

 http://www.perlmonks.org/?node_id=175586

 Author: Ton Hospel, original Perl solution. 

 This solution eschews the binomial theorem for a simpler (and faster) method - adding
 numbers from the previous row. 

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




