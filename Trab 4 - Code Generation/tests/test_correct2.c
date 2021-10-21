int batata;


int bake(){
    int temp;
    float tempfloat;

    tempfloat = 3.4;

    if((batata < 100) && (batata > 20) || (batata == tempfloat)){
        temp = batata;
    }
    else{
        temp = (batata * 2) + (3 + 5.1 * 9 / 3 - 2);
    }


    write(temp);
    writeln(" batatas assadas");
}


int main(){

    write("Digite um inteiro: ");
    read(batata);

    write("O inteiro digitado foi: ");
    writeln(batata);

    bake();

    write("Encerrando execução...");

    return 0;
}
