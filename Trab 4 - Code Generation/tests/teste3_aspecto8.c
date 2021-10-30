int a;
float flag;
int list_value;

int list list_input(int n){
    int i;
    int temp;
    int list mylist;
    mylist = NIL;
    int batata;

    for(i=0; i<n; i = i + 1){
        read(temp);
        mylist = temp : mylist;
    }

    batata = 1 + 2/2 + (3 + 5.1 - 90 * 2);

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

    writeln(?n);


    list_value = ?n;
    temp_list = check_list << n;
    temp_list2 = double_list >> n;
    temp_list = !temp_list;

    writeln(?temp_list2);

    writeln(?temp_list);

    return 0;

}

float processamento(float a, int b){
    float retorno;
    int flag;
    int i;

    retorno = (a + b) * 2.2 - 5/2 * (a/2) + b - (b*5.5) + (78 - (30*a / (5/b)));

    read(flag);

    for(i=0; ((i*2) <= 30) && !((i> i-5) == (34-i)); i = i+1){
        return retorno + 1;
    }


    return retorno;
}


int leitura(){
    float a;
    float calculo;

    read(a);

    calculo = processamento(a, a);

    return calculo;
}


int main(){
    int list a;

    leitura();

    a = list_input(5);

    test_list(a);

    return 0;
}
