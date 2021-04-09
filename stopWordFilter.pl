#perl stopWordFilter.pl < in.txt > out.txt
use strict;
use warnings;
binmode STDIN;
binmode STDOUT;
my $text;
while(<>){
	$text .= $_;
}
$text =~ s/^a .*?\r\n//gm;
$text =~ s/^.*? a.*?\r\n//gm;
$text =~ s/^and .*?\r\n//gm;
$text =~ s/^.*? and.*?\r\n//gm;
$text =~ s/^at .*?\r\n//gm;
$text =~ s/^.*? at.*?\r\n//gm;
$text =~ s/^b .*?\r\n//gm;#These are included because I had a lot of multiple choice phrases.
$text =~ s/^.*? b.*?\r\n//gm;
$text =~ s/^c .*?\r\n//gm;
$text =~ s/^.*? c.*?\r\n//gm;
$text =~ s/^d .*?\r\n//gm;
$text =~ s/^.*? d.*?\r\n//gm;
$text =~ s/^if .*?\r\n//gm;
$text =~ s/^.*? if.*?\r\n//gm;
$text =~ s/^is .*?\r\n//gm;
$text =~ s/^.*? is.*?\r\n//gm;
$text =~ s/^it.*?\r\n//gm;
$text =~ s/^.*? it.*?\r\n//gm;
$text =~ s/^of .*?\r\n//gm;
$text =~ s/^.*? of.*?\r\n//gm;
$text =~ s/^on .*?\r\n//gm;
$text =~ s/^.*? on.*?\r\n//gm;
$text =~ s/^that .*?\r\n//gm;
$text =~ s/^.*? that.*?\r\n//gm;
$text =~ s/^the .*?\r\n//gm;
$text =~ s/^.*? the.*?\r\n//gm;
$text =~ s/^to .*?\r\n//gm;
$text =~ s/^.*? to.*?\r\n//gm;
$text =~ s/^which .*?\r\n//gm;
$text =~ s/^.*? which.*?\r\n//gm;
print $text;