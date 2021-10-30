int batata;


int bake(){
    int temp;
    // int list batata2;

    if((batata < 100) && (batata > 20) || (batata == 10)){
        temp = batata;
    }
    else{
        temp = (batata * 2) + (3 + 5.1 * 9 / 3 - 2);
    }

    // if(batata2 > 10){
    //     temp = batata;
    // }
    // else if(batata2 && (batata>1)){
    //     temp = batata;
    // }

    write(temp);
    writeln(" batatas assadas");

    // return 0;
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
