$1 < 0 || $2 < 0 || $3 < 0 { 
	print "NO" 
	exit 1
}
$3 > $1 + $2 { print "NO" }
$3 < $1 + $2 { print "YES" }

