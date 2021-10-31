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
int batata_1
int i_3
int i_6
int n_7
int temp_list_7
int temp_list2_7
int listread_8
int n_8
.code
list_input:
pop n_1
pop k_1
pop l_1
pop j_1
pop g_1
inttofl $0, NIL
mov mylist_1, $0
mov i_1, 0
for_label_0:
println "Digite um inteiro para armazenar na lista"
scani temp_1
mov mylist_1, $0
add $1, i_1, 1
mov i_1, $1
slt $2, i_1, n_1
brnz for_label_0, $2
div $3, 2, 2
add $4, 1, $3
inttofl $5, $4
inttofl $6, 3
add $7, $6, 5.1
mul $8, 90, 2
inttofl $9, $8
sub $10, $7, $9
add $11, $5, $10
fltoint $12, $11
mov batata_1, $12
println "Lista armazenada"
return mylist_1
return NIL
check_list:
pop i_3
sleq $0, list_value_0, i_3
brz if_label_1, $0
return 1
jump if_label_2
if_label_1:
return 0
if_label_2:
return -1
return 0
double_list:
pop i_6
mul $0, i_6, 2
return $0
return 0
test_list:
pop n_7
print "Primeiro elemento da lista: "
println `Hvùü
mov batata_0, 0
mov list_value_0, $-1
mov temp_list_7, $-1
mov temp_list2_7, $-1
print "Primeiro elemento da lista duplicada: "
println  Evùü
print "Primeiro elemento da lista filtrada pelo primeiro valor da lista de entrada: "
println ÀEvùü
return 0
return 0
main:
print "Digite um tamanho para a lista: "
scani n_8
print "O inteiro digitado foi: "
println n_8
param 3
param 2
param 4
param 1
param n_8
call list_input
pop $0
mov listread_8, $0
param listread_8
call test_list
pop $1
print "Encerrando execuÃ§Ã£o..."
return 0
return 0
