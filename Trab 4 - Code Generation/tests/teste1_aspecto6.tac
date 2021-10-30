.table
int a_0
float flag_0
float a_1
int b_1
float retorno_1
int flag_1
float a_5
float calculo_5
int a_6
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
seq $22, flag_1, 1
inttofl $23, 2
mul $24, retorno_1, $23
mov retorno_1, $24
slt $25, 1, flag_1
inttofl $26, 100
add $27, retorno_1, $26
mov retorno_1, $27
inttofl $28, 100
sub $29, retorno_1, $28
mov retorno_1, $29
scanf a_5
fltoint $30, a_5
mov calculo_5, $30
fltoint $31, calculo_5
