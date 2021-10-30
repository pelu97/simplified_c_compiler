.table
int a_0
float flag_0
float a_1
int b_1
float retorno_1
int flag_1
int i_1
float a_3
float calculo_3
int a_4
.code
inttofl $0, b_1
add $1, a_1, $0
mul $2, $1, 2.2
div $3, 5, 2
inttofl $4, $3
inttofl $5, 2
div $6, a_1, $5
mul $7, $4, $6
sub $8, $2, $7
inttofl $9, b_1
add $10, $8, $9
inttofl $11, b_1
mul $12, $11, 5.5
sub $13, $10, $12
inttofl $14, 78
inttofl $15, 30
mul $16, $15, a_1
div $17, 5, b_1
inttofl $18, $17
div $19, $16, $18
sub $20, $14, $19
add $21, $13, $20
mov retorno_1, $21
scani flag_1
mov i_1, 0
mul $22, i_1, 2
sleq $23, $22, 30
sub $24, i_1, 5
slt $25, $24, i_1
sub $26, 34, i_1
seq $27, $25, $26
not $28, $27
and $29, $23, $28
add $30, i_1, 1
mov i_1, $30
inttofl $31, 1
add $32, retorno_1, $31
scanf a_3
fltoint $33, a_3
mov calculo_3, $33
fltoint $34, calculo_3
