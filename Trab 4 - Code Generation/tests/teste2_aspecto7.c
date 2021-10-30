int a;
float flag;


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

    return 0;
}
