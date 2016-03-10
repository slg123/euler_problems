#!/usr/bin/perl

use strict;
use warnings;

use ExtUtils::Installed;

my $inst = ExtUtils::Installed->new();
my @modules = $inst->modules();
foreach my $module (@modules) {
    print $module ." - ". $inst->version($module)."\n"; 
}
