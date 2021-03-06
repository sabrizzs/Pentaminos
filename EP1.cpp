/*
    nome: Sabrina Araújo da Silva
    nUSP: 12566182
*/

#include <iostream>
#include <stdio.h>

using namespace std;
#define MAX 60

class stack {
    private:
        static const int max_size = 12; //tamanho da pilha
        int topo;                       //topo atual da pilha
        int itens[max_size];            //vetor para os itens da pilha

    public:
        //inicializa a pilha
        stack (){
            topo = -1;
        }

        //empilha um item
        void push (int item){
            if(topo >= max_size - 1) {
                cout << "Stack overflow" << endl;
            } else itens[++topo] = item;
        }

        //desempilha o item do topo
        int pop (){
            if(topo <= -1) {
                cout << "Stack underflow" << endl;
                return -1;
            } else return itens[topo--];
        }

        //retorna se a pilha está vazia ou não
        bool empty (){
            if(topo == -1) return true;
            else return false;
        }

        //retorna o item do topo da pilha
        int top (){
            if(topo == -1) return -1;
            else return itens[topo];
        }
};

int m; int n;           //dimensoes da matriz
int posx; int posy;     //posição atual
int aposx; int aposy;   //posicao anterior

//pentaminos
const char pecas[12][9][5][5] = {
{ //peça F
{{'*','F','F','*','*'},
 {'F','F','*','*','*'},
 {'*','F','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'F','F','*','*','*'},
 {'*','F','F','*','*'},
 {'*','F','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','F','*','*','*'},
 {'F','F','F','*','*'},
 {'*','*','F','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','F','*','*','*'},
 {'F','F','F','*','*'},
 {'F','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','F','*','*','*'},
 {'*','F','F','*','*'},
 {'F','F','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','F','*','*','*'},
 {'F','F','*','*','*'},
 {'*','F','F','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'F','*','*','*','*'},
 {'F','F','F','*','*'},
 {'*','F','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','*','F','*','*'},
 {'F','F','F','*','*'},
 {'*','F','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
 {'S'} //indica que está no final das possíveis rotações da peça
},
{ //peça I
{{'I','*','*','*','*'},
 {'I','*','*','*','*'},
 {'I','*','*','*','*'},
 {'I','*','*','*','*'},
 {'I','*','*','*','*'}},
{{'I','I','I','I','I'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
 {'S'}
},
{ //peça L
{{'L','*','*','*','*'},
 {'L','*','*','*','*'},
 {'L','*','*','*','*'},
 {'L','L','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','L','*','*','*'},
 {'*','L','*','*','*'},
 {'*','L','*','*','*'},
 {'L','L','*','*','*'},
 {'*','*','*','*','*'}},
{{'L','L','L','L','*'},
 {'L','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'L','L','L','L','*'},
 {'*','*','*','L','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'L','L','*','*','*'},
 {'*','L','*','*','*'},
 {'*','L','*','*','*'},
 {'*','L','*','*','*'},
 {'*','*','*','*','*'}},
{{'L','L','*','*','*'},
 {'L','*','*','*','*'},
 {'L','*','*','*','*'},
 {'L','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','*','*','L','*'},
 {'L','L','L','L','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'L','*','*','*','*'},
 {'L','L','L','L','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
 {'S'}
},
{ //peça N
{{'N','N','*','*','*'},
 {'*','N','N','N','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','*','N','N','*'},
 {'N','N','N','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','N','*','*','*'},
 {'N','N','*','*','*'},
 {'N','*','*','*','*'},
 {'N','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'N','*','*','*','*'},
 {'N','N','*','*','*'},
 {'*','N','*','*','*'},
 {'*','N','*','*','*'},
 {'*','*','*','*','*'}},
{{'N','N','N','*','*'},
 {'*','*','N','N','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','N','N','N','*'},
 {'N','N','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','N','*','*','*'},
 {'*','N','*','*','*'},
 {'N','N','*','*','*'},
 {'N','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'N','*','*','*','*'},
 {'N','*','*','*','*'},
 {'N','N','*','*','*'},
 {'*','N','*','*','*'},
 {'*','*','*','*','*'}},
 {'S'}
},
{ //peça P
{{'P','P','*','*','*'},
 {'P','P','*','*','*'},
 {'P','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'P','P','*','*','*'},
 {'P','P','*','*','*'},
 {'*','P','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'P','P','P','*','*'},
 {'*','P','P','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'P','P','P','*','*'},
 {'P','P','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'P','P','*','*','*'},
 {'P','P','P','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','P','P','*','*'},
 {'P','P','P','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'P','*','*','*','*'},
 {'P','P','*','*','*'},
 {'P','P','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','P','*','*','*'},
 {'P','P','*','*','*'},
 {'P','P','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
 {'S'}
},
{ //peça T
{{'T','T','T','*','*'},
 {'*','T','*','*','*'},
 {'*','T','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'T','*','*','*','*'},
 {'T','T','T','*','*'},
 {'T','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','*','T','*','*'},
 {'T','T','T','*','*'},
 {'*','*','T','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','T','*','*','*'},
 {'*','T','*','*','*'},
 {'T','T','T','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
 {'S'}
},
{ //peça U
{{'U','*','U','*','*'},
 {'U','U','U','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'U','U','U','*','*'},
 {'U','*','U','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'U','U','*','*','*'},
 {'U','*','*','*','*'},
 {'U','U','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'U','U','U','*','*'},
 {'U','*','U','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
 {'S'} 
},
{ //peça V
{{'V','*','*','*','*'},
 {'V','*','*','*','*'},
 {'V','V','V','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','*','V','*','*'},
 {'*','*','V','*','*'},
 {'V','V','V','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'V','V','V','*','*'},
 {'V','*','*','*','*'},
 {'V','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'V','V','V','*','*'},
 {'*','*','V','*','*'},
 {'*','*','V','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
 {'S'}
},
{ //peça W
{{'W','*','*','*','*'},
 {'W','W','*','*','*'},
 {'*','W','W','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','*','W','*','*'},
 {'*','W','W','*','*'},
 {'W','W','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','W','W','*','*'},
 {'W','W','*','*','*'},
 {'W','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'W','W','*','*','*'},
 {'*','W','W','*','*'},
 {'*','*','W','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
 {'S'}
},
{ //peça X
{{'*','X','*','*','*'},
 {'X','X','X','*','*'},
 {'*','X','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
 {'S'}
},
{ //peça Y
{{'*','Y','*','*','*'},
 {'Y','Y','*','*','*'},
 {'*','Y','*','*','*'},
 {'*','Y','*','*','*'},
 {'*','*','*','*','*'}},
{{'Y','*','*','*','*'},
 {'Y','Y','*','*','*'},
 {'Y','*','*','*','*'},
 {'Y','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','Y','*','*','*'},
 {'Y','Y','Y','Y','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','*','Y','*','*'},
 {'Y','Y','Y','Y','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'Y','*','*','*','*'},
 {'Y','*','*','*','*'},
 {'Y','Y','*','*','*'},
 {'Y','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','Y','*','*','*'},
 {'*','Y','*','*','*'},
 {'Y','Y','*','*','*'},
 {'*','Y','*','*','*'},
 {'*','*','*','*','*'}},
 {'S'}
},
{ //peça Z
{{'Z','Z','*','*','*'},
 {'*','Z','*','*','*'},
 {'*','Z','Z','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','Z','Z','*','*'},
 {'*','Z','*','*','*'},
 {'Z','Z','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'*','*','Z','*','*'},
 {'Z','Z','Z','*','*'},
 {'Z','*','*','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
{{'Z','*','*','*','*'},
 {'Z','Z','Z','*','*'},
 {'*','*','Z','*','*'},
 {'*','*','*','*','*'},
 {'*','*','*','*','*'}},
 {'S'}
}
};

stack st; //pilha de peças
stack rot; //pilha auxiliar de rotações

//imprime o tabuleiro
void imprime(char tabuleiro[][MAX]){ 
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(tabuleiro[i][j] == '1') cout<< '*';
            else cout<< tabuleiro[i][j];
        }
        cout<< "\n";
    }
    return;
}

//procura uma posicao valida a partir da pos atual e retorna para posx e posy
void valido(char tabuleiro[][MAX]){ 
    aposx = posx; aposy = posy; //posicoes anteriores
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(tabuleiro[j][i] == '0'){
                posx = j;
                posy = i;
                return;
            }
        }
    }
}

//encontra letra da peça
char letra(int ind){ 
    for(int q = 0; q < 5; q++){
        for(int j = 0; j < 5; j++){
            if(pecas[ind][0][q][j] != '*') return pecas[ind][0][q][j];
        }
    }
}

//verifica se a rotação dada encaixa no tabuleiro
bool rotacao(int ind, int i, char tabuleiro[][MAX]){ 
    valido(tabuleiro);
    int primeira = 1;
    for(int q = 0; q < 5; q++){
        for(int j = 0; j < 5; j++){
            if(pecas[ind][i][j][q] != '*'){
                if(primeira){ //ajusta a posição inicial para encaixar a peça
                    posx = posx - j;
                    posy = posy - q;
                    primeira = 0;
                }
                if(posx + j >= m || posy + q >= n){ //a peça não cabe no tabuleiro
                    return false;
                } else if(tabuleiro[posx+j][posy+q] != '0'){ //a peça não encaixa nessa posição no tabuleiro
                    return false;
                }
            }
        }
    }
    return true;
}

//encaixa a peça no tabuleiro (matriz)
void pecaTab(int ind, int i, char tabuleiro[][MAX]){ 
    for(int q = 0; q < 5; q++){
        for(int j = 0; j < 5; j++){
            if(pecas[ind][i][q][j] != '*'){
                tabuleiro[posx+q][posy+j] = pecas[ind][i][q][j];
            }
        }
    }
    valido(tabuleiro);
    st.push(ind);
    rot.push(i);
    return;
}

//verifica se uma dada peça encaixa na pos atual em todas as rotações
bool encaixa(int ind, int rot, char tabuleiro[][MAX]){  
    valido(tabuleiro);
    for(int i = rot; i < 8; i++){
        if(pecas[ind][i][0][0] == 'S') return false;
        if(rotacao(ind, i, tabuleiro)){    //função rotacao() para ver se a rotacao encaixa
            pecaTab(ind, i, tabuleiro);    //função pecaTab() para encaixar a peça no tabuleiro
            return true;
        }
    }
    return false;
}

//desencaixa peça do tabuleiro
void desencaixa(int ind, int *i, char tabuleiro[][MAX]){ 
    st.pop();
    *i = rot.top();
    rot.pop();
    char peca = letra(ind);

    for(int q = 0; q < m; q++){
        for(int j = 0; j < n; j++){
            if(tabuleiro[q][j] == peca) tabuleiro[q][j] = '0';
        }
    }
    posx = aposx; posy = aposy;
}

void pentaminos(int npecas, char tabuleiro[][MAX]){
    int cont = 0;
    int encaixadas[npecas];
    int inicio = 0;
    int rot = 0;        //rotacao da peça

    for(int i = 0; i < npecas; i++) encaixadas[i] = 0; //inicia array de peças que foram encaixadas
    valido(tabuleiro); //procura primeira casa válida no tabuleiro

    while(cont < npecas){ //enquanto existe uma peça para encaixar
        for(int i = inicio; i < npecas; i++){
            if(encaixadas[i] == 0 && encaixa(i, rot, tabuleiro) && cont < npecas){
                cont++;
                encaixadas[i] = 1;
                i = -1;          //reinicia o 'for' depois que encaixou uma peça
                if(inicio != 0){ //reinicia o 'for' depois do backtracking
                inicio = 0;
                i = -1;
                }
            }
            rot = 0;
        }
        
        //backtracking
        if(cont < npecas){
            if(!st.empty()){
                int ind = st.top();
                desencaixa(ind, &rot, tabuleiro);
                encaixadas[ind] = 0;
                inicio = ind;
                if(rot < 9){
                    rot++;
                } 
                cont--;
            } else {
                cout<< "Impossivel!\n";
                return;
            }
        }

    }
    cout<< "Possivel!\n";
    return;
}

int main(){
    int npecas = 12; //numero de peças

    //recebe as dimensoes e valores do tabuleiro
    cout<< "Insira os valores de m e n para criar o tabuleiro m x n: \n";
    cin>> m; cin>> n;
    char tabuleiro[m][MAX];

    cout<< "Insira os valores da matriz " << m << " x " << n << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>> tabuleiro[i][j];
        }
    }
    pentaminos(npecas, tabuleiro);
    imprime(tabuleiro);
    return 0;
}