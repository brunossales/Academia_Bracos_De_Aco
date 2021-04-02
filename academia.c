#include <stdio.h>

typedef struct cliente Cliente;

struct cliente // struct com dados do cliente
{
   int cod;
   char nome[51];
   double altura;
   double peso;
   double IMC;
};

double calculo_IMC(double peso, double altura){  // essa funÃ§Ã£o receberÃ¡ o peso e altura do cliente e retornarÃ¡ o IMC


        return peso/(altura*altura);
}

void analise_IMC(Cliente c){ // essa funÃ§Ã£o vai analisar o imc e imprimir condiÃ§Ã£o do peso(ex:obeso,abaixo do peso ...) 
	if(c.IMC < 18.5)
		printf("Voce esta abaixo do peso\n");
	
	else if(c.IMC >= 18.5 && c.IMC <= 24.9)
	    printf("Peso normal\n");
	    
	else if(c.IMC >= 25 && c.IMC <= 29.9)
	    printf("Sobrepeso\n");
	    
	else if(c.IMC >= 30 && c.IMC <= 34.9)
	    printf("Obesidade I\n");
	    
	else if(c.IMC >= 35 && c.IMC <= 39.9)
	    printf("Obesidade II\n");
	    
	else if(c.IMC >= 40)
	    printf("Obesidade grau III ou Morbida\n");

}

Cliente cadastrar_cliente(){
	Cliente C;
	printf("Nome do cliente:\n");
	scanf(" %50[^\n]",C.nome);
	printf("Altura do cliente:\n");
	scanf("%lf",&C.altura);
	printf("Peso do cliente:\n");
	scanf("%lf",&C.peso);
	C.IMC=calculo_IMC(C.peso,C.altura);
	analise_IMC(C);
	
	return C;
}
void listarClientes(Cliente c){
	printf("\nCodigo: %d",c.cod);
	printf("\nCliente: %s",c.nome);
	printf("\naltura: %.2lf",c.altura);
	printf("\npeso: %.2lf",c.peso);
	printf("\nIMC: %.2lf\n",c.IMC);
}
Cliente atualizar_cliente(){
	Cliente C;
	printf("Atualiza Nome do cliente:\n");
	scanf(" %50[^\n]",C.nome);
	printf("Atualiza Altura do cliente:\n");
	scanf("%lf",&C.altura);
	printf("Atualiza Peso do cliente:\n");
	scanf("%lf",&C.peso);
	C.IMC=calculo_IMC(C.peso,C.altura);
	
	return C;
}






int main(){
    int op=0;
	int fechar=0;
	int opc;
	Cliente c[50];
	int q=0;
	int r;
    int k;
	int contad;
    int cont = 0;
    printf(" Bem vindo a Academia Bracos de Aco!\n A melhor Academia do Sertao Central");


    while(fechar==0){
        printf("\nPara selecionar a opcao desejada, digite o numero abaixo correspondente a funcao :D");
        printf("\n1 - Cadastro de Cliente\n");
        printf("2 - Listar Clientes\n");
        printf("3 - Atualiza dados do cliente\n");
        printf("4 - Fechar o programa\n");
        printf("\n");
        scanf("%d",&op);
        contad = 0;
        switch(op){
           case 1:
            printf("Aqui voce cadastra o cliente\n");
            c[q]=cadastrar_cliente();
    
            c[q].cod=q;
            q++;
            while (contad<1)
            {
			    printf("\nDigite 1 para cadastrar outro cliente e 2 para voltar ao menu\n");
			    scanf("%d", &opc);
				if (opc==1)
				{
					contad = 0;
                    c[q]=cadastrar_cliente();
    
                    c[q].cod=q;
                    q++;
				}
				else if(opc==2)
				{
					contad = 1;
				}
                else
                {
                    printf("opcao invalida\n");
                }
            }
            contad = 0;
            break;
            case 2:
            printf("Aqui voce consulta os clientes cadastrados\n");
            for(int i=0;i<q;i++){
                listarClientes(c[i]);
                    analise_IMC(c[i]);
            }
            while (contad<1)
            {
            printf("\nDigite algo para voltar ao menu\n");
			char a;
            scanf(" %c", &a);
            contad = 1;
            }
            contad = 0;
            break;
            case 3:
            printf("\nAqui atualiza os dados do cliente\n");
            while (contad<1)
            {
            printf("digite o codigo do cliente:\n");
            k=0;
            scanf("%d",&r);
            
            for(int i=0;i< 49;i++){
            	if(c[r].cod==r)
            	k++;
			}
            if(k>0){
        	c[r]=atualizar_cliente();
        	c[r].cod=r;
        	}
        	else{
        		printf("codigo de cliente invalido\n");
                }   
            cont = 0;
			while (cont<1)
            {
            printf("Digite 1 para atualizar outro cliente ou 2 para voltar ao menu\n");
			scanf("%d", &opc);
				if (opc==1)
				{
					contad=0;
                    cont = 1;
				}
				else if(opc==2)
				{
					contad=1;
                    cont = 1;
				}
                else{
                    printf("opcao invalida\n");
                }
            }
            }
            break;
           case 4:
                printf("Aqui encerra o programa\n");
				fechar=1;
                break;
           default:
                printf("opcao invalida\n");
        }
    }
	printf("Obrigado pela preferencia!");
    return 0;
}