.table
int vetor[] = {0}
int vetor_size = 0
.code
// L1:
// add vetor_size, vetor_size, 1
// // mema vetor, vetor_size
// mema $0, vetor_size
// mov vetor, &$0
// mov vetor[0], 1
// mov $1, vetor[0]
// println $1
// L2:
// add vetor_size, vetor_size, 1
// mema $0, vetor_size
// mov $0[0], 1
// mov $1, $0[0]
// println $1
// L3:
// mov vetor[0], 1
// mov vetor[1], 2
// mov $0, vetor[0]
// mov $1, vetor[1]
// println $0
// println $1
// L4:
// mov $1, 1
// mov $0, 4
// println $1
// println $0
L5:
mema $0, 2
mov $0[0], 1
mov $0[1], 2
mema $1, 4
mov $2, 0
LOOP:
mov $4, $0[$2]
mov $1[$2], $4
add $2, $2, 1
slt $3, $2, 2
brnz LOOP, $3
mov $1[2], 3
mov $1[3], 4
mov $5, $1[0]
println $5
mov $5, $1[1]
println $5
mov $5, $1[2]
println $5
mov $5, $1[3]
println $5


// mov $15, $14[0]
// println $15
// mov $15, $14[1]
// println $15
// mov $15, $14[2]
// println $15
