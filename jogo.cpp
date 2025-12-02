#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;
int count;
int tentativas = 1;
int numeroJogador;
int contador;
int acertosPosicao;
int acertosValor;
void Cabecalho() {
    cout << "=====================================\n";
    cout << "          JOGO DA SENHA\n";
    cout << "     Descubra a senha secreta!\n";
    cout << "         Digitos de 1 a 6\n";
    cout << "=====================================\n";
}

void Menu() {
    cout << "\n------ MENU ------\n";
    cout << "1 - Iniciar o jogo\n";
    cout << "2 - Ajuda\n";
    cout << "3 - Sair\n";
    cout << "Escolha: ";
}

void Ajuda() {
    cout << "\n========== AJUDA ==========\n";
    cout << "O computador gera uma senha de 4 digitos (1 a 6).\n";
    cout << "Voce tem 10 tentativas para adivinhar.\n\n";
    cout << "Feedback por tentativa:\n";
    cout << "- Digitos corretos e na posicao correta\n";
    cout << "- Digitos corretos mas na posicao errada\n";
    cout << "Iniciar jogo digite 1.\n";
    cout << "Sair digite 3.\n";
    cout << "============================\n\n";
}

void mostrarEntradaTentativa(int tentativa) {
    
        cout << "\n-------------------------------------\n";
        cout << " Tentativa " << tentativa << " de 10\n";
        cout << " Digite 4 digitos (1 a 6): ";
    
}

void mostrarFeedback(int acertosPosicao, int acertosValor) {
    cout << "\n--- FEEDBACK ---\n";
    cout << "Posicao correta: " << acertosPosicao << "\n";
    cout << "Cor correta na posicao errada: " << acertosValor << "\n";
    cout << "-----------------\n";
}

void Vitoria() {
    cout << "\n=====================================\n";
    cout << "      PARABENS! VOCE DESCOBRIU!\n";
    cout << "=====================================\n";
}

void Derrota() {
    cout << "\n=====================================\n";
    cout << "        FIM DE JOGO!\n";
    cout << "  Suas tentativas acabaram.\n";
    cout << "=====================================\n";
}
void derrotaPorNumeroInvalido() {
    cout << "\n=====================================\n";
    cout << "        FIM DE JOGO!\n";
    cout << "  Numero invalido jogado.\n";
    cout << "=====================================\n";
}
//Criei um struct q randomiza a senha para maior organizacao do codigo;
struct senhaRandom{
    int digito1 = (rand() % 6) + 1;
    int digito2 = (rand() % 6) + 1;
    int digito3 = (rand() % 6) + 1;
    int digito4 = (rand() % 6) + 1;
    int numeroFinal = digito1 * 1000 + digito2 * 100 + digito3 * 10 + digito4;
};

//struct para tratar o numero jogado pelo usuario
struct numeroJogado
{
    
     int primeiroDigitoJ;
     int segundoDigitoJ;
     int terceiroDigitoJ;
     int quartoDigitoJ;
     
};


//funcao q trata o numero jogado pelo usuario, separando os digitos
numeroJogado trataNumeroJogador(int numeroJogador){

    numeroJogado njr;
    njr.primeiroDigitoJ = numeroJogador / 1000;
    njr.segundoDigitoJ = (numeroJogador - njr.primeiroDigitoJ *1000)/ 100;
    njr.terceiroDigitoJ = (numeroJogador - (njr.primeiroDigitoJ * 1000 + njr.segundoDigitoJ * 100))/10;
    njr.quartoDigitoJ = numeroJogador - (njr.primeiroDigitoJ * 1000 + njr.segundoDigitoJ * 100 + njr.terceiroDigitoJ * 10);

    return njr;

}


void jogoDaSenha(){
   
    //chama as variaveis do struct
    senhaRandom senhaRandom;
    
    mostrarEntradaTentativa(tentativas);

    int numeroJogador;
    cin >> numeroJogador;
    
    
    if (numeroJogador == senhaRandom.numeroFinal){
        Vitoria();
    } else {
       
        while(tentativas <= 10){
            
                while(count <= 4 ){
                    
                    numeroJogado nj = trataNumeroJogador(numeroJogador);

                    if(tentativas < 10 ){
                        if(numeroJogador >= 1111 and numeroJogador <= 6666){
                            if(numeroJogador == senhaRandom.numeroFinal){
                                Vitoria();
                                break;
                                
                            } else{    
                                acertosPosicao = 0;
                                acertosValor = 0;
                                cout << "\nResultado da tentativa " << tentativas << ": ";
                                if (nj.primeiroDigitoJ == senhaRandom.digito1)
                                {
                                    cout << "o";
                                    acertosPosicao++;
                                    
                                } else if(nj.primeiroDigitoJ == senhaRandom.digito2 or nj.primeiroDigitoJ == senhaRandom.digito3 or nj.primeiroDigitoJ == senhaRandom.digito4){
                                    cout << "x";
                                    acertosValor++;
                                }else{
                                    cout << "_";
                                }
                                
                                //verifica se o segundo digito e compativel com qualquer um dos 4 digitos da senha
                                if(nj.segundoDigitoJ == senhaRandom.digito2){
                                    cout << "o";
                                acertosPosicao++;
                                }else if (nj.segundoDigitoJ == senhaRandom.digito1 or nj.segundoDigitoJ == senhaRandom.digito3 or nj.segundoDigitoJ == senhaRandom.digito4)
                                {
                                    cout << "x";
                                    acertosValor++;
                                }else{
                                    cout << "_";
                                }
            

                                //verifica se o terceiro digito e compativel com qualquer um dos 4 digitos da senha
                                if(nj.terceiroDigitoJ == senhaRandom.digito3){
                                    cout << "o";
                                    acertosPosicao++;
                                }else if (nj.terceiroDigitoJ == senhaRandom.digito1 or nj.terceiroDigitoJ == senhaRandom.digito2 or nj.terceiroDigitoJ == senhaRandom.digito4)
                                {
                                    cout << "x";
                                    acertosValor++;
                                }else{
                                    cout << "_";
                                }
            
                                //verifica se o quarto digito e compativel com qualquer um dos 4 digitos da senha
                                if(nj.quartoDigitoJ == senhaRandom.digito4){
                                    cout << "o" << endl;
                                    acertosPosicao++;
                                }else if (nj.quartoDigitoJ == senhaRandom.digito1 or nj.quartoDigitoJ == senhaRandom.digito2 or nj.quartoDigitoJ == senhaRandom.digito3)
                                {
                                    cout << "x" << endl;
                                    acertosValor++;
                                }else{
                                    cout << "_" << endl;
                                }
                                    tentativas++;
                                    mostrarFeedback(acertosPosicao, acertosValor); 
                                    mostrarEntradaTentativa(tentativas);
                                    
                                    cin >> numeroJogador;  
                                    
                            }
                        }else{
                            derrotaPorNumeroInvalido();
                            break;
                        }
                    }else{
                            Derrota();
                            break;
                    } 
                        
                }
            break;
        }
    }


}








int main(){
    srand(time(NULL));
    Cabecalho();
    int escolha;
    cout << "\n------ MENU ------\n";
    cout << "1 - Iniciar o jogo\n";
    cout << "2 - Ajuda\n";
    cout << "3 - Sair\n";
    cout << "Escolha: ";
    cin >> escolha;
    
    while(contador < 1){
        if(escolha == 1){
            jogoDaSenha();
            contador++; 
            break;  
        }else if (escolha == 2){
            Ajuda();
        }else{
            break;
        }
        cin >> escolha;
    }
 }
