.table
int batata_0
int temp_1
.code
bake:
slt $0, batata_0, 100
slt $1, 20, batata_0
and $2, $0, $1
seq $3, batata_0, 10
or $4, $2, $3
brz if_label_0, $4
mov temp_1, $4
jump if_label_1
if_label_0:
mul $5, batata_0, 2
inttofl $6, $5
inttofl $7, 3
inttofl $8, 9
mul $9, 5.1, $8
inttofl $10, 3
div $11, $9, $10
add $12, $7, $11
inttofl $13, 2
sub $14, $12, $13
add $15, $6, $14
fltoint $16, $15
mov temp_1, $16
if_label_1:
print temp_1
print ' '
print 'b'
print 'a'
print 't'
print 'a'
print 't'
print 'a'
print 's'
print ' '
print 'a'
print 's'
print 's'
print 'a'
print 'd'
print 'a'
print 's'
println
return 0
main:
print 'D'
print 'i'
print 'g'
print 'i'
print 't'
print 'e'
print ' '
print 'u'
print 'm'
print ' '
print 'i'
print 'n'
print 't'
print 'e'
print 'i'
print 'r'
print 'o'
print ':'
print ' '
scani batata_0
print 'O'
print ' '
print 'i'
print 'n'
print 't'
print 'e'
print 'i'
print 'r'
print 'o'
print ' '
print 'd'
print 'i'
print 'g'
print 'i'
print 't'
print 'a'
print 'd'
print 'o'
print ' '
print 'f'
print 'o'
print 'i'
print ':'
print ' '
println batata_0
call bake
pop $0
print 'E'
print 'n'
print 'c'
print 'e'
print 'r'
print 'r'
print 'a'
print 'n'
print 'd'
print 'o'
print ' '
print 'e'
print 'x'
print 'e'
print 'c'
print 'u'
print 'Ã'
print '§'
print 'Ã'
print '£'
print 'o'
print '.'
print '.'
print '.'
return 0
return 0
