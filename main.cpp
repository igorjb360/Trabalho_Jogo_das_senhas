/* Integrantes da equipe:
 * Cicero Pizetta Pizutti
 * Igor José Bourscheid
 * Pablo da Silva Marques
 *
 *Trabalho desenvolvido em maio/21 às diretrizes de:
 *Rafael Ballottin Martins, professor de Algoritmos e Programação
*/

#include <iostream>
#include <time.h> //Utilizada apenas para chamar a função srand
#include <locale.h> //Utilizada apenas para usar o setlocale
using namespace std;

int main() 
{
  setlocale(LC_ALL, "Portuguese"); //Idioma do local definido como português

  int loop=1, opcao, voltar;
  int dificuldade=2, tentativas=10; //Por padrão, a dificuldade será equivalente a média 

  while (loop==1) { // Esse loop será constante. Só irá parar caso o usuário no menu pressione 4
      system("clear"); //Garante que ao retornar para o menu, tudo impresso anteriormente no console seja apagado
      cout<<"--------------------------------------------------\n[1] Jogar | [2] Dificuldade | [3] Sobre | [4] Sair\n--------------------------------------------------"<<endl;
      cout<<">: ";
      cin>>opcao;
      system("clear"); //Garante que o menu seja apagado do console após a opção escolhida

      //Essas variáveis encontram-se aqui pois necessitam ser atualizadas constantemente
      int jogar=1;
      int contador=0;
      int n1=0, n2=0, n3=0, n4=0, n5=0; //Números que compoem o código secreto gerado pelo computador
      int codigo1=10, codigo2=10, codigo3=10, codigo4=10, codigo5=10; //Abrigam os números que posteriormente serão digitados pelo usuário

      switch(opcao) {
        case 1:
            while(jogar==1) {

              srand(time(NULL));  //Esse comando garante que a cada passar do tempo a randomização dos números ocorra. Isso é, quando o usuário jogar jovamente seguidamente, os números gerados não serão mais os mesmos.
              while (n1 == n2 || n1 == n3 || n1 == n4 || n1 == n5 || n2 == n3 || n2 == n4 || n2 == n5 || n3 == n4 || n3 == n5 || n4 == n5) { //Esse laço se repete enquanto ouver ao menos um número que seja igual ao outro. Como todos se iniciam em 0, esse laço vai se repetir ao menos uma vez, e então se repetirá até que todos os números gerados abaixo sejam diferente.
                n1=rand()%6+1; //Gera um número aleatório entre 1 e 5, o +1 serve para garantir que o numero gerado seja até 6.
                n2=rand()%6+1;
                n3=rand()%6+1;
                n4=rand()%6+1;
                n5=rand()%6+1;
              }

              if(dificuldade==1) { // Aqui dentro ocorre o desenvolvimento do jogo na dificuldade fácil
                //cout<<n1<<"-"<<n2<<"-"<<n3<<" CÓDIGO A SER QUEBRADO"<<endl;
                cout<<"Digite uma sequência de 3 dígitos em 8 tentativas\nSiga o exemplo: 0 0 0\n";

                int contador=8, poscorreta=0, poserrada=0; 

                while (contador <= tentativas && contador !=0) { //O contador possui o mesmo valor das tentativas, que nesssa dificuldade é 8. A cada repetição é reduzido 1 do valor do contador até que ele chegue a 0, simbolizando que as tentativas se esgotaram.
                  cout<<"Tentativas restantes: "<<contador<<endl;
                  cout<<"\n>: ";
                  cin>>codigo1>>codigo2>>codigo3;
                  contador--;
                  
                  //Verifica se o valor digitado pelo usuário no codigo1 é igual ao valor de n1. Se for verdade, então será somado 1 a variável poscorreta, indicando um numero correto na posição correta
                  if (codigo1==n1 && codigo1!=n2 && codigo1!=n3)
                    poscorreta++;
                  //Verifica se o valor digitado pelo usuário em codigo1 corresponde ao valor contido em n2 ou n3. Se for verdade, então será somado 1 a variável que indica um numero correto na posição incorreta
                  if (codigo1!=n1 && (codigo1==n2 || codigo1==n3))
                    poserrada++;


                  //Verifica se o valor digitado pelo usuário no codigo2 é igual ao valor de n2. Se for verdade, então será somado 1 a variável poscorreta, indicando um numero correto na posição correta  
                  if (codigo2!=n1 && codigo2==n2 && codigo2!=n3)
                    poscorreta++;

                  //Verifica se o valor digitado pelo usuário em codigo2 corresponde ao valor contido em n1 ou n3. Se for verdade, então será somado 1 a variável que indica um numero correto na posição incorreta  
                  if (codigo2!=n2 && (codigo2==n1 || codigo2==n3))
                    poserrada++;

                  //O mesmo procedimento descrito acima ocorre aqui, porém, com o codigo3 e n3 como referência.
                  if (codigo3!=n1 && codigo3!=n2 && codigo3==n3)
                    poscorreta++;
                    
                  if (codigo3!=n3 && (codigo3==n1 || codigo3==n2))
                    poserrada++;

                  cout<<"\n--------------------------------------------------\nDigitou "<<poscorreta<<" número(s) correto(s) na posição correta.\nDigitou "<<poserrada<<" número(s) correto(s) na posição incorreta."<<endl;

                  //Garante que o valor das variáveis abaixo seja zerado após cada sequência de código digitado pelo usuário
                  poscorreta=0;
                  poserrada=0;

                  if (n1 == codigo1 && n2 == codigo2 && n3 == codigo3) //Se a sequência digitada for correta, esse laço será quebrado imediatamente
                    break;

                }

                cout<<endl<<n1<<"-"<<n2<<"-"<<n3<<" CÓDIGO SECRETO"<<endl; //Nesse ponto, independentemente do resultado, será apresentado o código secreto

                if (n1 == codigo1 && n2 == codigo2 && n3 == codigo3) { //Se o usuário venceu:
                  cout<<"\n-------------------\nPARABÉNS, Vencedor!\n-------------------"<<endl;
                  cout<<"\n[0] Voltar"<<endl<<">: "; //Novamente, essa opção é apenas simbolica para evitar o uso do system("pause"). Pressionar ou não o número 0 levará o usuário para o menu de qualquer forma, através do break.
                  cin>>voltar;
                  break; //Esse break interromperá o laço jogar, retornando ao laço loop correspondente ao menu
                }

                else { //Se o usuário perdeu:
                  cout<<"\n--------------------\nGAME OVER, Perdedor!\n--------------------"<<endl;
                  cout<<"\n[0] Voltar"<<endl<<">: ";
                  cin>>voltar;
                  break;
                }        

              }

              if(dificuldade==2) { // Aqui dentro ocorre o desenvolvimento do jogo na dificuldade média
                //cout<<n1<<"-"<<n2<<"-"<<n3<<"-"<<n4<<" CÓDIGO A SER QUEBRADO"<<endl;
                cout<<"Digite uma sequência de 4 ígitos em 10 tentativas\nSiga o exemplo: 0 0 0 0\n";

                int contador=10, poscorreta=0, poserrada=0;

                while (contador <= tentativas && contador !=0) {
                  cout<<"Tentativas restantes: "<<contador<<endl;
                    
                  cout<<"\n>: ";
                  cin>>codigo1>>codigo2>>codigo3>>codigo4;
                  contador--;
                  
                  if (codigo1==n1 && codigo1!=n2 && codigo1!=n3 && codigo1!=n4)
                        poscorreta++;
                    
                  if (codigo1!=n1 && (codigo1==n2 || codigo1==n3 || codigo1==n4))
                        poserrada++;
                    

                  if (codigo2!=n1 && codigo2==n2 && codigo2!=n3 && codigo2!=n4)
                        poscorreta++;
                    
                  if (codigo2!=n2 && (codigo2==n1 || codigo2==n3 || codigo2==n4))
                        poserrada++;
                    

                  if (codigo3!=n1 && codigo3!=n2 && codigo3==n3 && codigo3!=n4)
                        poscorreta++;
                    
                  if (codigo3!=n3 && (codigo3==n1 || codigo3==n2 || codigo3==n4))
                        poserrada++;
                    

                  if (codigo4!=n1 && codigo4!=n2 && codigo4!=n3 && codigo4==n4)
                        poscorreta++;
                    
                  if (codigo4!=n4 && (codigo4==n1 || codigo4==n2 || codigo4==n3))
                        poserrada++;
                    
                  cout<<"\n--------------------------------------------------\nDigitou "<<poscorreta<<" número(s) correto(s) na posição correta.\nDigitou "<<poserrada<<" número(s) correto(s) na posição incorreta."<<endl;
                    
                  poscorreta=0;
                  poserrada=0;

                  if (n1 == codigo1 && n2 == codigo2 && n3 == codigo3 && n4 == codigo4)
                    break;

                }

                cout<<endl<<n1<<"-"<<n2<<"-"<<n3<<"-"<<n4<<" CÓDIGO SECRETO"<<endl;

                if (n1 == codigo1 && n2 == codigo2 && n3 == codigo3 && n4 == codigo4) {
                  cout<<"\n-------------------\nPARABÉNS, Vencedor!\n-------------------"<<endl;
                  cout<<"\n[0] Voltar"<<endl<<">: ";
                  cin>>voltar;
                  break;
                }

                else {
                  cout<<"\n--------------------\nGAME OVER, Perdedor!\n--------------------"<<endl;
                  cout<<"\n[0] Voltar"<<endl<<">: ";
                  cin>>voltar;
                  break;
                }

              }

              if(dificuldade==3) { // Aqui dentro ocorre o desenvolvimento do jogo na dificuldade difícil
                //cout<<n1<<"-"<<n2<<"-"<<n3<<"-"<<n4<<"-"<<n5<<" CÓDIGO A SER QUEBRADO"<<endl;
                cout<<"Digite uma sequência de 5 dígitos em 12 tentativas\nSiga o exemplo: 0 0 0 0 0\n";

                int contador=12, poscorreta=0, poserrada=0;

                while (contador <= tentativas && contador !=0) {
                  cout<<"Tentativas restantes: "<<contador<<endl;
                  cout<<"\n>: ";
                  cin>>codigo1>>codigo2>>codigo3>>codigo4>>codigo5;
                  contador--;

                  if (codigo1==n1 && codigo1!=n2 && codigo1!=n3 && codigo1!=n4 && codigo1!=n5)
                    poscorreta++;
                    
                  if (codigo1!=n1 && (codigo1==n2 || codigo1==n3 || codigo1==n4 || codigo1==n5))
                    poserrada++;
                    

                  if (codigo2!=n1 && codigo2==n2 && codigo2!=n3 && codigo2!=n4 && codigo2!=n5)
                    poscorreta++;
                    
                  if (codigo2!=n2 && (codigo2==n1 || codigo2==n3 || codigo2==n4 || codigo2==n5))
                    poserrada++;
                    

                  if (codigo3!=n1 && codigo3!=n2 && codigo3==n3 && codigo3!=n4 && codigo3!=n5)
                    poscorreta++;
                    
                  if (codigo3!=n3 && (codigo3==n1 || codigo3==n2 || codigo3==n4 || codigo3==n5))
                    poserrada++;
                    

                  if (codigo4!=n1 && codigo4!=n2 && codigo4!=n3 && codigo4==n4 && codigo4!=n5)
                    poscorreta++;
                    
                  if (codigo4!=n4 && (codigo4==n1 || codigo4==n2 || codigo4==n3 || codigo4==n5))
                    poserrada++;
                    

                  if (codigo5!=n1 && codigo5!=n2 && codigo5!=n3 && codigo5!=n4 && codigo5==n5)
                    poscorreta++;
                    
                  if (codigo5!=n5 && (codigo5==n1 || codigo5==n2 || codigo5==n3 || codigo5==n4))
                    poserrada++;
                    
                  cout<<"\n--------------------------------------------------\nDigitou "<<poscorreta<<" número(s) correto(s) na posição correta.\nDigitou "<<poserrada<<" número(s) correto(s) na posição incorreta."<<endl;
                    
                  poscorreta=0;
                  poserrada=0;

                  if (n1 == codigo1 && n2 == codigo2 && n3 == codigo3 && n4 == codigo4 & n5 == codigo5)
                    break;
                }

                cout<<endl<<n1<<"-"<<n2<<"-"<<n3<<"-"<<n4<<"-"<<n5<<" CÓDIGO SECRETO"<<endl;

                if (n1 == codigo1 && n2 == codigo2 && n3 == codigo3 && n4 == codigo4 && n5 == codigo5) {
                  cout<<"\n-------------------\nPARABÉNS, Vencedor!\n-------------------"<<endl;
                  cout<<"\n[0] Voltar"<<endl<<">: ";
                  cin>>voltar;
                  break;
                }

                else {
                  cout<<"\n--------------------\nGAME OVER, Perdedor!\n--------------------"<<endl;
                  cout<<"\n[0] Voltar"<<endl<<">: ";
                  cin>>voltar;
                  break;
                }

              }

            }
            break;

        case 2: //Caso 2 seja pressionado no menu, o usuário terá a opção de alterar a dificuldade do jogo, que por padrão é a média.
          cout<<"---------------------\nALTERAR A DIFICULDADE\n---------------------\n[1] Fácil: sequência de 3 dígitos em até 8 tentativas\n[2] Média: sequência de 4 dígitos em até 10 tentativas\n[3] Difícil: sequência de 5 dígitos em até 12 tentativas\n\n[0] Voltar\n>: ";
          cin>>dificuldade; //É alterado o valor da dificuldade para algo indefinido
          if (dificuldade==1) {
            tentativas=8;
            break;
          }

          if (dificuldade==2) {
            tentativas=10;
          
            break;
          }

          if (dificuldade==3) {
            tentativas=12;
            break;
          }

          else { // A opção [0]Voltar é simbólica. Caso o usuário digitar qualquer valor diferente de 1, 2 ou 3, ele voltara ao menu com a dificuldade definida para média.
            dificuldade=2;
            tentativas=10;
            break;
          }

          break;

        case 3: //Caso 3 seja pressionado no menu, será apresentado ao usuário informações sobre o desenvolvimento do jogo.
            cout<<"---------------------\nINTEGRANTES DA EQUIPE\n---------------------\nCicero Pizetta Pizutti\nIgor Jose Bourscheid\nPablo da Silva Marques\n\nTrabalho desenvolvido em maio/2021, sob as diretrizes de:\nRafael Ballottin Martins, professor de Algoritmos e Programação\n\n[0] Voltar\n>: ";
            cin>>voltar; //Esse cin apenas existe para que o system("pause") não precise ser usado. Observe que, se o usuário pressionar 0 ou não, ele retornará ao menu da mesma maneira.
            break;

        case 4:
          loop=0; //Como mencionado, o jogo apenas irá pagar caso no menu seja pressionado 4
          break;  
        
      }
    }
    
    return 0;
}