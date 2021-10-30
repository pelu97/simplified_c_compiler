int a;
float flag;


float processamento(float a, int b){
    float retorno;
    int flag;

    retorno = (a + b) * 2.2 - 5/2 * (a/2) + b - (b*5.5) + (78 - (30*a / (5/b)));

    read(flag);

    if(flag == 1){
        retorno = retorno * 2;
    }

    if(flag > 1){
        retorno = retorno + 100;
    }
    else{
        retorno = retorno - 100;
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

    return 0;
}
