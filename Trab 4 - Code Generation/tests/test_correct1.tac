.table
int list_value_0
int batata_0
int n_1
int k_1
int l_1
int j_1
int g_1
int i_1
int temp_1
int mylist_1
int mylist_size_1 = 0
int batata_1
int i_3
int i_6
int n_7
int n_size_7 = 0
int temp_list_7
int temp_list_size_7 = 0
int temp_list2_7
int temp_list2_size_7 = 0
int listread_8
int listread_size_8 = 0
int n_8
.code
list_input:
mov $0, 0
mov $1, $0
mov i_1, 0
for_label_0:
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
print ' '
print 'p'
print 'a'
print 'r'
print 'a'
print ' '
print 'a'
print 'r'
print 'm'
print 'a'
print 'z'
print 'e'
print 'n'
print 'a'
print 'r'
print ' '
print 'n'
print 'a'
print ' '
print 'l'
print 'i'
print 's'
print 't'
print 'a'
println
scani temp_1
mov $3, mylist_size_1
add $3, $3, 1
mema $2, $3
mov $2[0], temp_1
mov $1, $2
add $4, i_1, 1
mov i_1, $4
slt $5, i_1, #4
brnz for_label_0, $5
div $6, 2, 2
add $7, 1, $6
inttofl $8, $7
inttofl $9, 3
add $10, $9, 5.1
mul $11, 90, 2
inttofl $12, $11
sub $13, $10, $12
add $14, $8, $13
fltoint $15, $14
mov batata_1, $15
print 'L'
print 'i'
print 's'
print 't'
print 'a'
print ' '
print 'a'
print 'r'
print 'm'
print 'a'
print 'z'
print 'e'
print 'n'
print 'a'
print 'd'
print 'a'
println
return $1
return 0
check_list:
sleq $0, list_value_0, #0
brz if_label_1, $0
return 1
jump if_label_2
if_label_1:
return 0
if_label_2:
return -1
return 0
double_list:
mul $0, #0, 2
return $0
return 0
test_list:
print 'P'
print 'r'
print 'i'
print 'm'
print 'e'
print 'i'
print 'r'
print 'o'
print ' '
print 'e'
print 'l'
print 'e'
print 'm'
print 'e'
print 'n'
print 't'
print 'o'
print ' '
print 'd'
print 'a'
print ' '
print 'l'
print 'i'
print 's'
print 't'
print 'a'
print ':'
print ' '
mov $0, #0[0]
println $0
mov batata_0, 0
mov $1, #0[0]
mov list_value_0, $1
return 0
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
print 't'
print 'a'
print 'm'
print 'a'
print 'n'
print 'h'
print 'o'
print ' '
print 'p'
print 'a'
print 'r'
print 'a'
print ' '
print 'a'
print ' '
print 'l'
print 'i'
print 's'
print 't'
print 'a'
print ':'
print ' '
scani n_8
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
println n_8
param 3
param 2
param 4
param 1
param n_8
call list_input, 5
pop $0
mov $1, $0
param $1
call test_list, 1
pop $2
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
println
println
