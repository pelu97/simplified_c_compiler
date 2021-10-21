int list_value;

int batata;

int list list_input(int n, int k, int l, int j, int g){
    int i;
    int temp;
    int list mylist;
    mylist = NIL;
    int batata;

    for(i=0; i<n; i = i + 1){
        writeln("Digite um inteiro para armazenar na lista");
        read(temp);
        mylist = temp : mylist;
    }


    writeln("Lista armazenada");

    return mylist;
}



int check_list(int i){
    if(i >= list_value){
        return 1;
    }
    else{
        return 0;
    }
}

int double_list(int i){
    return i*2;
}


int test_list(int list n){
    int list temp_list;
    int list temp_list2;
    // int batata;


    write("Primeiro elemento da lista: ");
    writeln(?n);

    batata= 0;

    // write("Último elemento da lista: ");
    // writeln(!n);

    list_value = ?n;
    temp_list = check_list << n;
    temp_list2 = double_list >> n;

    // write("Último elemento da lista - removendo um: ");
    // writeln(%n);

    write("Primeiro elemento da lista duplicada: ");
    writeln(?temp_list2);

    write("Primeiro elemento da lista filtrada pelo primeiro valor da lista de entrada: ");
    writeln(?temp_list);




}


int main(){
    int list listread;
    int n;
    write("Digite um tamanho para a lista: ");
    read(n);

    write("O inteiro digitado foi: ");
    writeln(n);

    listread = list_input(n, 1, 4, 2, 3);

    test_list(listread);

    write("Encerrando execução...");

    return 0;
}
