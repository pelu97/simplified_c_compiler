int batata;


int bake(){
    int temp;

    if((batata < 100) && (batata > 20) || (batata == 10)){
        temp = batata;
    }
    else{
        temp = (batata * 2) + (3 + 5 * 9 / 3 - 2);
    }


    write(temp);
    writeln(" batatas assadas");
}


int main(){

    write("Digite um inteiro: ");
    read(batata);

    write("O inteiro digitado foi: ");
    writeln(batata);

    bake(batata);

    write("Encerrando execução...");

    return 0;
}
