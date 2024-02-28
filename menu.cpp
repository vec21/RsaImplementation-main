#include "menu.h"
#include "crypto_functions.h"
#include "prime_functions.h"
#include "number_operations.h"
#include <iostream>
#include <fstream>
#include <string>




// Função para exibir o menu
void showMenu() {
    int escolha, op;
    //string mensagem, resultado;
    long long min = 200;
    long long max = 6001;
    // Gerando p e q primos
    long long p = generatePrime(min, max);
    long long q = generatePrime(min, max);
    long long n, tot, e, d;

    n = p * q;
    tot = (p - 1) * (q - 1);
    e = chosseE(tot);
    d = calculeD(e, tot);
    string message, decoded_word;
    vector<int> coded, xcode ;



    //Arquivos Sainda

    ofstream arquivoCPu;
    ofstream arquivoCPr;
    ofstream mensagemCriptografada;
    ofstream mensagemDescodificada;
    //Arquivos Entradas
    ifstream arquivoMensagem;
    ifstream arquivoMensagemCrip;

    do {
      // Exibir menu
      limparTela();
        cout << "===== Menu =====\n";
        cout << "1. Gerar Chaves\n";
        cout << "2. Criptografar Mensagem\n";
        cout << "3. Descodificar Mensagem\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
            limparTela();
                cout << "Gerando As Chaves"<<"\n";

                arquivoCPu.open("chavePublica.pem");
                arquivoCPr.open("chavePrivada.pem");
                cout << "As Chaves Foram Geradas Com Sucesso!"<<"\n";
               
                arquivoCPu<<e<<" "<<n;
                arquivoCPr<<d<<" "<<n;
                arquivoCPu.close();
                arquivoCPr.close();
                
                
                break;
            case 2:
               // limparTela();
                //cout << "+++++++++| Criptografar Mensagem |+++++++++\n";
                do {
                    limparTela(); // Limpar a tela a cada iteração do submenu
                    cout << "+++++++++| Criptografar Mensagem |+++++++++\n";
                    cout << "1 - Inserir Mensagem\n";
                    cout << "2 - Carregar Arquivo\n";
                    cout << "3 - Voltar no Menu Principal\n";
                    cout << "ESCOLHA UMA OPCAO: ";
                    cin >> op;

                    switch (op) {
                        case 1:
                           limparTela();
                            // Lógica para inserir mensagem
                            mensagemCriptografada.open("mensagemCriptografada.txt");
                            cout << "Você escolheu Inserir Mensagem.\n";
                            cout<<"Informe a Mensagem: ";
                            cin>>message;
                            cout<<"Informe a Chave Publica {e n}: ";
                            cin>>e>>n;
                            coded = encoder(message, e, n);
                            cout<<"Mensagem Criptografada com sucesso!"<<"\n";

                            for (auto& p : coded)
                                mensagemCriptografada<<p<<" ";
                             
                            mensagemCriptografada.close();
                            
                            break;

                        case 2:
                            limparTela();
                            // Lógica para carregar arquivo
                            cout << "Você escolheu Carregar Arquivo.\n";
                            
                            arquivoMensagem.open("mensagem.txt");
                            mensagemCriptografada.open("mensagemCriptografada.txt");
                            //mensagemCriptografada.open("mensagemCriptografada.txt");
                            
                            if(arquivoMensagem.is_open()){
                                while (getline(arquivoMensagem, message)){
                                    arquivoMensagem >> message;
                                }
                                arquivoMensagem.close();
                            }else{
                                cout<<"Não foi possivel abrir"<<endl;
                            }
                            coded = encoder(message, e, n);

                            for (auto& p : coded)
                                mensagemCriptografada<<p<<" ";
                             
                            mensagemCriptografada.close();

                            break;

                        case 3:
                            limparTela();
                            // Sair do submenu
                            cout << "Você escolheu Voltar no Menu Principal. Saindo...\n";
                            break;

                        default:
                            cout << "Opção inválida. Tente novamente.\n";
                    }
                    // Pausa para o usuário ler a mensagem
                    cout << "Pressione Enter para continuar...";
                    cin.ignore();
                    cin.get();

                } while (op != 3);
                
                break;
            case 3:
                do {
                    limparTela(); // Limpar a tela a cada iteração do submenu
                    cout << "+++++++++| Descodificar Mensagem |+++++++++\n";
                    cout << "1 - Inserir Mensagem Codificada \n";
                    cout << "2 - Carregar Arquivo\n";
                    cout << "3 - Voltar no Menu Principal\n";
                    cout << "ESCOLHA UMA OPCAO: ";
                    cin >> op;

                    switch (op) {
                        case 1:
                           limparTela();
                            // Lógica para inserir mensagem
                            cout << "Você escolheu Inserir Mensagem.\n";
                            cout<<"Informe a Mensagem Codificada: ";
                            cin>>message;
                            cout<<"Informe a Chave Privada {d n}: ";
                            cin>>e>>n;
                            cout<<"Mensagem Decodificada "<<"\n";
                            cout << decoder(coded, d, n) << endl;
                            break;

                        case 2:
                            limparTela();
                            // Lógica para carregar arquivo
                           /* cout << "Você escolheu Carregar Arquivo.\n";




                           // mensagemDescodificada
                            cout << decoder(coded, d, n) << endl;


                            mensagemDescodificada.open("mensagemDescodificada.txt");
                            
                            arquivoMensagemCrip.open("msgCripto.txt");

                            if(arquivoMensagemCrip.is_open()){
                                while (getline(arquivoMensagemCrip, message)){
                                    arquivoMensagemCrip >> message;
                                }
                                arquivoMensagemCrip.close();
                            }else{
                                cout<<"Não foi possivel abrir"<<endl;
                            }
                            

                            for (auto& p : message)
                                decoder(p, d, n);

                            cout << "\n\nMensagem Descodificada com Sucesso\n";
                            
                            
                            mensagemDescodificada.close();
                            cout << decoder(coded, d, n) << endl;


                         */                               


                                        
                            break;

                        case 3:
                            limparTela();
                            // Sair do submenu
                            cout << "Você escolheu Voltar no Menu Principal. Saindo...\n";
                            break;

                        default:
                            cout << "Opção inválida. Tente novamente.\n";
                    }
                    // Pausa para o usuário ler a mensagem
                    cout << "Pressione Enter para continuar...";
                    cin.ignore();
                    cin.get();

                } while (op != 3);


                
                
                
                break;
            case 4:
                limparTela();
                cout << "Saindo do programa.\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (escolha != 4);
}
