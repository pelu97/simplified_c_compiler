.table
int a_1
int b_1
int c_1
.code
test:
println #2
println #1
println #0
return 0
return 0
main:
param 3
param 2
param 1
call test, 3
pop $0
println
println
